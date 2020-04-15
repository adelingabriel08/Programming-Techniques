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
unsigned int clever_computer()
{    
    for(int i=1 ; i<=7;i=i+3)
    {
        if(cell[i]==cell[i+1] && !(cell[i+2] == 'X' || cell[i+2] == '0'))
            return i+2;
        if(cell[i]==cell[i+2] && !(cell[i+1] == 'X' || cell[i+1] == '0'))
            return i+1;
        if(cell[i+1]==cell[i+2] && !(cell[i] == 'X' || cell[i] == '0'))
            return i;
    }
    for(int i=1;i<=3;i++)
    {
        if(cell[i]==cell[i+3] && !(cell[i+6] == 'X' || cell[i+6] == '0'))
            return i+6;
        if(cell[i]==cell[i+6] && !(cell[i+3] == 'X' || cell[i+3] == '0'))
            return i+3;
        if(cell[i+3]==cell[i+6] && !(cell[i] == 'X' || cell[i] == '0'))
            return i;
    }
    if(cell[1]==cell[5] && !(cell[9] == 'X' || cell[9] == '0'))
        return 9;
    if(cell[1]==cell[9] && !(cell[5] == 'X' || cell[5] == '0'))
        return 5;
    if(cell[5]==cell[9] && !(cell[1] == 'X' || cell[1] == '0'))
        return 1;
    if(cell[3]==cell[5] && !(cell[7] == 'X' || cell[7] == '0'))
        return 7;
    if(cell[3]==cell[7] && !(cell[5] == 'X' || cell[5] == '0'))
        return 5;
    if(cell[5]==cell[7] && !(cell[3] == 'X' || cell[3] == '0'))
        return 3;
    return 0;
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
                if(clever_computer()==0)
                    n=rand()%10;
                else
                    n=clever_computer();
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