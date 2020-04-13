#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodes
{
    char data[250];
    struct nodes *next;
    struct nodes *prev;
} node;
node *head = NULL;
node *tail = NULL;
char names[20][250];
int nr = 0;
void readData(char inputfile[])
{
    FILE *fin;
    fin = fopen(inputfile, "r");
    if (fin == NULL)
    {
        printf("file not found");
        exit(-1);
    }
    char aux[250];
    while (fscanf(fin, " %s", names[nr]) == 1)
        nr++;
    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
            if (strcmp(names[i], names[j]) >= 1)
            {
                strcpy(aux, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], aux);
            }
}

void createList(int n)
{
    while (n-- > 0)
        if (head == NULL)
        {
            node *p;
            p = (node *)malloc(sizeof(node));
            if (p == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            strcpy(p->data, names[n]);
            p->next = NULL;
            p->prev = NULL;
            head = p;
            tail = head;
        }
        else
        {
            node *p;
            p = (node *)malloc(sizeof(node));
            if (p == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            strcpy(p->data, names[n]);
            p->next = head;
            head->prev = p;
            head = p;
        }
    tail->next = head;
    head->prev = tail;
}
void print(node *first)
{
    node *p;
    for (p = first; p != tail; p = p->next)
        printf("%s ", p->data);
    printf("%s ", p->data);
    printf("\n");
}

void game(node *start, char clock[], int n)
{
    node *aux, *p = start;
    while (true)
    {
        int i = 1;
        if (strcmp(clock, "clockwise") == 0)
        {
            while (i++ < n)
            {
                printf("Skipping %s\n", p->data);
                p = p->next;
            }
            printf("Eliminating %s\n", p->data);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            aux = p->next;
            free(p);
            p = aux;
            if (p->next == p)
            {
                printf("Winner: %s \n Game over !", p->data);
                break;
            }
        }
        if (strcmp(clock, "counter-clockwise") == 0)
        {
            while (i++ < n)
            {
                printf("Skipping %s\n", p->data);
                p = p->prev;
            }
            printf("Eliminating %s\n", p->data);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            aux = p->prev;
            free(p);
            p = aux;
            if (p->next == p)
            {
                printf("Winner: %s \n Game over !", p->data);
                break;
            }
        }
    }
}

int main(int argv, char **argc)
{
    readData(argc[1]);
    createList(nr);
    print(head);
    char clock[30];
    unsigned int n;
    printf("Choose the number: ");
    scanf(" %u", &n);
    printf("Clockwise or counter-clockwise?\n");
    scanf(" %s", clock);
    if (strcmp(clock, "clockwise") == 0)
        game(head, clock, n);
    else if (strcmp(clock, "counter-clockwise") == 0)
        game(tail, clock, n);
    else
        printf("bad input!");
    return 0;
}
