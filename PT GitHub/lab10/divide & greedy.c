#include <stdio.h>

void peak_greedy(int arr[], int n)
{
    if (arr[1] < arr[0])
        printf("%d ", arr[0]);
    else if (arr[n - 1] > arr[n - 2])
        printf("%d ", arr[n - 1]);
    for (int i = 1; i < n - 1; i++)
        if (arr[i - 1]<arr[i] && arr[i]>arr[i + 1])
            printf("%d ", arr[i]);
}
void peak_divide(int arr[], int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            printf("%d ", arr[mid]);
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
    int n, arr[100];
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nPeak_greedy elements: ");
    peak_greedy(arr, n);
    printf("\nDivide and conquer peak element: ");
    peak_divide(arr, 0, n - 1);
    return 0;
}