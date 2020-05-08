#include <stdio.h>
#include <limits.h>
#include<stdarg.h>

void min_max(unsigned int n, ...)
{
    va_list arglist;    
    int min = INT_MAX;
    int max = INT_MIN;
    int x;

    va_start(arglist, n);
    
    for(int i = 0; i < n; i++)
    {
        x = va_arg(arglist, int);

        //printf("%d\n", x);
        if(x > max)
            max = x;
        if(x < min)
            min = x;
    }
    va_end(arglist);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

}

int main()
{
    min_max(5, 3, 7, 1, 2, 8);
    return 0;
}