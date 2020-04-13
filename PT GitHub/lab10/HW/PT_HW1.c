#include <stdio.h>
#include <stdlib.h>


int min = 999999, minGreedy = 999999;

void minDist(int distances[5][5], int distance, int k, int i,  int condition[5])
{
    if(k == 5)
    {
       if(min > distance)
       {
           min = distance;
       }
    }
    for(int v = 0; v < 5; v++)
    {
        if(distances[i][v] != 0 && condition[v] == 0)
        {
            condition[v] = 1;
            minDist(distances, distance + distances[i][v], k+1, v, condition);
            condition[v] = 0;
        }
    }
}

void greedyDist(int distances[5][5], int distance, int k, int i,  int condition[5])
{
    
   int arr[5];
    
    if(k == 5)
    {
       if(minGreedy > distance)
       {
           minGreedy = distance;
       }
    }
    arr[i] = distance;
    for(int v = 0; v < 5; v++)
    {
        if(distances[i][v] != 0 && condition[v] == 0 && arr[i] != distances[i][v])
        {
            condition[v] = 1;
            greedyDist(distances, distance + distances[i][v], k+1, v, condition);
            condition[v] = 0;
        }
    }
 
}

int main(void)
{
   int arr[5][5] = { {0, 174, 315, 634, 544},
                     {174, 0, 152, 0, 595},
                     {315, 152, 0, 393, 0},
                     {634, 544, 393, 0, 0},
                     {544, 595, 0, 388, 0} };                                                      
    int condition[5] = {0, 0, 0, 0, 0};
  minDist(arr, 0, 1, 0, condition);
  greedyDist(arr, 0, 1, 0, condition);
  printf("Distance from Timisoara: %d\n", min);
  printf("Distance from Timisoara(with Greedy): %d\n", minGreedy);
  min = 999999;
  minGreedy = 999999;
  
  minDist(arr, 0, 1, 1, condition);
  greedyDist(arr, 0, 1, 1, condition);
  printf("Distance from Oradea: %d\n", min);
  printf("Distance from Oradea(with Greedy): %d\n", minGreedy);
  min = 999999;
  minGreedy = 999999;
  
  minDist(arr, 0, 1, 2, condition);
  greedyDist(arr, 0, 1, 2, condition);
  printf("Distance from Cluj: %d\n", min);
  printf("Distance from Cluj(with Greedy): %d\n", minGreedy);
  min = 999999;
  minGreedy = 999999;
  
  minDist(arr, 0, 1, 3, condition);
  greedyDist(arr, 0, 1, 3, condition);
  printf("Distance from Iasi: %d\n", min);
  printf("Distance from Iasi(with Greedy): %d\n", minGreedy);
  min = 999999;
  minGreedy = 999999;
  
  minDist(arr, 0, 1, 4, condition);
  greedyDist(arr, 0, 1, 4, condition);
  printf("Distance from Bucuresti: %d\n", min);
  printf("Distance from Bucuresti(with Greedy): %d\n", minGreedy);
  return 0;
}
