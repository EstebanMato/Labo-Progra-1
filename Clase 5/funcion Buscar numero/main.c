#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int vec[], int tamanio, int numero);

int main()
{
    int numeros[] = {22,35,45,12,0,9,18,78,1,10};
    int esta;

    esta = buscarNumeroVector(numeros,10,9);

    if (esta){
        printf("Esta\n");
    }else{
        printf("No esta\n");
    }

    return 0;
}

int buscarNumeroVector(int vec[],int tamanio, int numero){
    int esta = 0;
    for (int i=0; i<tamanio; i++){

        if (numero == vec[i]){
            esta =1;
        break;

        }
    }
return esta;
}
