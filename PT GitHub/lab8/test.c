#include<stdio.h>
#include<stdlib.h>

int main()
{
    // FILE *f = fopen("test.bin", "wb");
    // int a[8] = {1,2,3,4,5,6};
    // fwrite(a,sizeof(a), 6, f);
    // fclose(f);
    FILE *g = fopen("test.bin", "r+");
    int b=1;
    int pos = ftell(g);
    printf("pos: %d\n", pos);
    fseek(g, pos, SEEK_END);
    fwrite(&b, sizeof(b), 1, g);
    fclose(g);
    FILE *f = fopen("test.bin", "r+b");
    fseek(g, pos, SEEK_SET);
    int a[8];
    fread(a, sizeof(a), 1, f);
    pos = ftell(f);
    for(int i=0; i<8; i++){
        printf("%d \n", a[i]);
}

    return 0;
}