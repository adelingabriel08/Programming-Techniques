#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct nodes {
    float data;
    struct nodes* left;
    struct nodes* right;
}node;
node* root=NULL;
const float eps = 0.001;
float readNumber()
{
    float nr;
    printf("Enter the float number: ");
    scanf(" %f", &nr);
    return nr;
}
int checkNumber(float data, float new_number)
{
    if (fabs(new_number-data) < eps)
        return 0;
    else
        return 1;
}
node* find(node* current, float nr)
{
    if (checkNumber(current->data, nr))
    {
        if (current->data > nr)
            if (current->left == NULL)
            {
                return current;
            }
            else
                return find(current->left, nr);
        else
            if (current->right == NULL)
            {
                return current;
            }
            else
                return find(current->right, nr);
    }
    else
        return NULL;
}
int addNode(node* found, float nr)
{
    if (found == NULL)
        return 0;
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc error!");
        exit(-1);
    }
    p->data = nr;
    p->left = NULL;
    p->right = NULL;
    if (found->data > nr)
        found->left = p;
    else
        found->right = p;
    return 1;
}
void binaryTree(int n)
{
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc error!");
        exit(-1);
    }
    p->data = readNumber();
    p->left = NULL;
    p->right = NULL;
    root = p;
    while (--n){
        float nr=readNumber();
        addNode(find(root,nr),nr);
    }
}
void print(node* p) //preorder
{
    if (p != NULL) {
        printf("%f ", p->data);
        print(p->left);
        print(p->right);
    }
}
void freeMemory(node* p)
{
    if(p!=NULL)
    {
        freeMemory(p->left);
        freeMemory(p->right);
        free(p);
    }
}
int main()
{   
    int n;
    printf("Enter the number of floating points: ");
    scanf(" %d",&n);
    binaryTree(n);
    print(root);
    freeMemory(root);
    return 0;
}
