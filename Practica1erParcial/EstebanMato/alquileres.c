#include "alquileres.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initAlquileres(eAlquileres listaAlq[], int tamA){

    for(int i=0; i<tamA; i++){

        listaAlq[i].codAlquiler = 0;
    }

    return 0;
}

int buscarLibreAlquiler(eAlquileres listaA[], int tamA)
{

    int indice = -1;

    for (int i=0; i< tamA; i++){
        if (listaA[i].codAlquiler == 0){
            indice = i;
            break;
        }
    }

return indice;
}

int altaAlquiler(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eClientes clientes[], int tamC, int idAlquiler, eLocalidad localidades[], int tamLoc)
{
    int todoOk=0;
    int indice;
    int codJuego;
    int codCliente;
    int dia;
    int mes;
    int anio;

    indice = buscarLibreAlquiler(alquileres, tamA);

    system("cls");
    printf("***Alta de alquileres***\n");
    if(indice == -1){
        printf("\nSistema de alquileres completo.");
    }else{

        printJuegos(juegos, tamJ);
        printf("\nIngrese codigo de juego: ");
        fflush(stdin);
        scanf("%d", &codJuego);
        while(!validarCodJuego(juegos,tamJ,codJuego))
        {
            printf("\nERROR. Codigo incorrecto de juego, ingrese nuevamente: ");
            fflush(stdin);
            scanf("%d", &codJuego);
        }
        system("pause");

        listarClientes(clientes, tamC, localidades, tamLoc);
        printf("\nIngrese codigo de cliente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
        while(!validarCodCliente(clientes,tamC,codCliente))
        {
            printf("\nERROR. Codigo incorrecto de cliente, ingrese nuevamente: ");
            fflush(stdin);
            scanf("%d", &codCliente);
        }

        printf("\nIngrese fecha de alquiler: ");
        printf("\nMes(MM): ");
        fflush(stdin);
        scanf("%d", &mes);

        while(mes>12 || mes<1)
        {
            printf("\nERROR. mes incorrecto, ingrese nuevamente el mes(1-12): ");
            fflush(stdin);
            scanf("%d", &mes);
        }

        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("\nDia(DD): ");
            fflush(stdin);
            scanf("%d", &dia);

            while(dia>31 || dia<1)
            {
                printf("\nERROR. dia incorrecto, ingrese nuevamente el dia(1-31): ");
                fflush(stdin);
                scanf("%d", &dia);
            }
            break;

        case 2:
            printf("\nDia(DD): ");
            fflush(stdin);
            scanf("%d", &dia);

            while(dia>28 || dia<1)
            {
                printf("\nERROR. dia incorrecto, ingrese nuevamente el dia(1-28): ");
                fflush(stdin);
                scanf("%d", &dia);
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("\nDia(DD): ");
            fflush(stdin);
            scanf("%d", &dia);

            while(dia>30 || dia<1)
            {
                printf("\nERROR. dia incorrecto, ingrese nuevamente el dia(1-30): ");
                fflush(stdin);
                scanf("%d", &dia);
            }
            break;
        }

        printf("\nAnio(AAAA): ");
        fflush(stdin);
        scanf("%d", &anio);

        while(anio>2018 || anio<2000)
        {
            printf("\nERROR. anio incorrecto, ingrese nuevamente el anio(rango entre 2000 - 2018): ");
            fflush(stdin);
            scanf("%d", &anio);
        }


        todoOk=1;
    }

    if(todoOk){
        alquileres[indice].codAlquiler=idAlquiler;
        alquileres[indice].codJuego=codJuego;
        alquileres[indice].codCliente=codCliente;
        alquileres[indice].fecha.dia=dia;
        alquileres[indice].fecha.mes=mes;
        alquileres[indice].fecha.anio=anio;
        printf("\n\nAlta exitosa!!\n");
    }

return todoOk;
}

void listarAlquileres(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC, eJuego juegos[], int tamJ)
{
    int cliente;
    int juego;
    system("cls");
    printf("***Lista de alquileres***\n\n");
    printf("Cod       Juego         Cliente   Fecha de alquiler ");
    for(int i=0; i<tamA; i++)
    {
        if(alquileres[i].codAlquiler !=0){
            for(int j=0; j<tamC; j++){
                cliente=buscarClientePorId(clientes, tamC, alquileres[i].codCliente);
            }

            for(int j=0; j<tamJ; j++){
                if(alquileres[i].codJuego==juegos[j].codigo){
                juego=j;
                break;
                }
            }
            printf("\n%02d   %10s %15s          %02d/%02d/%d ", alquileres[i].codAlquiler, juegos[juego].descripcion, clientes[cliente].nombre, alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio);
        }
    }
    printf("\n\n");
}



void printJuegos(eJuego juegos[], int tamJ)
{
    printf("\nCod    Descrip Importe");

    for(int i=0; i<tamJ; i++)
    {
        printf("\n%d  %10s   %5d",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe );
    }
printf("\n");
}
