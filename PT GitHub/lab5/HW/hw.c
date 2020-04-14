#include <stdio.h>
#include <stdlib.h>

char cell[6][11] = { "0123456789","0123456789","0123456789","0123456789","0123456789","0123456789" };

int check(int tab)
{
    if (cell[tab][1] == cell[tab][2] && cell[tab][2] == cell[tab][3])
        return 1;
    else
        if (cell[tab][4] == cell[tab][5] && cell[tab][5] == cell[tab][6])
            return 1;
        else
            if (cell[tab][7] == cell[tab][8] && cell[tab][8] == cell[tab][9])
                return 1;
            else
                if (cell[tab][1] == cell[tab][4] && cell[tab][4] == cell[tab][7])
                    return 1;
                else
                    if (cell[tab][2] == cell[tab][5] && cell[tab][5] == cell[tab][8])
                        return 1;
                    else
                        if (cell[tab][3] == cell[tab][6] && cell[tab][6] == cell[tab][9])
                            return 1;
                        else
                            if (cell[tab][1] == cell[tab][5] && cell[tab][5] == cell[tab][9])
                                return 1;
                            else
                                if (cell[tab][3] == cell[tab][5] && cell[tab][5] == cell[tab][7])
                                    return 1;
                                else
                                    for (int i = 0;i < 6;i++)
                                        for (int j = 1;j < 6;j++)
                                            if (cell[i][j] != 'X' && cell[i][j] != '0')
                                                return -1;
    return 0;
}

void print()
{
    for (int tab = 0;tab <=3;tab=tab+3) {
        printf("Table no: %d             Table no: %d             Table no: %d          \n",tab+1,tab+2,tab+3);
        printf("      ||      ||               ||      ||              ||      ||         \n");
        printf("   %c  ||   %c  ||   %c        %c  ||   %c  ||   %c       %c  ||   %c  ||   %c  \n", cell[tab][1], cell[tab][2], cell[tab][3], cell[tab + 1][1], cell[tab + 1][2], cell[tab + 1][3], cell[tab + 2][1], cell[tab + 2][2], cell[tab + 2][3]);
        printf("      ||      ||               ||      ||              ||      ||        \n");
        printf("======================   ======================   ======================   \n");
        printf("      ||      ||               ||      ||              ||      ||        \n");
        printf("   %c  ||   %c  ||   %c        %c  ||   %c  ||   %c       %c  ||   %c  ||   %c \n", cell[tab][4], cell[tab][5], cell[tab][6], cell[tab + 1][4], cell[tab + 1][5], cell[tab + 1][6], cell[tab + 2][4], cell[tab + 2][5], cell[tab + 2][6]);
        printf("      ||      ||               ||      ||              ||      ||        \n");
        printf("======================   ======================   ======================   \n");
        printf("      ||      ||               ||      ||              ||      ||        \n");
        printf("   %c  ||   %c  ||   %c        %c  ||   %c  ||   %c       %c  ||   %c  ||   %c \n", cell[tab][7], cell[tab][8], cell[tab][9], cell[tab + 1][7], cell[tab + 1][8], cell[tab + 1][9], cell[tab + 2][7], cell[tab + 2][8], cell[tab + 2][9]);
        printf("      ||      ||               ||      ||              ||      ||        \n");
        printf("\n\n");
    }

}
unsigned int clever_computer(int tab)
{
    for (int i = 1; i <= 7;i = i + 3)
    {
        if (cell[tab][i] == cell[tab][i + 1] && !(cell[tab][i + 2] == 'X' || cell[tab][i + 2] == '0'))
            return i + 2;
        if (cell[tab][i] == cell[tab][i + 2] && !(cell[tab][i + 1] == 'X' || cell[tab][i + 1] == '0'))
            return i + 1;
        if (cell[tab][i + 1] == cell[tab][i + 2] && !(cell[tab][i] == 'X' || cell[tab][i] == '0'))
            return i;
    }
    for (int i = 1;i <= 3;i++)
    {
        if (cell[tab][i] == cell[tab][i + 3] && !(cell[tab][i + 6] == 'X' || cell[tab][i + 6] == '0'))
            return i + 6;
        if (cell[tab][i] == cell[tab][i + 6] && !(cell[tab][i + 3] == 'X' || cell[tab][i + 3] == '0'))
            return i + 3;
        if (cell[tab][i + 3] == cell[tab][i + 6] && !(cell[tab][i] == 'X' || cell[tab][i] == '0'))
            return i;
    }
    if (cell[tab][1] == cell[tab][5] && !(cell[tab][9] == 'X' || cell[tab][9] == '0'))
        return 9;
    if (cell[tab][1] == cell[tab][9] && !(cell[tab][5] == 'X' || cell[tab][5] == '0'))
        return 5;
    if (cell[tab][5] == cell[tab][9] && !(cell[tab][1] == 'X' || cell[tab][1] == '0'))
        return 1;
    if (cell[tab][3] == cell[tab][5] && !(cell[tab][7] == 'X' || cell[tab][7] == '0'))
        return 7;
    if (cell[tab][3] == cell[tab][7] && !(cell[tab][5] == 'X' || cell[tab][5] == '0'))
        return 5;
    if (cell[tab][5] == cell[tab][7] && !(cell[tab][3] == 'X' || cell[tab][3] == '0'))
        return 3;
    return 0;
}
int main()
{
    int n, game = -1, player = 2;
    char sym = 'X';
    while (game == -1)
    {
        if (player == 2)
            player = 1;
        else
            player = 2;
        if (player == 1){
            print();
            printf("Computer move: %d\n", n);
            do {
                
                printf("Enter the table number and cell number! E.g. For table no. 4 and cell 5 enter 45.\nEnter the table number and cell number: \n");
                scanf("%d", &n);
            } while (n > 70 || n < 11);
        }
        else
            do {
                if (clever_computer(n / 10 - 1) == 0)
                    n = rand() % 70;
                else
                    n =(n / 10)*10 + clever_computer(n / 10 - 1);
                if (cell[n / 10 - 1][n % 10] == 'X' || cell[n / 10 - 1][n % 10] == '0')
                    n = 70;
            } while (n > 70 || n < 11);
            if (player == 2)
                sym = '0';
            else
                sym = 'X';
            if (cell[n / 10 - 1][n % 10] != 'X' && cell[n / 10 - 1][n % 10] != '0')
                cell[n / 10 - 1][n % 10] = sym;
            else
            {
                if (player == 1)
                    printf("Error!Change position!\n");
                player = 2;
            }
            game = check(n / 10 - 1);
    }

    print();
    if (game == 1)
        if (player == 1)
            printf("You won!");
        else
            printf("Computer won !");
    else
        printf("Draw\n");

    return 0;
}