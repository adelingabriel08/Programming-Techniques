#include<stdio.h>
#include<stdlib.h>
struct move
{
    int x,y;
}finish, start;
int n;
void printMaze(char a[n][n]) 
{ 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            printf(" %c ", a[i][j]);
        printf("\n"); 
    } 
    printf("\n\n");
} 
void printRoute(struct move route[n*n],int counter)
{
    for(int i = 0; i < counter; i++)
        printf("(%d,%d)->", route[i].x, route[i].y);
    printf("(%d,%d)\n", finish.x, finish.y);
}
void Maze(char maze[n][n], int x, int y, struct move route[n*n], int counter)
{
    if (x == finish.x && y == finish.y && maze[x][y]=='.') 
    { 
        maze[x][y] = 'x';
        printRoute(route,counter);
        printMaze(maze);
    }
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == '.') { 
        maze[x][y] = 'x';
        route[counter].x = x;
        route[counter++].y = y;
        Maze(maze, x, y+1, route, counter);
        Maze(maze, x+1, y, route, counter);
        Maze(maze, x-1, y, route, counter);
        Maze(maze, x, y-1, route, counter);
        maze[x][y] = '.';
    }
}
int main(int argc, char **argv)
{
    FILE *fin;
    fin=fopen(argv[1],"r");
    if(!fin)
    {
        printf("Input file argument missing or couldn't be find\n");
        exit(-1);
    }
    n=4;
    char maze[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin," %c", &maze[i][j]);
    finish.x = n-1;
    finish.y = n-1;
    struct move moves[n*n];
    printf("Enter start coords: ");
    scanf(" %d %d", &start.x, &start.y);
    if(maze[start.x][start.y] == '#')
        printf("It's a wall there !\n");
    else
        Maze(maze, start.x, start.y, moves, 0);
    return 0;
}