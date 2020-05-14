#include<stdio.h>

int main()
{
    int ch;
    while((ch=fgetc(stdin))!=EOF)
    {
        if(ch == '\n')
            fprintf(stdout, "\r");
        fprintf(stdout, "%c", ch);
    }
    return 0;
}