#include <stdio.h>

struct insects{
    int legs,life;
};
struct birds{
    int speed,wing_length;
    char habbit[30];
};
struct mammals{
    int weight,height;
    char food[30];
};
struct fishes{
    int weight,swim,salt;
};
union animals{
    struct insects insect;
    struct birds bird;
    struct mammals mammal;
    struct fishes fish;
};
int main()
{
    int n;
    printf("No. of animals: "); scanf("%d",&n);
    union animals animal[n];
    int flags[n];
    for(int i=0; i<n; i++)
    {
        printf("0 Insect\n 1 Bird\n 2 Mammal\n 3 Fish \n Enter your option: ");
        do{
            scanf(" %d",&flags[i]);
        }while(flags[i]>=4);
        switch(flags[i])
        {
            case 0:
            {
                printf("Number of insect legs:"); scanf(" %d",&animal[i].insect.legs);
                printf("Life span: "); scanf(" %d",&animal[i].insect.life);
                break;
            }
            case 1:
            {
                printf("Flight speed: "); scanf(" %d",&animal[i].bird.speed);
                printf("Wing length: "); scanf(" %d",&animal[i].bird.wing_length);
                printf("Habbit: "); scanf(" %s",animal[i].bird.habbit);
                break;
            }
            case 2:
            {
                printf("Weight: "); scanf(" %d",&animal[i].mammal.weight);
                printf("Height: "); scanf(" %d",&animal[i].mammal.height);
                printf("Food: "); scanf(" %s",animal[i].mammal.food);
                break;
            }
            case 3:
            {
               printf("Weight: "); scanf(" %d",&animal[i].fish.weight);
               printf("Swimming depth: "); scanf(" %d",&animal[i].fish.swim);
               printf("Water salt: "); scanf(" %d",&animal[i].fish.salt);
               break;
            }
        }
    }
    for(int i=0;i<n;i++)
        switch(flags[i])
        {
            case 0:
            {
                printf("Number of insect legs: %d\n",animal[i].insect.legs);
                printf("Life span: %d\n",animal[i].insect.life);
                break;
            }
            case 1:
            {
                printf("Flight speed: %d\n",animal[i].bird.speed);
                printf("Wing length: %d\n",animal[i].bird.wing_length);
                printf("Habbit: %s\n",animal[i].bird.habbit);
                break;
            }
            case 2:
            {
                printf("Weight: %d\n",animal[i].mammal.weight);
                printf("Height: %d\n",animal[i].mammal.height);
                printf("Food: %s\n",animal[i].mammal.food);
                break;
            }
            case 3:
            {
               printf("Weight: %d\n",animal[i].fish.weight);
               printf("Swimming depth: %d\n",animal[i].fish.swim);
               printf("Water salt: %d\n",animal[i].fish.salt);
               break;
            }
        }
    return 0;
    
}