#include<stdio.h>
void sierpinski(int n, int x, int y, int width)
{
    if( n==0 ) return;
    printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"black\"/>\n", x, y, width, width);
    sierpinski(n-1,x + width/3, y - 2*width/3, width/3);//middle top
    sierpinski(n-1,x + width/3 - 2*width/3 - width/3, y - 2*width /3, width/3);//middle 
    sierpinski(n-1,x + width/3 - 2*width/3 - width/3, y - 2*width /3, width/3);// left top
    sierpinski(n-1,x + width/3 + 2*width/3 + width/3, y - 2*width/3, width/3);//right top
    sierpinski(n-1,x + width/3, y + width + width/3, width/3);// middle bottom
    sierpinski(n-1,x + width/3 - 2*width/3 - width/3, y + width + width/3, width/3);// left bottom
    sierpinski(n-1,x + width/3 + 2*width/3 + width/3, y + width + width/3, width/3);//right bottom
    sierpinski(n-1,x - 2*width/3, y + width/3, width/3);//left middle
    sierpinski(n-1,x + width + width/3, y+width/3, width/3);//right middle
}
int main()
{
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 1920, 3000);
    sierpinski(6,500,300,200);
    printf("</svg>");
}