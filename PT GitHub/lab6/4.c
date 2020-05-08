#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    double (*functions[])(double) = {sin, cos, ceil, floor, fabs, log, sqrt};
    char func[][10]={"sin", "cos", "ceil", "floor", "fabs", "log", "sqrt"};
    int op;
    do{
     printf("Enter your option (0=sin, 1=cos, 2=ceil, 3=floor, 4=fabs, 5=log, 6=sqrt, 9=exit): ");
     float nr;
     scanf(" %d", &op);
     printf("Enter the number: \n");
     scanf(" %f", &nr);
     printf("Executing %s(%f)...\n Result: %f \n", func[op], nr, functions[op](nr));
    }while(op<=6 && op>=0);
    return 0;
}