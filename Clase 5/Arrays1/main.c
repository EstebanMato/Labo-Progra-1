#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero [5];// vector llamado numero del tipo int de tamaño 5
    int total=0;
    int numMax;
    int position;
    int flag=0;



    for (int i=0; i<5; i++){

        printf("Ingrese un numero: ");
        scanf("%d", &numero[i]);

        if(numero[i]>numMax || flag==0){
            numMax= numero[i];
            position = i;
            flag=1;
       }
    }

    for (int i=0;i<5;i++){
        printf("%d " , numero[i]);
    }

    for (int i=0;i<5;i++){
        total += numero[i];
    }

    for(int i=0;i<5;i++){
        if(numMax==numero[i])
        printf("El numero maximo es %d y su posicion es %d",numero[i],i);
    }
    printf("\nLa suma total de lo numeros es %d, el numero maximo es %d, y esta en la posicion %d del array", total, numMax,position);


    return 0;
}
