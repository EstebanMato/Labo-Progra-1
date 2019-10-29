#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void ordenarVector (int files[], int ages[], char sexs[], int n1[], int n2[], float prom[], int tam);

int main()
{
    int legajos[TAM] = {8, 3, 5, 1, 2};
    int edades[TAM] = {22, 34, 16, 45, 12};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasP1[TAM] = {2, 5, 6, 9, 10};
    int notasP2[TAM] = {4, 4, 2, 10, 8};
    float promedios[TAM] = {3.33, 4.5, 4, 9.5, 9};


    ordenarVector(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    return 0;
}

void ordenarVector (int files[], int ages[], char sexs[], int n1[], int n2[], float prom[], int tam){

    printf("Vector legajos sin ordenar: ");
    for(int i=0; i<tam; i++){
        printf("%d ",files[i]);
    }

    printf("\nVector edades sin ordenar: ");
    for(int i=0; i<tam; i++){
        printf("%d anios ",ages[i]);
    }

    printf("\n\n");
    int aux;
    float auxFloat;
    char auxChar;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(files[i]>files[j]){

                aux = files[i];
                files[i]=files[j];
                files[j]=aux;

                aux = ages[i];
                ages[i]=ages[j];
                ages[j]=aux;

                aux = n1[i];
                n1[i]=n1[j];
                n1[j]=aux;

                aux = n2[i];
                n2[i]=n2[j];
                n2[j]=aux;

                auxFloat = prom[i];
                prom[i]=prom[j];
                prom[j]=auxFloat;

                auxChar=sexs[i];
                sexs[i]=sexs[j];
                sexs[j]=auxChar;

                /*
                strcpy(auxChar,sexs[i]);
                strcpy(sexs[i],sexs[j]);
                strcpy(sexs[j],auxChar);*/

            }
        }
    }

    printf("\nVector legajos ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%d ",files[i]);
    }

    printf("\nVector edades ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%d anios ",ages[i]);
    }

    printf("\nVector nota 1 ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%d ",n1[i]);
    }

    printf("\nVector nota 2 ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%d ",n2[i]);
    }

    printf("\nVector promedio ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%.2f ",prom[i]);
    }

    printf("\nVector sexos ordenado: ");
    for(int i=0; i<tam; i++){
        printf("%c ",sexs[i]);
    }

    printf("\n\n");

    return;
}

