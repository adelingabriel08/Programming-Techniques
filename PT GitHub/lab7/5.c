#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct time
{
    unsigned int h, m;
    char s[7];
}time;
struct content
{
    unsigned int id;
    time start, end;
    char string[256], tag;
    void (*changeTime)(struct content*, unsigned int);
}content;
void convertCommaToDot(char *str)
{
    for(int i = 0; i < strlen(str); i++)
        if(str[i]==',')
            {
                str[i] = '.';
                break;
            }
}
void convertDotToComma(char *str)
{
    for(int i = 0; i < strlen(str); i++)
        if(str[i]=='.')
            {
                str[i] = ',';
                break;
            }
}
void function(struct content *content, unsigned int arg)
{
    convertCommaToDot(content->start.s);
    convertCommaToDot(content->end.s);

    float start_s = atof(content->start.s);
    float end_s = atof(content->end.s);

    start_s += arg;
    end_s += arg;


    if(start_s >= 60)
    {
        content->start.m += start_s / 60;
        start_s -= 60 * ((int)start_s / 60);

        if(content->start.m >= 60)
        {
            content->start.h += content->start.m / 60;
            content->start.m = content->start.m % 60;
        }
    }


    if(end_s >= 60)
    {
        content->end.m += end_s / 60;
        end_s -= 60 * ((int)end_s / 60);

        if(content->end.m >= 60)
        {
            content->end.h += content->end.m / 60;
            content->end.m = content->end.m % 60;
        }
    }

    gcvt(start_s, 5, content->start.s);
    gcvt(end_s, 5, content->end.s);

    convertDotToComma(content->start.s);
    convertDotToComma(content->end.s);
}
void checkFileContent(FILE *f)
{
    while((content.tag = fgetc(f))!=EOF)
            printf("%c", content.tag);
}
int main(int argc, char **argv)
{
    int arg = atoi(argv[1]);
    if(arg <= 0)
    {
        printf("the input arg is 0 or is not a number!\n");
        return 0;
    }
    FILE *f;
    char file[256];
    printf("Enter the file name: ");
    scanf(" %s", file);
    f = fopen(file,"r");
    if(f==NULL)
    {
        printf("Cannot find the file!\n");
        exit(-1);
    }
    content.changeTime = &function;
    while(fscanf(f,"%u\n%u:%u:%s --> %u:%u:%s\n<%c>%[^<]s", &content.id, &content.start.h, &content.start.m, content.start.s,
    &content.end.h, &content.end.m, content.end.s, &content.tag, content.string)==9 && fscanf(f,"</%c>\n\n",&content.tag))
    {
        content.changeTime(&content, arg);
        printf("%u\n%u:%u:%s --> %u:%u:%s\n%s\n\n", content.id, content.start.h, content.start.m, content.start.s,
    content.end.h, content.end.m, content.end.s, content.string);
    }
    //checkFileContent(f);
    
    return 0;
}