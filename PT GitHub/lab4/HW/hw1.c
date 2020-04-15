#include <stdio.h>

struct main_stars{
    char name[40];
    int age;
    char color[13];
};
struct binary_stars{
    char name[40];
    int rotationRadius_star1,rotationRadius_star2;
};
struct light_stars{
    char name[40];
    int low_luminosity,high_luminosity,light_period;
};
union stars{
    struct main_stars mstars;
    struct binary_stars bstars;
    struct light_stars lstars;
};
int main()
{
    int n;
    printf("Enter the number of stars:");
    scanf(" %d",&n);
    union stars star[n];
    int flags[n];
    for(int i=0;i<n;i++)
    {
        printf("0 Main Stars\n 1 Binary stars\n 2 Light Stars\n Enter your option:  ");
        do{
            scanf(" %d",&flags[i]);
        }while(flags[i]>=3);
        switch(flags[i]){
            case 0:
            {
                printf("Star Name: ");scanf(" %s",star[i].mstars.name);
                printf("Age: ");scanf(" %d",&star[i].mstars.age);
                printf("Color: ");scanf(" %s",star[i].mstars.color);
                break;
            }
            case 1:
            {
                 printf("Star Name: ");scanf(" %s",star[i].bstars.name);
                 printf("Rotation radius of the star 1: ");scanf(" %d",&star[i].bstars.rotationRadius_star1);
                 printf("Rotation radius of the star 2: ");scanf(" %d",&star[i].bstars.rotationRadius_star2);
                 break;
            }
            case 2:
            {
                printf("Star Name: ");scanf(" %s",star[i].lstars.name);
                printf("Low luminosity: ");scanf(" %d",&star[i].lstars.low_luminosity);
                printf("High luminosity: ");scanf(" %d",&star[i].lstars.high_luminosity);
                break;
            }
        }
        
    }
    for(int i=0;i<n;i++)
        switch(flags[i]){
            case 0:
            {
                printf("Star Name: %s\n",star[i].mstars.name);
                printf("Age: %d\n",star[i].mstars.age);
                printf("Color: %s\n",star[i].mstars.color);
                break;
            }
            case 1:
            {
                 printf("Star Name: %s\n",star[i].bstars.name);
                 printf("Rotation radius of the star 1: %d\n",star[i].bstars.rotationRadius_star1);
                 printf("Rotation radius of the star 2: %d\n",star[i].bstars.rotationRadius_star2);
                 break;
            }
            case 2:
            {
                printf("Star Name: %s\n",star[i].lstars.name);
                printf("Low luminosity: %d\n",star[i].lstars.low_luminosity);
                printf("High luminosity: %d\n",star[i].lstars.high_luminosity);
                break;
            }
        }
    return 0;
}
