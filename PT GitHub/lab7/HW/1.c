#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void UpperToLower(char *file)
{
  FILE *f;

  f = fopen(file, "r");

  if (f == NULL)
  {
    printf("File not found or missing arguments\n");
    exit(-1);
  }

  int c;

  while ((c = fgetc(f)) != EOF)
  {
    if (c >= 'a' && c <= 'z')
      fprintf(stdout, "%c", c - 32);
    else
      fprintf(stdout, "%c", c);
  }

  fclose(f);
}

int main(int argc, char **argv)
{
  UpperToLower(argv[1]);
  return 0;
}
