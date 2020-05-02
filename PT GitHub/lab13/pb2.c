#include<stdio.h>
#define N 5
long int f[N+1];

unsigned long int fib(unsigned long int n) 
{
    unsigned int i;
    if(n > 2){
        if(f[n]==0)
            for(i = 2; i<=n; i++)
            {
                if(f[i]<=0)
                    f[i] = f[i-1] + f[i-2];
            }
        else printf("Reused val:\n");
    }
    return (unsigned long int) f[n];
}

int main()
{
    f[0] = 0;
    f[1] = 1;
    printf(" fib(10) = %lu\n", fib(10));
    printf(" fib(3) = %lu\n", fib(3));
    printf(" fib(5) = %lu\n", fib(5));
    printf(" fib(11) = %lu\n", fib(11));
    return 0;
}