#include<stdio.h>
#include<limits.h>
int max(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int n;
    printf("n= ");scanf(" %d", &n);
    int prices[n], computations[n+1];
    printf("Enter the prices: \n");
    for(int i=0; i < n; i++)
        scanf(" %d", &prices[i]);

    computations[0] = 0;
  
   for (int i = 1; i <= n; i++)
   {
       int maximum = INT_MIN;
       for (int j = 0; j < i; j++)
            maximum = max(maximum, prices[j] + computations[i-j-1]);
       computations[i] = maximum;
   }
  
    printf("The maximum revenue obtainable by cutting up the rod and selling the pieces is %d\n", computations[n]);
}