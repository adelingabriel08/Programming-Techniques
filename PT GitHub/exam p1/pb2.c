#include<stdio.h>
#include<stdlib.h>

typedef struct _node{ // list definition
    int data;
    struct _node *next;
    struct _node *prev;
}node;
node *head = NULL;
node *tail = NULL;
int n=1;

void sort(int arr[], int n) //insertion sort, sorting the array in ascending order before inserting in the list
{
    int aux;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[i])
            {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
}
int* read()
{
    FILE *f=fopen("filecopy.bin", "rb");// opening the passwn file
    if(!f)
    {
        printf("Cannot find filecopy.bin file\n");
        exit(-1);
    }
    int *values = malloc(sizeof(int)); // allocating mem for elements
    while(fread(&values[n-1], sizeof(int), 1, f)) // while reading the array from the file
    {
        n++;
        values = realloc(values, sizeof(int)*n); // reallocating memory for array while is reading
    }
    fclose(f);
    return values; // returning the array pointer
}
void print(int arr[], int n)
{
    printf("Array elems: "); // printing the array elements
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void add_to_list(int nr) // creating a node and add it to the list
{
        if (head == NULL) // if head is null then create it
        {
            node *temp;
            temp = (node *)malloc(sizeof(node));
            if (temp == NULL)
            {
                printf("Error malloc for nodes");
                exit(-1);
            }
            temp->data = nr; // insert data in the node
            temp->next = NULL; // head is the single node now
            temp->prev = NULL;
            head = temp; // head is the created node, temp
            tail = head; // tail is the last node
        }
        else
        {
            node *temp;
            temp = (node *)malloc(sizeof(node)); // alloc memory for the node
            if (temp == NULL)
            {
                printf("Error malloc creating initial list");
                exit(-1);
            }
            temp->data = nr; // insert data in the node
            temp->next = NULL; // temp is the last node
            tail->next = temp; // the tail next node will be the created one
            temp->prev = tail; // the created node has the tail node as previous
            tail = temp; // the created node will be the last
        }
}
void print_list() // printing the list starting from head
{
    node *temp;
    printf("List content: ");
    for(temp = head; temp!=NULL; temp=temp->next)
        printf("%d ", temp->data);
    printf("\n");
}
void free_memory(node *p) // clearing the memory starting from node p
{
    node *aux;
    while (p)
    {
        aux = p->next;
        free(p);
        p = aux;
    }
}
int main()
{
     int *arr = read(); 
    // print(arr, n);
     sort(arr, n);
    // print(arr, n);
    for(int i=0; i<n; i++) // adding the sorted array data in the list
        add_to_list(arr[i]);
    print_list();
    free_memory(head);
    return 0;
}