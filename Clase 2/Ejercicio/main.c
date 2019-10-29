#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*
pedir nombre mientras que el usuario quiera
nota 0-10
sexo f-m
mientras que el usuario quiera

promedio de notas totales
promedio de notas mujeres
nombre sex nota max
nombre sex nota min
*/
int main()
{

    int nota;
    int acumuladorNotas = 0;
    int contadorNotas = 0;
    int acumuladorMujer = 0;
    int contadorMujer = 0;
    int flag = 0;
    int notaMax;
    int notaMin;


    float promedio;

    char nombre [20];
    char nombreMax[20];
    char nombreMin[20];

    char sexo;
    char sexoMax;
    char sexoMin;
    char seguir;



    do
    {

        //pedimos los datos y validamos
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(sexo != 'f' && sexo != 'm')
        {
            printf("ERROR. Ingrese sexo valido: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        printf("Ingrese la nota: ");
        fflush(stdin);
        scanf("%d",&nota);

        while(nota <0 || nota>10)
        {
            printf("ERROR. Ingrese la nota valida: ");
            fflush(stdin);
            scanf("%d",&nota);
        }

        //obtenemos promedio total de notas
        acumuladorNotas += nota;
        contadorNotas++;

        if(sexo == 'f'){
            acumuladorMujer +=nota;
            contadorMujer++;
        }

        if(nota>notaMax || flag == 0){
            notaMax = nota;

        }






        printf("%c %d",sexo,nota);

        printf("\nDesea continuar? :");
        fflush(stdin);
        scanf("%c", &seguir);
    }while(seguir == 's');

    return 0;
}
