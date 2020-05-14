#include<stdio.h>

int main()
{
    char freq[300]={0};
    int ch;
    while((ch=fgetc(stdin))!=EOF)
        freq[ch]++;
    for(int i = 0; i < 300; i++)
        if(freq[i] > 0)
            fprintf(stdout, "Character %c found %d times.\n", i, freq[i]);
    return 0;
}   