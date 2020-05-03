#include <stdio.h>
#include <stdlib.h>
#define N 8
int board[N][N];
void printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%d  ", board[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void initializeBoard()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = -1;
}

int verify(int x, int y)
{
	int i;

	if (x > 8 || y > 8 || x < 0 || y < 0)
		return 0;


	for (i = 0; i < N; i++)
		if (board[x][i] != -1 || board[i][y] != -1)
			return 0;


	int left=y, right=y;


	for (i = x; i >= 0; i--)
	{
		if(left >= 0 && right < N){
			if (board[i][left] != -1 || board[i][right] != -1)
				return 0;
		}
		else break;
		left--;
		right++;
	}


	left = right = y;


	for (i = x; i < N; i++)
	{
		if(left >= 0 && right < N){
			if (board[i][left] != -1 || board[i][right] != -1)
				return 0;
		}
		else break;
		left--;
		right++;
	}


	return 1;
}

void queen(int x, int y, int counter)
{
	
	if (verify(x, y) && board[x][y] == -1)
	{
		board[x][y] = counter;

		if (board[x][y] == 8)
		{
			printBoard();
			return;
		}


		while (x < 8)
		{

			y++;
			if (y == 8)
			{
				y = 0;
				x++;
			}

			queen(x, y, counter+1);

			board[x][y] = -1;
		}


	}
}

int main()
{
	for(int i = 0; i < N; i++)
	{
		initializeBoard();
		queen(0, i, 1);
	}
	return 0;
}
