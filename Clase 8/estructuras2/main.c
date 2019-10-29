#include <stdio.h>
#include <stdlib.h>
#define TAM 2
//ESTRUCTURAS:
typedef struct{
int legajo;
int edad;
char nombre[20];
char sexo;
int notaP1;
int notaP2;
float promedio;
}eAlumno;
void mostrar5Alumnos();
void mostrarAlumno(eAlumno al);
int main()
{

    //eAlumno alumno;
    eAlumno lista[TAM];

    for(int i=0;i<TAM;i++){
    printf("Ingrese legajo: ");
    scanf("%d",&lista[i].legajo);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(lista[i].nombre);

    printf("Ingrese edad: ");
    scanf("%d",&lista[i].edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&lista[i].sexo);

    printf("Ingrese nota primer parcial: ");
    scanf("%d",&lista[i].notaP1);

    printf("Ingrese nota segundo parcial: ");
    scanf("%d",&lista[i].notaP2);

    lista[i].promedio=(float)((lista[i].notaP1+lista[i].notaP2)/2);
    }
    mostrar5Alumnos(lista,TAM);
    return 0;
}

void mostrarAlumno(eAlumno al){
printf("     %d        %s      %d    %c      %d       %d       %.2f\n",al.legajo,al.nombre,al.edad,al.sexo,al.notaP1,al.notaP2,al.promedio);
}

void mostrar5Alumnos(eAlumno vec[],int tam){
    printf("Legajo   Nombre   Edad   Sexo   Nota1   Nota2   Promedio\n\n");
    for(int i=0;i<tam;i++){
        mostrarAlumno(vec[i]);
    }

}
