#include<stdio.h>
#include<stdlib.h>
struct move
{
    int x,y,z;
}finish, start;
int n;
void printMaze(char a[6][n][n]) 
{ 
    for(int k = 0; k < 6; k++)
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
                printf(" %c ", a[k][i][j]);
            printf("\n"); 
        } 
    printf("\n\n");
} 
void printRoute(struct move route[],int counter)
{
    for(int i = 0; i < counter; i++)
        printf("(%d,%d,%d)->", route[i].x, route[i].y,route[i].z);
    printf("(%d,%d,%d)\n", finish.x, finish.y, finish.z);
}
void Maze(char maze[6][n][n], int z, int x, int y, struct move route[], int counter)
{
    if (x == finish.x && y == finish.y && z == finish.z && maze[z][x][y] == '.') 
    { 
        maze[z][x][y] = 'x';
        printRoute(route,counter);
        printMaze(maze);
    }
    if (x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < 6 && maze[z][x][y] == '.') { 
        maze[z][x][y] = 'x';
        route[counter].x = x;
        route[counter].y = y;
        route[counter++].z = z;
        Maze(maze, z, x+1, y, route, counter);
        Maze(maze, z+1, x, y, route, counter);
        Maze(maze, z-1, x, y, route, counter);
        Maze(maze, z, x-1, y, route, counter);
        Maze(maze, z+1, x, y, route, counter);
        Maze(maze, z-1, x, y, route, counter);
        maze[z][x][y] = '.';
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
    char maze[6][n][n];
    for(int k=0; k < 6; k++)
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin," %c", &maze[k][i][j]);
    finish.x = n-1;
    finish.y = n-1;
    finish.z = 5;
    struct move moves[n*n*6];
    printf("Enter start coords: ");
    scanf(" %d %d %d", &start.x, &start.y, &start.z);
    if(maze[start.z][start.x][start.y] == '#')
        printf("It's a wall there !\n");
    else
        Maze(maze, start.z, start.x, start.y, moves, 0);
    return 0;
}