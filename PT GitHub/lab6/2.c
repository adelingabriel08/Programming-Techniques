#include <stdio.h>
#include<math.h>
#define N 10

struct point
{
    float x , y;
}point1;

struct shape
{
    int type; // 0 , 1 , 2
    int ID;
    union
    {
        struct
        {
            float radius;
            struct point center; //center of the circle
        } circle;
        
        struct
        {
            struct point t1 , t2 , t3;
        }triangle;
        
        struct
        {
            struct point t1,t4; //upper left and right bottom
        }rectangle;
        
    }shape;
    
    void (*read_shape)(struct shape *shape_ptr);
    void (*write_shape)(struct shape *shape_ptr);
    void (*area)(struct shape *shape_ptr);
};

void read_circle(struct shape *shape_ptr)
{
    printf("Enter radius.\n");
    scanf("%f", &(shape_ptr->.circle.radius));
    
    printf("Enter center.\n");
    scanf("%f %f", &(shape_ptr->.circle.center.x),&(shape_ptr->.circle.center.y));
}

void write_circle (struct shape *shape_ptr)
{
    printf("Circle : (%f ,%f) , %f\n", shape_ptr->shape.circle.center.x , shape_ptr->shape.circle.center.y , shape_ptr->shape.circle.radius);
}

void area_circle (struct shape *shape_ptr) // A = 2*pi*r^2
{
    printf("Circle area: %f\n", 2 * 3.14 * shape.circle.radius*shape.circle.radius);
    return 0;
}

void read_triangle (struct shape *shape_ptr) // A = sqrt(p(p-a)(p-b)(p-c)) , p = (a + b + c) / 2;
{
    printf("Enter coordinates.\n");
    scanf("%f %f %f %f %f %f",&(shape_ptr->.triangle.t1.x) , &(shape_ptr->.triangle.t1.y) , &(shape_ptr->.triangle.t2.x) , &(shape_ptr->.triangle.t2.y) ,&(shape_ptr->.triangle.t3.x) , &(shape_ptr->.triangle.t3.y));
}

void write_triangle (struct shape *shape_ptr)
{
    printf("Triangle : (%f ,%f) , (%f ,%f) , (%f ,%f)\n", shape_ptr->shape.triangle.t1.x , shape_ptr->shape.triangle.t1.y , shape_ptr->shape.triangle.t2.x, shape_ptr->shape.triangle.t2.y , shape_ptr->shape.triangle.t3.x ,shape_ptr->shape.triangle.t3.y);
}

float area_triangle (struct shape *shape_ptr)
{
    float p = (
    return 0;
}
void read_rectangle (struct shape *shape_ptr)
{
    printf("Enter coordinates.\n");
    scanf("%f %f %f %f %f %f",&(shape_ptr->.rectangle.t1.x) , &(shape_ptr->.rectangle.t1.y) , &(shape_ptr->.rectangle.t4.x) , &(shape_ptr->.rectangle.t4.y));
}

void write_rectangle (struct shape *shape_ptr)
{
    printf("Rectangle : (%f ,%f) , (%f ,%f) , (%f ,%f)\n", shape_ptr->shape.rectangle.t1.x , shape_ptr->shape.rectangle.t1.y , shape_ptr->shape.rectangle.t4.x, shape_ptr->shape.rectangle.t4.y);
}

float area_rectangle (struct shape *shape_ptr) // A = l * L;
{
    return 0;
}


int main()
{
    int i , type;
    struct shape shape_ptr[N];
    
    for( i = 0; i < N; i++)
    {
        do
        {
            printf("Shape ID %d :\n",i);  //get info from user part
            printf("What shape is it? (0 = circle , 1 = triangle , 2 = rectangle)\n");
            scanf("%d",&type);
            shape_ptr[i].type = type;
            shape_ptr[i].ID = i;
            
            switch(shape_ptr[i].type) 
            {
                case 0:
                    shape_ptr[i].read_shape = &read_circle;
                    shape_ptr[i].write_shape = &write_circle;
                    break;
                
                case 1:
                    shape_ptr[i].read_shape = &read_triangle;
                    shape_ptr[i].write_shape = &write_triangle;
                    break;
                    
                case 2:
                    shape_ptr[i].read_shape = &read_rectangle;
                    shape_ptr[i].write_shape = &write_rectangle;
                    break;    
                    
                default :
                    printf("Oof...\n");
            }
        }
        while((shape_ptr[i].type != 0) && (shape_ptr[i].type != 1) && (shape_ptr[i].type != 2)) //do we do this in order to be sure that at pos i,the structure is filled?
    }
    
    printf("The area for every rectangle in our collection is:\n");
    for(i = 0; i<N ; i++)
        if(shape_ptr[i].type == 2)
            shape_ptr[i].write_area_rectangle(&shape_ptr[i]); //dummy function
    return 0;
}