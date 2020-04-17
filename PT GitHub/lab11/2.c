#include<stdlib.h>
#include<stdio.h>

int board[8][8];
int X[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int Y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
int move(int knightX, int knightY, int counter) 
{ 
   int x, y; 
   if (counter == 8*8 + 1)
       return 1;
   for (int i = 0; i < 8; i++)
   { 
       x = knightX + X[i];
       y = knightY + Y[i];
       if (x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == 0)
       { 
            board[x][y] = counter;
            if (move(x, y, counter+1) == 1)
                return 1;
            else
                board[x][y] = 0;
       }
   }
   return 0;
}
int main()
{
    int startX, startY;
    printf("Enter the start point coordinates (between 0 and 7): ");
    scanf(" %d %d",&startX,&startY);
    board[startX][startY]  = 1;
    if (move(startX, startY, 2) == 0)
        printf("Cannot find a solution"); 
    else
        for(int i=0; i<8 ; i++)
            {
            for(int j=0; j<8; j++)
                printf("%2d ", board[i][j]);
            printf("\n");
            }
    return 0; 
} 
