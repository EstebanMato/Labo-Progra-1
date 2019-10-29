#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct{

    int day;
    int month;
    int year;

}eFecha;

typedef struct{

    char nombre[20];
    char equipo[20];
    int edad;
    char sexo;
    int numero;
    int partidos;
    int cantGoles;
    float promedioGol;
    eFecha fechaDebut;

}eJugador;

void mostrarJugador(eJugador vec[], int tam);

int main()
{
    eJugador jugador[TAM] =
    {
        {"Esteban", "River", 25, 'm', 9, 18, 9, 0.5, {22, 12, 1993}},
        {"Ariel", "San lorenzo", 25, 'm', 9, 18, 9, 1.5, {6, 4, 1995}}


    };

    /*
    for(int i=0; i<TAM; i++){
        printf("\nIngrese nombre del jugador: ");
        fflush(stdin);
        gets(jugador[i].nombre);

        printf("\nIngrese nombre del equipo: ");
        fflush(stdin);
        gets(jugador[i].equipo);

        printf("\nIngrese edad: ");
        scanf("%d",&jugador[i].edad);

        printf("\nIngrese sexo: ");
        fflush(stdin);
        scanf("%c",&jugador[i].sexo);

        printf("\nIngrese numero: ");
        scanf("%d",&jugador[i].numero);

        printf("\nIngrese cantidad partidos: ");
        scanf("%d",&jugador[i].partidos);

        printf("\nIngrese cantidad de goles: ");
        scanf("%d",&jugador[i].cantGoles);

        printf("\nIngrese fecha debu: dd/mm/aaaa");
        scanf("%d/%d/%d",&jugador[i].fechaDebut.day,&jugador[i].fechaDebut.month,&jugador[i].fechaDebut.year);

        jugador[i].promedioGol=(float) (jugador[i].cantGoles/jugador[i].partidos);
        */

    mostrarJugador(jugador , TAM);

    return 0;
}

void mostrarJugador(eJugador vec[], int tam){

    printf("Equipo Nombre Edad Sexo Numero Partidos Goles Debut");
    for(int i=0; i<tam; i++){
        printf("\n%10s    %10s   %d   %c     %d     %d  %d %.2f  %02d/%02d/%02d",
        vec[i].equipo,
        vec[i].nombre,
        vec[i].edad,
        vec[i].sexo,
        vec[i].numero,
        vec[i].partidos,
        vec[i].cantGoles,
        vec[i].promedioGol,
        vec[i].fechaDebut.day,
        vec[i].fechaDebut.month,
        vec[i].fechaDebut.year
        );
    }

return;

}
