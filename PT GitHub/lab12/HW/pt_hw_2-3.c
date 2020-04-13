/*Create a simple linked list with numbers from the keyboard and delete from the list the odd numbers */
#include <stdio.h>
#include<stdlib.h>
typedef struct nodes{
    int data;
    struct nodes *next;
}node;
node *head=NULL;
int readData()
{
    int n;
    printf("Enter the list data: ");
    scanf(" %d",&n);
    return n;
}
void createList(int n)
{
    int i = n--;
    while (i > 0)
        if (head == NULL)
        {
            node* p;
            p = (node*)malloc(sizeof(node));
            if (p == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            p->data = readData();
            p->next = NULL;
            head = p;
            i--;
        }
        else
        {
            node* p;
            p = (node*)malloc(sizeof(node));
            if (p == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            p->data = readData();
            p->next = head;
            head = p;
            i--;
        }
    
}
void deleteOddNumbers()
{
    node *p,*q;
    while(head->data%2==0)
    {
        q=head;
        head=head->next;
        free(q);
    }
    p=head;
    while(p->next)
        if(p->next->data%2==0)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        else p=p->next;
}
void print(node* first)
{
    node* p;
    for (p = first;p != NULL;p = p->next)
        printf("%d ", p->data);
    printf("\n");

}
void clearMemory(node *first)
{
    node* p;
    while(first!=NULL) {
        p = first->next;
        free(first);
        first = p;
    }
    printf("Memory cleared successfully\n");
}
int main()
{
    int n;
    printf("How many elements does your list has?\n");
    scanf(" %d",&n);
    createList(n);
    print(head);
    deleteOddNumbers();
    print(head);
    clearMemory(head);
    return 0;
}
