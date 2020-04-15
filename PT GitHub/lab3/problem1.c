#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n)
{
	int aux;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i]>arr[j])
			{
				aux=arr[i];
				arr[i]=arr[j];
				arr[j]=aux;
			}

}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int n;
	int arr[50];
	n=50;
	for(int i=0;i<n;i++)
		arr[i]=rand()%1000;
	print(arr,n);
	sort(arr,n);
	print(arr,n);
	return 0;
}