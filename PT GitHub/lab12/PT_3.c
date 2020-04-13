#include <stdio.h>
#include<stdlib.h>
typedef struct nodes {
    int data;
    struct nodes* next;
}node;
node* head = NULL;
node* tail = NULL;
void givenList(int n)
{
    int i = n--;
    while (i >= 0)
        if (head == NULL)
        {
            node* p;
            p = (node*)malloc(sizeof(node));
            if (p == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            p->data = i--;
            p->next = NULL;
            head = p;
            tail = head;
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
            p->data = i--;
            p->next = head;
            head = p;
        }
    tail->next = head;

}
void print(node* first)
{
    node* p;
    for (p = first;p != tail;p = p->next)
        printf("%d ", p->data);
    printf("%d ", p->data);
    printf("\n");

}
void RemoveFromList(int n)
{
    int i = 0;
    node* aux, *p = head;
    while (i++ < (n / 2)-1)
        p = p->next;
    printf("The node %d will get out from this list \n", p->data+1);
    aux = p;
    p = p->next;
    aux->next = p->next;
    free(p);
}
void clearMemory(node* first,int n)
{
    node* p;
    int i = 0;
    while (i++<n) {
        p = head->next;
        free(head);
        head = p;
    }
    printf("Memory cleared successfully\n");
}
int main()
{
    int n=6; //number of list elements
    givenList(n);
    print(head);
    RemoveFromList(n);
    print(head);
    clearMemory(head,n);
    return 0;
}

