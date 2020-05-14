#include<stdio.h>

int main(int argc, char **argv)
{
    FILE *f;
    for(int i = 1; i < argc; i++)
   {
       f = fopen(argv[i], "r");
       if(f==NULL)
       {
           printf("File %s not found!\n", argv[i]);
       }
       else{
        int ch;
        while((ch=fgetc(f))!=EOF)
        {
            if(ch == '\n')
                fprintf(stdout, "\r");
            fprintf(stdout, "%c", ch);
        }
       }
    }
    return 0;
}