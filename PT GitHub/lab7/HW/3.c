#include <stdio.h>
#include <stdlib.h>

void BlackGradient(FILE *file)
{

  fprintf(file, "P3\n%d %d\n255\n", 1000, 1000);

  for (int i = 0; i < 1000; i++)
  {
    for (int j = 0; j < 1000; j++)
      fprintf(file, "%d %d %d ", 255 * j / 1000, 255 * j / 1000, 255 * j / 1000);
    fprintf(file, "\n");
  }
}

void  VioletGradient(FILE *file)
{
  fprintf(file, "P3\n%d %d\n255\n", 1000, 1000);

  for (int i = 0; i < 1000; i++)
  {
    for (int j = 0; j < 1000; j++)
      fprintf(file, "%d %d %d ", 255 * j / 1000, 0, 255 * j / 1000);
    fprintf(file, "\n");
  }
}

int main(void)

{

  FILE *file;
  file = fopen("black.ppm", "w");

  BlackGradient(file);

  fclose(file);

  file = fopen("violet.ppm", "w");

  VioletGradient(file);

  fclose(file);

  return 0;
}
