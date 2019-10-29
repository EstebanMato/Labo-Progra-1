#include <stdio.h>
#include <stdlib.h>

void suma (int *resultado);

int main()
{
    int * p;
    int resultado = 0;
    p=&resultado;

    printf("%d \n",resultado);


    suma(p);

    printf("%d \n",resultado);
    system("pause");
    return 0;
}

void suma (int *resultado)
{
    *resultado=18;
}
