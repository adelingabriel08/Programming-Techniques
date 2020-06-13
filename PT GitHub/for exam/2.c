// 2. a bin file contains fibonacci nr in an unsorted sequence
// a) add the elems in a circular simple linked list
// b) choose a random node and append the number from it in the bin file
// c) sort the bin file without qsort()

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node; // node def
node *head, *tail;
void add_to_list(int n)
{
    node *temp = malloc(sizeof(node)); // aloc memorie noului nod
    temp->data = n; // adaug n-ul in nod
    if (head == NULL)// daca nu are vreun element va fi "head" noul nod
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp; // il leg de ultimul nod
        temp->next = head; // il leg de head sa fie lista circulara
        tail = temp;
    }
}
void print_list()
{
    if (!head)
        exit(-1); // daca e nula sa nu crape
    printf("List elements: %d ", head->data);
    for (node *p = head->next; p != head && p!=NULL; p = p->next) // parcurg lista pana cand vede ca a ajuns iar la head
        printf("%d ", p->data);
    printf("\n");
}
void free_memory(node *p) // elimin memoria folosita de lista
{
    node *t; // temporary node
    while (p)
    {
        t = p->next; // ii dau lui t urmatorul ca nu o sa stie cine e urmatorul dupa ce sterg nodul
        free(p);
        p = t; // p devine urmatorul
        if (t == tail) // sterg ultimul element ca dupa o sa crape daca face t=p->next pentru ca nu exista
        {
            free(t);
            break;
        }
    }
}
int fibo(int n) // genereaza al n-lea termen fibonacci
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}
void gen_binary_file(int n) // genereaza fisierul cu 10 termeni random%10 ai lui fibonacci
{
    FILE *f;
    f = fopen("binary.bin", "wb");
    for (int i = 0; i < n; i++)
    {
        int fib = fibo(rand() % 10);
        fwrite(&fib, sizeof(int), 1, f);
    }
    fclose(f);
}
void read_bin_and_add_to_list()//citesc din fisier si creez lista cu elemente
{
    FILE *f;
    f = fopen("binary.bin", "rb");
    int data;
    while (fread(&data, sizeof(int), 1, f))
        add_to_list(data);
    fclose(f);
}
void append() // scriu un element random din lista la finalul fisierului
{
    FILE *f;
    f = fopen("binary.bin", "ab");
    int random = rand() % 10;
    node *p;
    p = head;
    while (--random) // parcurg lista pana la elementul random
        p = p->next;
    fwrite(&p->data, sizeof(int), 1, f); // il scriu in fisier
    // printf("Data added: %d \n", p->data);
    fclose(f);
}
// for(int i=0; i<n; i++)
//     for(int j=i+1; j<n; j++)
//     if(ceva < ceva2)
//     aux = ceva;
//     ceva = ceva2;
//     ceva = aux;
void sort_binary()
{
    FILE *f;
    f = fopen("binary.bin", "r+b"); // deschid fisierul
    int a, b, a_pos, b_pos;
    // for(int i=0; i<n; i++)
    //     for(int j=i+1; j<n; j++)
    //     if(a[i] < a[j])
    //     aux = a[i];
    //     a[i] = a[j];
    //     a[j] = aux;
    while (fread(&a, sizeof(int), 1, f)) // citesc a
    {
        a_pos = ftell(f); // iau pozitia lui a din fisier , adica i-ul din vector cum ar fi
        while (fread(&b, sizeof(int), 1, f)) // citesc b
            if (a > b)
            {
                b_pos = ftell(f); // iau pozitia lui b din fisier
                //printf("Swap elements with the pos: %d %d and the elements are: a: %d b: %d\n", a_pos/4 -1, b_pos/4 -1, a, b);
                fseek(f, a_pos - sizeof(int), SEEK_SET); // sar la pozitia lui a
                fwrite(&b, sizeof(int), 1, f);// suprascriu a cu b
                fseek(f, b_pos - sizeof(int), SEEK_SET); // sar la pozitia lui b
                fwrite(&a, sizeof(int), 1, f);// suprascriu b cu a
                a = b; // ii dau valoarea pe care o are a acum
            }
        fseek(f, a_pos, SEEK_SET);
    }
    fclose(f);
}
int main()
{
    //gen_binary_file(10); //generez numerele in fisier
    read_bin_and_add_to_list(); // citesc lista
    print_list();               // o printez
    append();                   // adaug un element random din lista in fisier, la final
    free_memory(head);          // scap de memoria folosita
    sort_binary();              // sortez fisierul
    return 0;
}