#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20] ="Juan";
    char auxCad[100];

  /*  printf("Ingrese un nombre:");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) > 19){
        printf("Error. Ingrese nombre:");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre,auxCad); */

    strupr(nombre);


    printf(" Nombre\n");
    printf("%s", nombre);

    return 0;
}
