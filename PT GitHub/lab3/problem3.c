#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int start,end,middle;
	char verify='n';
	end=0;
	while(verify!='y')
	{
		start=end;
		end+=100;
		printf("Did you pick a number between %d and %d ? (y/n) ",start,end); 
		scanf(" %c",&verify);
	}
	 while(start<end)
	{
	 	middle=(start+end)/2;
		printf("Is your number greater or equal than %d ?",middle); scanf(" %c",&verify);
	 	if(verify == 'y')
	 		{
	 			start=middle;
	 			if(end-start==1)
	 		{
	 			printf("Your number is %d !\n", start);
	 			exit(1);
	 		}
	 	}
	 	else 
	 		{
	 			end=middle;
	 			if(start-end==1)
	 		{
	 			printf("Your number is %d !\n", end);
	 			exit(1);
	 		}
	 	}
	 	
	 }
	return 0;
}