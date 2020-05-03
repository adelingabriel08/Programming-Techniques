#include<stdio.h>
int amount;

void print(int k, int arr[])
{
    for(int i = 0; i < k; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int check(int k, int arr[])
{
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += arr[i];
    return sum;
}
void bkt(int k, const int coins[], const int n, int arr[])
{
    for(int i = 0; i < n; i++)
    {
        arr[k] = coins[i];
            if(check(k, arr)==amount)
                print(k, arr);
            else if(check(k, arr) < amount)
                    bkt(k+1, coins, n, arr);
    }
}
int main()
{
    printf("Enter the amount: ");
    scanf(" %d", &amount);
    int arr[amount+1];
    int n;
    printf("Enter the number of coins: ");
    scanf(" %d", &n);
    int coins[n];
    printf("Enter the coins' values: ");
    for(int i = 0; i < n; i++)
        scanf(" %d", &coins[i]);
    bkt(0, coins, n, arr);
}