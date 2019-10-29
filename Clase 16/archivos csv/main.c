#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float sueldo;
}eEmpleado;

eEmpleado* new_Empleado();

int main()
{
    // esto es un array que adentro guarda punteros, direcciones de memmoria que referencian a los empleados creados por malloc
    // que estan en la memoria dinamica
    eEmpleado* lista[50];
    eEmpleado* emple;

    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[10];
    int i=0;

    FILE* miArchivo;
    miArchivo=fopen("datos.csv", "r");
    fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n],", legajo, nombre, apellido, sueldo);

    while(!feof(miArchivo)){
        emple=new_Empleado();
        fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n],", legajo, nombre, apellido, sueldo);
        emple->legajo = atoi(legajo);
        emple->sueldo = atof(sueldo);
        strcpy(emple->nombre, nombre);
        strcpy(emple->apellido, apellido);

        *(lista+i)= emple;
        i++;
    }

    fclose(miArchivo);

    for(int i=0; i<50; i++){
        printf("%d--%s--%s--%2f\n", lista[i]->legajo, lista[i]->nombre, lista[i]->apellido, lista[i]->sueldo);
    }


    return 0;
}

eEmpleado* new_Empleado()
{
    eEmpleado* e;

    e= (eEmpleado*) malloc(sizeof(eEmpleado));

    return e;
}
