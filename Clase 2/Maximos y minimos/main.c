#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*
    Pedir: Nombre, Nota (0-10), sexo.
    Mostrar: Promedio de notas totales, promedio  totales de muejres,
            mostrar nota maxima y minima con nombre y sexo.
*/

int main()
{
    float promedio;
    float promedioF;
    int nota;
    int notaMax;
    int notaMin;
    int acumulador = 0;
    int contador = 0;
    int flag = 0;
    int contadorF = 0;
    int acumuladorF = 0;
    char continuar;
    char nombre[20];
    char nombreMax[20];
    char nombreMin[20];
    char sexo;
    char sexoMax;
    char sexoMin;

    do{
            printf("\n Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("\n Ingrese Sexo: ");
            fflush(stdin);
            //scanf("%c", &sexo);
            sexo = getchar();
            sexo = tolower(sexo);

                while(sexo != 'f' && sexo != 'm'){
                    printf("Error. Reingrese : ");
                    fflush(stdin);
                    //scanf("%c", &sexo);
                    sexo = getchar();
                    sexo = tolower(sexo);
                }

            printf("\n Ingrese nota del 0 a 10: ");
            scanf("%d", &nota);

                while(nota < 0 || nota >10){
                    printf("Error. Reingrese nota: ");
                    scanf("%d", &nota);
                }


            if( nota > notaMax || flag == 0 ){
                notaMax = nota;
                strcpy(nombreMax, nombre);
                sexoMax = sexo;
            }

            if( nota < notaMin || flag == 0 ){
                notaMin = nota;
                strcpy(nombreMin, nombre);
                sexoMin = sexo;
                flag = 1;
            }

            contador++;
            acumulador += nota;

            if(sexo == 'f'){
                contadorF++;
                acumuladorF += nota;
            }


        printf("\n\n Continuar? ");
        fflush(stdin);
        scanf("%c", &continuar);

        continuar = tolower(continuar);

        system("cls");
    }while(continuar == 's');


        promedio = (float) acumulador / contador;

    if(contadorF != 0){
        promedioF = (float) acumuladorF / contadorF;
    }

    printf("\n\n");
    printf("  ***********************************************\n");
    printf("  *El promedio total es: %.2f                   *\n", promedio);
    printf("  *El promedio de mujeres es: %.2f              *\n", promedioF);
    printf("  *La nota maxima es: %d, nombre: %s, Sexo : %c *\n", notaMax, nombreMax, sexoMax);
    printf("  *La nota minima es: %d, nombre: %s, Sexo : %c *\n", notaMin, nombreMin, sexoMin);
    printf("  ***********************************************\n");

system("pause");

    return 0;
}
