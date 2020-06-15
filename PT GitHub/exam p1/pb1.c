#include<stdio.h>
#include<stdlib.h>

struct _number
{
    unsigned int nr;
    unsigned int occurences;
    float percent;
}*number;
int counter=0, i=0;

typedef struct _node
{
    struct _number data;
    struct _node *next;
}node;
node *head = NULL;
node *tail = NULL;
int alreadyexist(int nr)
{
    for(int j=0; j< i; j++)
        if(number[j].nr == nr)
        {
            number[j].occurences++;
            return 1;
        }
    return 0;

}
void readFile(char filename[])
{
    FILE *f;
    f=fopen(filename, "rb");
    if(!f)
    {
        printf("Cannot find the input file");
        exit(-1);
    }
    number = NULL;
    number = malloc(sizeof(struct _number));
    if(!number)
    {
        printf("Cannot alloc mem");
        exit(-1);
    }
    int nr;
    while(fread(&nr, sizeof(unsigned int), 1, f))
    {
        counter++;
        if(!alreadyexist(nr)){
            number[i].nr = nr;
            number[i].occurences++;
        }
        number = realloc(number, sizeof(struct _number)*(i+2));
        i++;
    }
    fclose(f);
}
void sort()
{
    struct _number aux;
    for(int j=0; j< i-1; j++)
        for(int k=j+1; k< i; k++)
        if(number[i].nr>number[j].nr)
            {
                aux = number[i];
                number[i] = number[j];
                number[j] = aux;
            }
}
void print()
{
    printf("counter: %d\n", counter);
    for(int j=0; j< i; j++)
        printf("%d ", number[j].nr);
}
void add_to_list(struct _number n)
{
    node *temp = malloc(sizeof(node));
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
}
void print_list(char filename[])
{
    FILE *f = fopen(filename, "w");
    if (!head)
        exit(-1);
    for (node *p = head; p!=NULL; p = p->next){
        //p->data.percent = (float)(p->data.occurences/counter)*100;
        fprintf(f, "%d : %d : %f\n", p->data.nr, p->data.occurences, p->data.percent);
    }
    printf("\n");
    fclose(f);
}
void free_memory(node *p)
{
    node *t;
    while (p)
    {
        t = p->next;
        free(p);
        p = t;
    }
}
int main(int argc, char **argv)
{
    readFile(argv[1]);
    sort();
    //print();
    for(int j=0; j<i; j++)
        add_to_list(number[j]);
    print_list(argv[2]);
    free_memory(head);
    return 0;
}