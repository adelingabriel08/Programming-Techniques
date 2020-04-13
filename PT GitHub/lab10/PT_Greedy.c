#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
int minDistance(int arr[], int visited[])
{
    int min = INT_MAX, index;
    for (int i = 0; i < 5; i++)
        if (visited[i] == 0 && arr[i] <= min)
        {
            min = arr[i];
            index = i;
        }
    return index;
}
void path(int arr[5][5], int src)
{
    int distance = 0;
    int visited[5] = { 0 };
    visited[1] = 1;
    int i = 1,j=1;
    printf("Oradea ");
    while (j != src)
    {
        j = minDistance(arr[i], visited);
        distance += arr[i][j];
        i = j;
        visited[i] = 1;
        if (i == 0)
            printf("Timisoara ");
        else if (i == 2)
            printf("Cluj ");
        else if (i == 3)
            printf("Iasi ");
        else printf("Bucuresti ");
    }
    printf("\n");
    printf("Distance: %d\n", distance);
}
int main(int argc, char** argv)
{
    FILE* fin;
    fin = fopen("C:/Users/Adelin/source/repos/input.txt", "r");
    if (fin == NULL)
    {
        printf("file not found\n");
        exit(-1);
    }
    int arr[5][5];
    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
            fscanf(fin, "%d", &arr[i][j]);
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 5;j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    for (int i = 0;i < 5;i++)
        path(arr, i);
    return 0;
}
