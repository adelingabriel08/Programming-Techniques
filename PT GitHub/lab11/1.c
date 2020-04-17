#include<stdio.h>
#include<stdlib.h>
int arr[30],a[30][30],n,op,minDistance=9999999,route[30];
void print(int k)
{
    for(int i=0;i<=k;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void checkRoute()
{
    int distance=0;
    for(int i=0;i<n;i++) 
        if(a[arr[i]][arr[i+1]]==0)
            return;
        else
            distance+=a[arr[i]][arr[i+1]];
    if(distance<minDistance)
    {
        minDistance = distance;
        for(int i=0;i<n;i++)
            route[i]=arr[i];
    }
}
int check(int k)
{
    if(arr[0]!=op)
        return 0;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<=k;j++)
            if(arr[j]==arr[i])
                return 0;
    return 1;
}
void bkt(int k)
{
    for(int i = 0; i<n; i++)
    {
        arr[k]=i;
        if(k==n-1){
            if(check(k))
                checkRoute();
        }else
            bkt(k+1);
            
    }

}
int main(int argc, char **argv)
{
    FILE *fin;
    fin=fopen(argv[1],"r");
    if(fin==NULL)
    {
        printf("Error opening the file!");
        exit(-1);
    }
    fscanf(fin," %d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fin,"%d",&a[i][j]);
    printf("Choose the starting city: \n 0 - Timisoara, 1 - Oradea, 2 - Cluj-Napoca, 3 - Iasi, 4 - Bucuresti\n");
    scanf(" %d",&op);
    bkt(0);
    for(int i=0; i<n; i++)
        if(route[i]==0) printf("Timisoara ");
        else if(route[i]==1) printf("Oradea ");
            else if(route[i]==2) printf("Cluj ");
                else if(route[i]==3) printf("Iasi ");
                    else printf("Bucuresti ");
    printf("%d km \n", minDistance);
    return 0;
}