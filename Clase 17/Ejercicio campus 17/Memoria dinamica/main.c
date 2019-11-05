#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1) Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto
y devuelva un puntero a un espacio de memoria donde esta almacenado el texto ingresado.
Se requiere el uso de memoria dinámica.*/

void* getDynamicString(char* msg);

int main()
{
    char nombre[50];
    char* puntertoQueRetorno;
    printf("Ingrese nombre: \n");
    scanf("%s", nombre);

    puntertoQueRetorno = getDynamicString(nombre);
    printf("\n%p", puntertoQueRetorno);
    printf("\n%s", puntertoQueRetorno);

    return 0;
}

void* getDynamicString(char* msg)
{
    char* punteroAMensaje;
    punteroAMensaje = (char*) malloc(sizeof(char)*(strlen(msg)) );
    if(punteroAMensaje == NULL){
        printf("No hay espacio en memoria");
        EXIT_FAILURE;
    }

    strcpy(punteroAMensaje, msg);
    printf("%s", punteroAMensaje);
    printf("\n%p", punteroAMensaje);
    return punteroAMensaje;
}
