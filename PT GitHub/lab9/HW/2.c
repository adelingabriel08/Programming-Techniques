#include<stdio.h>
#include<stdlib.h>
void peak_divide(int arr[], int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            printf("%d ", arr[mid]);
            peak_divide(arr,start,mid-1);
            peak_divide(arr,mid+1,end);
            break;
        }
        else if (arr[mid] > arr[mid + 1])
            end = mid;
        else
            start = mid + 1;
    }
}
int main()
{
    int n=10;
    int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arr[i][j]=rand()%100;
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ",arr[i][j]);
            printf("\n");
        }
        printf("\n\n\n\nPeak values: ");
    for(int i=0 ; i<n; i++){
        if(arr[i][0]>arr[i][1])
            printf("%d ",arr[i][0]);
        if(arr[i][n-1]>arr[i][n-2])
            printf("%d ",arr[i][n-1]);
        peak_divide(arr[i], 0, n);
    }
    printf("\n");
    return 0;
}