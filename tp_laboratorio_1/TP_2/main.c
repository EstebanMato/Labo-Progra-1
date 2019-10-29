#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleado.h"

#define ELEMENTS 1000



int menu();

void menuInformes (eEmployee empleados[], int tam);
int orderInfo();



int main()
{
    eEmployee lista[ELEMENTS];
    char salir = 'n';
    int id=10000;

    initEmployees(lista, ELEMENTS);

    do{
        switch(menu())
        {
        case 1:
            if(altaEmployee(lista, ELEMENTS, id)){
                id++;
            }
            break;

        case 2:

            if(loadedVector(lista, ELEMENTS)){
                modifyEmployee(lista, ELEMENTS);
            }else{
                printf("\nSe debe cargar primero algun empleado\n");
            }

            break;

        case 3:
            if(loadedVector(lista, ELEMENTS)){
                removeEmployee(lista, ELEMENTS);
            }else{
                printf("\nSe debe cargar primero algun empleado\n");
            }

            break;

        case 4:
             if(loadedVector(lista, ELEMENTS)){
                menuInformes(lista, ELEMENTS);
            }else{
                printf("\nSe debe cargar primero algun empleado\n");
            }

            break;

        case 5:
            printf("\nConfirma la salida del sistema? (s/n): ");
            fflush(stdin);
            scanf("%c",&salir);
            break;

        default:
            printf("\nOPCION INVALIDA");
        }

        printf("\n\n");

        system("pause");
    }while(salir =='n');

return 0;

}

int menu(){

    int opcion;

    system("cls");
    printf("****ABM EMPLEADOS TP2****\n\n");
    printf("** Nomina de empleados **\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Listar empleados\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}



void menuInformes (eEmployee empleados[], int tam)
{
    int option;
    int order=0;
    system("cls");
    printf("***INFORMES***\n\n");
    printf("1-Listado ordenado por Apellido y Sector\n");
    printf("2-Listado total de salarios y promedio\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &option);

    if(option==1){
        order=orderInfo();
    }

    sortEmployees(empleados, tam, option, order);

}

int orderInfo(){

    int order;

    system("cls");
    printf("***INFORMES***\n\n");
    printf("1-Ascendente\n");
    printf("2-Descendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &order);

    return order;
}






