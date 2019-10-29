#include <stdio.h>
#include <stdlib.h>

typedef struct{

int legajo;
char nombre[20];
int edad;
char sexo;
int notaParcial1;
int notaParcial2;
float promedio;

}eAlumno;

void mostrarAlumno(eAlumno alu);
void mostrarAlumnos( eAlumno vec[], int tam);

int main()
{

    printf("\nIngrese el legajo: ");
    scanf("%d", &eAlumno.legajo);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(eAlumno.nombre);

    printf("\nIngrese la edad: ");
    scanf("%d",&eAlumno.edad);

    printf("\nIngrese sexo: ");
    fflush(stdin);
    gets(eAlumno.sexo);

    printf("\nIngrese la nota 1: ");
    scanf("%d",&eAlumno.notaParcial1);

    printf("\nIngrese la nota 2: ");
    scanf("%d",&eAlumno.notaParcial2);

    float eAlumno.promedio=(float) (alu.notaParcial1 + alu.notaParcial2) / 2;


    return 0;
}

void mostrarAlumno(eAlumno alu){

    float promedio=(float) (alu.notaParcial1 + alu.notaParcial2) / 2;

printf("%d %s %d %c %d %d %.2f\n", alu.legajo, alu.nombre, alu.edad, alu.sexo, alu.notaParcial1, alu.notaParcial2, alu.promedio);

}
