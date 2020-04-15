#include <stdio.h>
#include <stdlib.h>

int search(int v[] , int x , int n )
{
    int counter = 0;
    for(int i = 0; i < n ; i++)
    {
        counter++;
        if(v[i] == x){
            printf("x is at position %d in the non sorted array (linear search)\n",i);
            break;
        }
    }
    return counter;
}


int binary_search(int v[] , int x, int n)
{
    int counter=0;
    int left = 0 ;
    int right = n - 1;
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        counter++;
        if(v[mid] < x)
            left = mid + 1;
        else 
            if(v[mid] == x)
            {
                printf("x is at position %d in the sorted array.\n",mid +1);
                break;
            }
            else 
                right = mid - 1;
    }
    if (left > right)
        puts("Not found!\n");
    
    return counter;
}


void sort(int v[], int n)
{
    int aux;
    for(int i = 0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    printf("The sorted array: ");
    for(int i=0; i<n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

int main()
{
    int N=2 , n , x ;
    
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    
    for(int i=1; i<n; i++)
        N=N*2;
    
    int array[N];
    printf("The array: ");
    for(int i = 0; i < N ; i++)
    {
        array[i] = rand()%200;
        printf("%d ",array[i]);     
    }
    printf("\n");
    printf("Enter the number you want to search: ");
    scanf("%d",&x);
    int binary_search_counter , search_counter;
    search_counter = search(array , x , N);
    sort(array,N);
    binary_search_counter = binary_search(array , x , N);
    printf("Counter for linear search : %d\n",search_counter);
    printf("Counter for binary search: %d\n",binary_search_counter);
    return 0;
}