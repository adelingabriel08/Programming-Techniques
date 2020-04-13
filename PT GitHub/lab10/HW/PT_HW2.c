#include <stdio.h>


void setCoins(int n)
{
    int coins[4]={0, 0, 0, 0};//coins[0] == "coins of 20", coins[1]=="coins of 10",coins[2]== "coins of 5", coins[3]== " coins of 1"
    coins[0] = n/20;
    n = n % 20;
    coins[1] = n/10;
    n = n % 10;
    coins[2] = n/5;
    coins[3] = n%5;
    
    printf("Coins of 20 : %d\n",coins[0]);
    printf("Coins of 10 : %d\n",coins[1]);
    printf("Coins of 5 : %d\n",coins[2]);
    printf("Coins of 1 : %d\n",coins[3]);
}

int main(void)
{
    int n;
    printf("How much coins?  ");
    scanf("%d", &n);
    setCoins(n);
    return 0;
}
