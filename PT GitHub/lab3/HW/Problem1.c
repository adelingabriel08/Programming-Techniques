#include <stdio.h>
#include<stdlib.h>

unsigned int merge_counter;
void insertion_sort (int v[] , int length) 
{   
    int counter = 0;
    int i , j , aux;
    for(i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && v[j-1] > v[j])
        {
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
            counter++;
        }
    }
    printf("Insertion swap counter: %d \n",counter);
}
void merge(int v[] , int left , int mid , int right )
{
    int p = left;
    int q = mid + 1;
    int k = 0;
    int array[right - left + 1];
    
    for(int i = left; i<=right; i++)
    {

        if (p > mid)
        {
            array[k] = v[q];
            q++;
            k++;
        }
        else if (q > right)
             {
                array[k] = v[p];
                k++;
                p++;
             }
             else if(v[p] < v[q])
                  {
                    array[k] = v[p];
                    k++;
                    p++;
                  }
                 else
                 {
                    array[k] = v[q];
                    q++;
                    k++;
                 }
    }
    for ( p = 0; p < k ; p++) 
    {
        
        v[left] = array[p];
        left++;
    }

}

void merge_sort(int v[] , int left , int right )
{     
    if(left < right)
    {
        int mid = (left + right) / 2 ;
        
        merge_sort(v, left, mid);
        merge_sort(v, mid+1, right);
        merge(v, left , mid , right);
    }
    merge_counter++;
}

int main()
{
    int n;
    printf("Enter the array length: ");
    scanf(" %d",&n);
    int array1[n], array2[n];
    printf("The array before sort : ");
    for(int i = 0 ; i<n ; i++)
    {
        array1[i]=rand()%200;
        array2[i]=array1[i];
        printf("%d ", array1[i]);
    }
    printf("\n");
    insertion_sort(array1,n);
    merge_sort(array2,0,n-1);
    printf("Merge sort swap counter: %d\n",merge_counter);
    printf("Array after sort: ");
    for(int i = 0; i<n; i++)
        printf("%d ", array1[i]);
    printf("\n");
    return 0;
}
