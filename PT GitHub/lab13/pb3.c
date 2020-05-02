#include<stdio.h>

void coin(int amount, int coins[],int nr)
{
	int combine[amount+1];
	combine[0]=1;
	for(int i=1; i<=amount; i++)
		combine[i]=0;
	for(int i=0; i<nr; i++)
		for(int j=1; j<amount+1; j++)
			if(j>=i)
				combine[j] += combine[ j-coins[i] ];
	printf("Number of combinations: %d \n",combine[amount]);
}

int main()
{

	int amount,nr;
	printf("How much money?\n");
	scanf("%d",&amount);
	printf("How many coins?\n");
	scanf("%d",&nr);
	int coins[nr];
	printf("Enter the coins' values:\n");
	for(int i=0;i<nr;i++)
		scanf("%d",&coins[i]);
	coin(amount,coins,nr);

}
