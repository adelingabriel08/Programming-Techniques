#include <stdio.h>
#include<stdlib.h>
typedef struct nodes {
    int data;
    struct nodes* prev;
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
            p->prev = NULL;
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
            p->prev = NULL;
            p->next = head;
            head->prev = p;
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
node* constructNewList()
{
    node* first = NULL;
    node* list_node;
    for (list_node = head;list_node != NULL;list_node = list_node->next)
    {
        node* p;
        p = (node*)malloc(sizeof(node));
        if (p == NULL)
        {
            printf("Error malloc creating initial list");
            exit(-1);
        }
        p->data = list_node->data;
        if (first == NULL)
        {
            p->prev = NULL;
            p->next = NULL;
            first = p;
        }
        else {
            p->prev = NULL;
            p->next = first;
            first->prev = p;
            first = p;
        }
    }
    return first;

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
int main()
{
    givenList(5);
    print(head);
    node* first=constructNewList();
    print(first);
    clearMemory(first);
    clearMemory(head);
    return 0;
}
