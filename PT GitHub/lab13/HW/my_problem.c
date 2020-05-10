#include<stdio.h>
//Find the contiguous subarray, from a given array, which has the largest sum and print the sum
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
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i=0; i < n; i++)
        scanf(" %d", &arr[i]);
    int maxSum = 0;
	int max_end = 0;
	for (int i = 0; i < n; i++)
	{

		max_end+=arr[i];
		max_end = max(max_end, 0);
		maxSum = max(maxSum, max_end);
	}

	printf("The maximum sum of contiguous subarray with the largest sum is %d\n", maxSum);
	return 0;
}