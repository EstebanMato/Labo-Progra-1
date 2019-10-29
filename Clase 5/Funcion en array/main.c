#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt (int vec[] , int tamanio);

int main()
{
    int numero [5];

    for (int i=0; i<5; i++){

        printf("Ingrese un numero: ");
        scanf("%d", &numero[i]);

    }

    mostrarVectorInt(numero,5);
        return 0;

}

void mostrarVectorInt (int vec[], int tamanio){

    for (int i=0; i<tamanio;i++){
        printf("%d ", vec[i]);

    }
    printf("\n\n");
}
