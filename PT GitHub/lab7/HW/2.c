#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double cotan(double x)
{
  return 1 / tan(x);
}

int main(int argc, char **argv)
{
  FILE *f;
  float rad;
  f = fopen(argv[1], "w");
  if (f == NULL)
  {
    printf("file not found or missing argument !\n");
    exit(-1);
  }

  fprintf(f, "\n\nDegrees      Radians        sin(x)          cos(x)          tan(x)          cotan(x)\n");
  fprintf(f, "==========================================================================================\n");
  for (float i = 0; i <= 180; i += 0.1)
  {
    rad = i * M_PI / 180;
    fprintf(f, "%.1f          %.3f          %.3f           %.3f           %.3f            %.3f\n", i, rad, sin(i), cos(i), tan(i), cotan(i));
  }

  fclose(f);

  return 0;
}
