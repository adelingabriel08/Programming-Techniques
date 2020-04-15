#include <stdio.h>
#include <stdlib.h>

char cell[10] = "0123456789";

int check()
{
    if(cell[1] == cell[2] && cell[2] == cell [3])
        return 1;
    else
        if(cell[4] == cell[5] && cell[5] == cell [6])
        return 1;
    else
        if(cell[7] == cell[8] && cell[8] == cell [9])
        return 1;
    else
        if(cell[1] == cell[4] && cell[4] == cell [7])
        return 1;
    else
        if(cell[2] == cell[5] && cell[5] == cell [8])
        return 1;
    else
        if(cell[3] == cell[6] && cell[6] == cell [9])
        return 1;
    else 
        if(cell[1] == cell[5] && cell[5] == cell [9])
        return 1;
    else
        if(cell[3] == cell[5] && cell[5] == cell [7])
        return 1;
    else 
        if(cell[1] !='1' && cell[2] !='2' && cell[3] !='3' && cell[4] !='4' && cell[5] !='5' && cell[6] !='6' && cell[7] !='7' && cell[8] !='8' && cell[9] !='9')
            return 0;
    return -1;    
}

void print()
{
    printf("\n");
    printf("     ||     ||     \n");
    printf("  %c  ||  %c  ||  %c  \n",cell[1],cell[2] ,cell[3]);
    printf("     ||     ||    \n");
    printf("===================\n");
    printf("     ||     ||    \n");
    printf("  %c  ||  %c  ||  %c  \n",cell[4],cell[5] ,cell[6]);
    printf("     ||     ||    \n");
    printf("===================\n");
    printf("     ||     ||    \n");
    printf("  %c  ||  %c  ||  %c  \n",cell[7],cell[8] ,cell[9]);
    printf("     ||     ||     \n");
}
int main()
{
    int n, game = -1, player = 2;
    char sym = 'X';
    while(game == -1)
    {
        if(player == 2)
            player = 1;
        else
            player = 2;
        if(player == 1)
            do{
            print();
            printf("Enter the cell number: \n");
            scanf("%d",&n);
            }while(n > 9 || n < 1);
        else
            do{
                n=rand()%10;
                printf("Computer move: %d\n",n);
                if(cell[n] == 'X' || cell[n] == '0')
                n=10;
            }while(n > 9 || n < 1);
        if(player == 2) 
            sym = '0';
        else
            sym = 'X';
        if(cell[n] != 'X' && cell[n] != '0')
            cell[n] = sym;
        
        else 
        {   if(player == 1)
                printf("Error!Change position!\n");
                player = 2;
        }
        game = check();
    }
    
    print();
    if( game == 1)
        if(player == 1)
                printf("You won!");
            else
                printf("Computer won !");
    else 
        printf("Draw\n");
    
    return 0;
}