#include <stdio.h>
#include <stdlib.h>

void compare(char *file1, char *file2)
{
    FILE *f1, *f2;

    f1 = fopen(file1, "r");
    if (f1 == NULL)
    {
        printf("file 1 not found or missing arg\n");
        exit(-1);
    }
    f2 = fopen(file2, "r");
    if (f2 == NULL)
    {
        printf("file 2 not found or missing arg\n");
        exit(-1);
    }
    FILE *f;
    f=fopen("hamming.txt", "w");
    int counter = 0, c1, c2;
    while ((c1 = fgetc(f1)) != EOF || (c2 = fgetc(f2)) != EOF)
    {
        if (c1 != c2)
            counter++;
    }
    fprintf(f, "Hamming Distance: %d\n", counter);
    fclose(f1);
    fclose(f2);
}

int main(int argc, char **argv)
{
    compare(argv[1], argv[2]);
    return 0;
}
