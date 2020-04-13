#include <stdio.h>
#include<stdlib.h>
typedef struct nodes {
    int data;
    struct nodes* next;
}node;
node* head = NULL;
node* tail = NULL;
node* first_head = NULL;
node* second_head = NULL;
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
    while(head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    printf("Memory cleared successfully\n");
}
node* splitList(int n)
{
    first_head = head;
    node* last = NULL;
    node* p;
    p = head;
    while (p->data != n)
        if (p == NULL)
        {
            printf("Cannot split the list");
            exit(-1);
        }
        else {
            last = p;
            p = p->next;
        }
    last->next = NULL;
    second_head = p;
        
}
int main()
{
    givenList(5);
    print(head);
    splitList(2);
    print(first_head);
    print(second_head);
    clearMemory(first_head);
    clearMemory(second_head);
    return 0;
}
