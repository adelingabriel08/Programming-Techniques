#include <stdio.h>
#include <math.h>
#define N 2
struct gshape
{
    int type;
    int ID;
    union {
        struct
        {
            float radius;
            float x, y;
        } circle;
        struct
        {
            float x1, y1, x2, y2, x3, y3;
        } triangle;
        struct
        {
            float x1, y1;
            float x4, y4;
        } rectangle;
    } gshape;

    void (*read_gshape)(struct gshape *gs);
    void (*write_gshape)(struct gshape *gs);
    void (*area)(struct gshape *gs);
};

void read_circle(struct gshape *gs)
{
    printf(" radius ? ");
    scanf("%f ", &(gs->gshape.circle.radius));
    printf("X center ? ");
    scanf("%f ", &(gs->gshape.circle.x));
    printf("Y center?");
    scanf("%f ", &(gs->gshape.circle.x));
}
void write_circle(struct gshape *gs)
{
    printf(" %f %f %f", &(gs->gshape.circle.x), &(gs->gshape.circle.y), &(gs->gshape.circle.radius));
}
void read_triangle(struct gshape *gs)
{
    scanf(" %f %f %f %f %f %f ", &(gs->gshape.triangle.x1),
            &(gs->gshape.triangle.y1), &( gs->gshape.triangle.x2),
           &( gs->gshape.triangle.y2), &(gs->gshape.triangle.x3),
            &(gs->gshape.triangle.y3));
}
void write_triangle(struct gshape *gs)
{
    printf("Triangle (% f ,% f ) (% f ,% f ) , (% f ,% f )\n ", gs->gshape.triangle.x1,
           gs->gshape.triangle.y1, gs->gshape.triangle.x2,
           gs->gshape.triangle.y2, gs->gshape.triangle.x3,
           gs->gshape.triangle.y3);
}
void read_rectangle(struct gshape *gs)
{
    printf("Reading rectangle :\n ");
    scanf(" %f %f %f %f", &(gs->gshape.rectangle.x1), &(gs->gshape.rectangle.y1), &(gs->gshape.rectangle.x4), &(gs->gshape.rectangle.y4));
}
void write_rectangle(struct gshape *gs)
{
    printf(" %f %f %f %f", gs->gshape.rectangle.x1, gs->gshape.rectangle.y1, gs->gshape.rectangle.x4, gs->gshape.rectangle.y4);
}
void area_circle(struct gshape *gs)
{
    printf("Circle area: %f\n", 3.14 * gs->gshape.circle.radius * gs->gshape.circle.radius);
}
float length(int x1, int y1, int x2, int y2)
{
     return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void area_triangle(struct gshape *gs)
{
     float a, b, c, p;
     a = length(gs->gshape.triangle.x1, gs->gshape.triangle.x2, gs->gshape.triangle.y1, gs->gshape.triangle.y2);
     b = length(gs->gshape.triangle.x2, gs->gshape.triangle.x3, gs->gshape.triangle.y2, gs->gshape.triangle.y3);
     c = length(gs->gshape.triangle.x3, gs->gshape.triangle.x1, gs->gshape.triangle.y3, gs->gshape.triangle.y1);
     p = (a + b + c)/2.0;
     float area = sqrt(p*(p-a)*(p-b)*(p-c));
     printf("Triangle area: %f \n", area);
}
void area_rectangle(struct gshape *gs)
{
    int x, y;
    x = gs->gshape.rectangle.x1;
    y = gs->gshape.rectangle.y4;
    printf("Rectangle area: %f\n", length(x,y,gs->gshape.rectangle.x1,gs->gshape.rectangle.y1)*
                                    length(x,y,gs->gshape.rectangle.x4, gs->gshape.rectangle.y4));
}
int main(void)
{
    int i, type;
    struct gshape gs[N];
    printf("Initializing the geometric shapes collection:\n ");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Shape ID %d : ", i);
            printf("What type of shape is it ? (0= circle, 1= triangle , 2= rectangle)");
            scanf(" %d", &type);
            gs[i].type = type;
            gs[i].ID = i;
            switch (gs[i].type)
            {
            case 0:
            {
                gs[i].read_gshape = &read_circle;
                gs[i].write_gshape = &write_circle;
                gs[i].area = &area_circle;
                gs[i].read_gshape(gs+i);
                break;
            }
            case 1:
            {
                gs[i].read_gshape = &read_triangle;
                gs[i].write_gshape = &write_triangle;
                gs[i].area = &area_triangle;
                gs[i].read_gshape(gs+i);
                break;
            }
            case 2:
            {
                gs[i].read_gshape = &read_rectangle;
                gs[i].write_gshape = &write_rectangle;
                gs[i].area = &area_rectangle;
                gs[i].read_gshape(gs+i);
                break;
            }
            }
        } while((gs[i].type != 0) && (gs[i].type != 1) && (gs[i].type != 2));
    }
     for (i = 0; i < N; i++)
         if (gs[i].type == 2)
             gs[i].area(&gs[i]);
    return 1;
}
