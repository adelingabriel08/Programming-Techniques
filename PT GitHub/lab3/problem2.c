#include<stdio.h>
#include<string.h>
struct student{
	char name[50];
	unsigned int grade;
}students[30];

void read_students(unsigned int n, struct student students[])
{
	for(int i=0;i<n;i++)
		{
			printf("Enter the student's name: ");
			scanf("%s",students[i].name);
			printf("Enter the student's grade: ");
			scanf("%d",&students[i].grade);
		}
}

int main()
{
	//man
	printf("0. Exit\n");
	printf("1. Enter the number of students\n");
	printf("2. Enter the students name and grades\n");
	printf("3. Display class in alphabetic order\n");
	printf("4. Display class creating a top based on grades\n");
	printf("5. Display the first 3 students according to their grades\n");

	//code :)

	unsigned choose=1;
	unsigned int n;
	while(choose!=0)
	{
		printf("Enter your option: ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1: 
			{
				scanf("%d",&n);
				break;
			}
			case 2:
			{
				read_students(n,students);
				printf("Your students: \n");
				for(int i=0;i<n;i++)
					printf("%s  %d \n",students[i].name,students[i].grade);
				break;
			}
			case 3:
			{
				struct student aux;
				for(int i=0;i<n-1;i++)
					for(int j=i+1;j<n;j++)
						if(strcmp(students[i].name,students[j].name)>0)
								{
								aux=students[i];
								students[i]=students[j];
								students[j]=aux;
							}
				for(int i=0;i<n;i++)
					printf("%s  %d \n",students[i].name,students[i].grade);
				break;
			}
			case 4:
			{
				struct student aux;
				for(int i=0;i<n-1;i++)
					for(int j=i+1;j<n;j++)
						if(students[i].grade<students[j].grade)
							{
								aux=students[i];
								students[i]=students[j];
								students[j]=aux;
							}
				for(int i=0;i<n;i++)
					printf("%s  %d \n",students[i].name,students[i].grade);
				break;
			}
			case 5:
			{
				struct student aux;
				for(int i=0;i<n-1;i++)
					for(int j=i+1;j<n;j++)
						if(students[i].grade<students[j].grade)
							{
								aux=students[i];
								students[i]=students[j];
								students[j]=aux;
							}
				for(int i=0;i<3;i++)
					printf("%s  %d \n",students[i].name,students[i].grade);
				break;
			}
			default:
			{
				if(choose!=0)
					printf("Choose a valid option ! \n");
			}
		}
	}
	return 0;
}