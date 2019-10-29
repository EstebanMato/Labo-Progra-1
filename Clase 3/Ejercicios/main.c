#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b,  int c);
int getInt();
int getInt200500();
int getIntRango(int min, int max);

///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int max;
    int num;
    int num2;
    int numMin = 1;
    int numMax = 10;
    int num3;


        max = getMax( 2, 1, 0);
        num = getInt200500();
        num2 = getIntRango(numMin, numMax);
        num3 = getInt();

        printf("El maximo es: %d \n\n", max);
        printf("El numero es: %d\n\n", num);
        printf("El numero es: %d\n\n", num2);
        printf("El numero es: %d\n\n", num3);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////

int getMax(int a, int b,  int c){
    int max;

    max = a;

         max = a;
         if(max < b){
            max = b;
         }
         if(max < c){
            max = c;
         }

    return max;
}

int getInt200500(){
    int num;

        printf("Ingese numero entre 200 y 500: ");
        scanf("%d", &num);

        while(num < 200 || num > 500){
            printf("Errr. Reingrese numero entre 200 y 500: ");
            scanf("%d", &num);
        }

    return num;
}

int getIntRango(int min, int max){
    int num;

        printf("Ingese numero entre %d y %d: ", min, max);
        scanf("%d", &num);

        while(num < min || num > max){
            printf("Error. Reingese numero entre %d y %d: ", min, max);
            scanf("%d", &num);
        }

    return num;
}

int getInt(){
     int num;

        printf("Ingese numero: ");
        scanf("%d", &num);
        printf("\n");

    return num;
}
