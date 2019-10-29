#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char nombreColor[21];
 }eMarca;

 typedef struct{
    int id;
    char nombreColor[21];
 }eColor;

 typedef struct{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
 }eAuto;

 typedef struct{
    int id;
    char descripcion[26];
    int precio;
 }eServicio;

 typedef struct{
    int id;
    int patente;
    int idServicio;
    eFecha fecha;
 }eTrabajo;


int main()
{
    int idMarca = 1000;
    int idColor = 5000;



    return 0;
}
