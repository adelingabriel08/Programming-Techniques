#include<stdio.h>
#include <math.h>
#include<stdlib.h>

typedef struct points
{
    float x,y;
}point;
int iterations=5;
void generate_triangle(int n,point A, point B)
{
    point D,E,F;
        D = (point){
                (2*A.x+B.x)/(float)3,
                (2*A.y+B.y)/(float)3
            };
		E = (point){
            (2*B.x+A.x)/(float)3,
            (2*B.y+A.y)/(float)3
            };
        F=(point)
        {
            (E.x + D.x + sqrt(3)*(E.y - D.y) )/(float)2,
            (D.y + E.y + sqrt(3)*(D.x - E.x) )/(float)2
        };
    if(n==0)
    {
        printf("%f,%f %f,%f ",A.x,A.y,B.x,B.y);
    }
    else
    {
        generate_triangle(n-1,A,D);
        generate_triangle(n-1,D,F);
        generate_triangle(n-1,F,E);
        generate_triangle(n-1,E,B);
    }
    
}
int main()
{
    point A,B,C;
    B.x=300;
    B.y=500;
    C.x=800;
    C.y=500;
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 1920, 3000);
    A= (point){
                (C.x + B.x + sqrt(3)*(C.y - B.y) )/(float)2,
                (B.y + C.y + sqrt(3)*(B.x - C.x) )/(float)2
            };
    printf("<polyline points=\"%f,%f ",A.x,A.y);
    generate_triangle(iterations-1,A,C);
    generate_triangle(iterations-1,C,B);
    generate_triangle(iterations-1,B,A);
    printf("%f,%f\" stroke=\"black\" stroke-width=\"4\" fill=\"none\" />\n",A.x,A.y);
    printf("<text x=\"450\" y=\"300\" fill=\"green\" style=\"font-size: 40px; \">#StamAcasa</text>");
    printf("</svg>\n");
    return 0;

}