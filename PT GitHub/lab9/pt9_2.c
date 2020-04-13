#include<stdio.h>
#include<string.h>
int n;
int x=200,y=0;
char colors[5][30]={"black","blue","red","orange","pink"};
int diskWidth[5]={150,125,100,75,50},diskHeight=20;
int disk_y[5]={20,40,60,80,100};
int disk_x[5]={200,200,200,200,200};
void set_disk(int i,char fromPeg,char toPeg)
{
    if( (fromPeg=='A' && toPeg=='B') || (fromPeg=='B' && toPeg=='C'))
        disk_x[i]+=200;
    else if(fromPeg=='A' && toPeg=='C')
            disk_x[i]+=400;
        else if((fromPeg=='C' && toPeg=='B') || (fromPeg=='B' && toPeg=='A'))
                disk_x[i]-=200;
            else if(fromPeg=='C' && toPeg=='A')
                    disk_x[i]-=400;

}
void board()
{
        y+=200;
        printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" stroke-width=\"4\" />\n", x, y, 425, 20);
        printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" stroke-width=\"4\" />\n", x, y-150, 20, 160);
        printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" stroke-width=\"4\" />\n", x+200, y-150, 20, 160);
        printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" stroke-width=\"4\" />\n", x+400, y-150, 20, 160);
        for(int i=0;i<n;i++)
            printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\"/>\n", disk_x[i]-diskWidth[i]/2+10, y-disk_y[i], diskWidth[i], diskHeight,colors[i]);
}
void movedisks (int ndisks, char fromPeg, char toPeg, char auxPeg) 
{
    if (ndisks == 0){
        set_disk(n-ndisks-1,fromPeg,toPeg);
        board();
    }
    else
    {
        movedisks(ndisks-1, fromPeg, auxPeg, toPeg);
        set_disk(n-ndisks-1,fromPeg,toPeg);
        board();
        movedisks(ndisks-1, auxPeg, toPeg, fromPeg);
    }
}
int main(void) {  
    scanf(" %d",&n);
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 1920, n*1300);
    board();
    movedisks(n-1, 'A' , 'C' , 'B');
    printf("</svg>");
    
}
