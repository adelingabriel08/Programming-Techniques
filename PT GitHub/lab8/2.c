#include <x86intrin.h>
#include <stdio.h>
#include <string.h>
#define LCS _lrotl // left circular shift
#define RCS _lrotr // right circular shift
#define u64 unsigned long long
#define R(x, y, k) (x = RCS(x, 8), x += y, x ^= k, y = LCS(y, 3), y ^= x)
#define INV_R(x, y, k) (y ^= x, y = RCS(y, 3), x ^= k, x -= y, x = LCS(x, 8))
void Speck128ExpandKeyAndEncrypt(u64 pt[], u64 ct[], u64 K[])
{
    u64 i, B = K[1], A = K[0];
    ct[0] = pt[0];
    ct[1] = pt[1];
    for (i = 0; i < 32; i++)
    {
        R(ct[1], ct[0], A);
        R(B, A, i);
    }
}
void Speck128Encrypt(u64 pt[], u64 ct[], u64 k[])
{
    u64 i;
    ct[0] = pt[0];
    ct[1] = pt[1];
    for (i = 0; i < 32; i++)
        R(ct[1], ct[0], k[i]);
}
void Speck128Decrypt(u64 pt[], u64 ct[], u64 K[])
{
    long long i;
    for (i = 31; i >= 0; i--)
    {
        INV_R(ct[1], ct[0], K[i]);
    }
}

static void speck_keyexpand(u64 K[]) // OK
{
    u64 tmp[32], *p;
    memcpy(tmp, K, sizeof tmp);
    // K[0] stays the same
    u64 i;
    for (i = 0; i < (31);)
    {
        p = tmp + (1 + (i % (2 - 1)));
        R(*p, tmp[0], i);
        ++i;
        K[i] = tmp[0];
    }
}
int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        perror("File not found or argument missing");
        exit(-1);
    }
    FILE *g_temp = fopen("temp.bin", "wb");
    u64 k[32];
    printf("Enter the password:\n");
    scanf("%llu", k);
    k[1] = k[0] / 1000;
    k[0] /= 1000;
    speck_keyexpand(k);

    int op;
    printf("Enter the option:\n0-encrypt\n1-decrypt\n");

    u64 pt[2];
    u64 ct[] = {0x0, 0x0};

    scanf(" %d", &op);
    switch (op)
    {
    case 0:
    {
        printf("Encrypting...\n");
        while (fread(pt, sizeof(pt), 2, f))
        {
            Speck128Encrypt(pt, ct, k);
            fwrite(ct, sizeof(ct), 2, g_temp);
        }
        break;
    }
    case 1:
    {
        printf("Decrypting....\n");
        while (fread(pt, sizeof(pt), 2, f))
        {
            Speck128Decrypt(pt, ct, k);
            fwrite(ct, sizeof(ct), 2, g_temp);
        }
        break;
    }
    }
    remove(argv[1]);
    rename("temp.bin", argv[1]);
    return 0;
}