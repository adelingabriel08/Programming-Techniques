#include<stdio.h>
#include<stdlib.h>

enum shapess{
	Triangle = 0,
	Rectangle = 1,
	Circle = 2
};
struct points
{
    int x;
    int y;  
};

struct triangles
{
    struct points A , B , C;
};

struct rectangles
{
	struct points A,D;
};
struct circles
{
	struct points O,r;
};
struct shapes{
	struct triangles triangle;
	struct rectangles rectangle;
	struct circles circle;
	unsigned flag;
};
int main()
{
	unsigned aux,n;
	printf("Enter the number of shapes: ");
	scanf(" %u",&n);
	struct shapes shape[n];
	for(int i=0;i<n;i++){
	printf("Enter '0' for triangle , '1' for rectangle , '2' for circle ");
	scanf(" %u",&aux);
	if((aux>=0)&&(aux<=2))
		shape[i].flag = aux;
	else {
		printf("Error");
		i--;
		}
	}
	for(int i=0;i<n;i++)
		if(shape[i].flag== Triangle)
		{
			printf("Enter the triangle coordinates: \n");
			scanf(" %u%u%u%u%u%u",&shape[i].triangle.A.x, &shape[i].triangle.A.y, &shape[i].triangle.B.x, &shape[i].triangle.B.y, &shape[i].triangle.C.x, &shape[i].triangle.C.y);
		}
		else if(shape[i].flag == Rectangle)
		{
			printf("Enter the rectangle coordinates:\n");
			scanf(" %u%u%u%u",&shape[i].rectangle.A.x , &shape[i].rectangle.A.y, &shape[i].rectangle.D.x , &shape[i].rectangle.D.y);
		}
		else
		{
			printf("Enter the circle coordinates:\n");
			scanf(" %u%u%u%u",&shape[i].circle.O.x,&shape[i].circle.O.y,&shape[i].circle.r.x,&shape[i].circle.r.y);
		}
		for(int i=0;i<n;i++)
			if(shape[i].flag==Triangle)
		{
			printf("Triangle: (%u,%u) (%u,%u) (%u,%u)",shape[i].triangle.A.x,shape[i].triangle.A.y,shape[i].triangle.B.x,shape[i].triangle.B.y,shape[i].triangle.C.x,shape[i].triangle.C.y);
		}
		else if(shape[i].flag==Rectangle)
		{
			printf("Rectangle: (%u,%u) (%u,%u) (%u,%u) (%u,%u)",shape[i].rectangle.A.x,shape[i].rectangle.A.y,shape[i].rectangle.D.x,shape[i].rectangle.A.y,shape[i].rectangle.D.x,shape[i].rectangle.D.y,shape[i].rectangle.A.x,shape[i].rectangle.D.y);
		}
		else
		{
			printf("Circle: (%u,%u) (%u,%u)",shape[i].circle.O.x,shape[i].circle.O.y,shape[i].circle.r.x,shape[i].circle.r.y);
		}
	return 0;
}