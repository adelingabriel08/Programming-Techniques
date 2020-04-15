#include<stdio.h>

unsigned isprime(unsigned int n)
{
	for(int i=2;i<n/2;i++)
		if(n%i==0) 
			return 0;
	return 1;
}

int main()
{
	unsigned int n;
	printf("Enter the length of the array: ");
	scanf("%d",&n);
	unsigned int primes[n];
	primes[0]=2;
	unsigned int prime_number=3;
	int i=1;
	while(i<n)
		if(isprime(prime_number))
			{
			primes[i++]=prime_number;
			prime_number+=2;
			}
			else 
				prime_number+=2;

	// for(int i=0;i<n;i++)
	// 	printf("%d ",primes[i]);

	unsigned int x;
	printf("Enter the number you want to verify:");
	scanf("%d",&x);
	if(!isprime(x)){
		printf("the number you entered is not in the array !\n");
		return 0;
	}
	unsigned int start=0,end=primes[n-1],middle;
	while(start<=end)
	{
		middle=(start+end)/2;
		if(middle==x)
		{
			printf("the number you entered is in the array!\n");
			return 0;
		}
		else 
			if(x<middle)
				end=middle;
			else 
				start=middle;
	}
	printf("the number you entered is not in the array !\n");
	return 0;
}