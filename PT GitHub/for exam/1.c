// using function pointers compute the following expressions: 2x^2-1 and tan(x), with x from [0,1] with a step of 0.01

#include <stdio.h>
#include <math.h>

double function(double n)
{
    return 2 * n * n - 1;
}

int main()
{
    double (*my_tan)(double);
    double (*compute)(double) = &function;
    my_tan = &tan;
    printf("  x        tan(x)             2*x*x-1\n");
    printf("=====================================\n");
    for (int i = 0; i <= 100; i++)
    {
        double j = i / 100.0;
        printf("%.2f        %.2f               %.2f\n", j, my_tan(j), compute(j));
    }
    return 0;
}