#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include "carrera.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

typedef struct
{

    int id;
    char descripcion[20];
    float precio;

} eComida;

typedef struct
{

    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;

} eAlmuerzo;


// Funciones Carrera

int menuInformes();
int menu();
void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAl);
void mostrarAlumnosCarrera( eAlumno alumnos[],                      int tam,
                            eCarrera carreras[],
                            int tamC,
                            int idCarrera);
void mostrarAlumnosCarreraSeleccionada( eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC
                                      );
void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[],
                                      int tam,
                                      eCarrera carreras[],
                                      int tamC);
int contarAlumnosCarrera(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC,
                         int idCarrera);
void mostrarCantidadDeAlumnosPorCarrera(eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC);

void carreraMasInscriptos(eAlumno alumnos[],
                          int tam,
                          eCarrera carreras[],
                          int tamC);

// Prototipos Comida
void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comida);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);

// Prototipos Almuerzos
void inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamC);
void mostrarAlmuerzos(eAlmuerzo vec[],int tam, eComida comidas[], int tamC);
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam);
int altaAlmuerzo( eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eComida comidas[], int tComida, eAlumno alumnos[], int tAlumno, eCarrera carreras[], int tCarrera);
eAlmuerzo newAlmuerzo(int id,int legajo,int idComida, eFecha fecha);

//NUEVOS
void carreraMilanesa(eAlmuerzo almuerzos[], int tamAl,
                          eCarrera carreras[], int tamC,
                          eAlumno alumnos[], int tamA);

int cantidadComidasPorCarrera(eAlmuerzo almuerzos[], int tamAl,
                          int idCarrera,
                          eAlumno alumnos[], int tamA,
                          int idComida);

// Informes pendientes
void mejorPromedioCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void alumnosVarones(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM]= {{5000, "Bife", 250},
        {5001, "Fideos", 200},
        {5002, "Pizza", 190},
        {5003, "Arroz", 200},
        {5004, "Milanesa", 220}
    };
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzos( almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 10);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            mostrarInformes(lista, TAM, carreras, TAMC, almuerzos, TAMAL);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;

        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 10:
            if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, comidas, TAMCOM, lista, TAM, carreras, TAMC))
            {
                idAlmuerzo++;
            }
            break;


        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzo\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes *******\n\n");
    printf(" 1-Mostrar Alumnos de una Carrera\n");
    printf(" 2-Mostrar Alumnos por Carrera\n");
    printf(" 3-Mostrar Cantidad de alumnos por Carrera\n");
    printf(" 4-Mostrar La Carrera con mas inscriptos\n");
    printf(" 5-Mostrar Mejor Promedio por Carrera\n");
    printf(" 6-Mostrar Alumnos Varones\n");
    printf(" 7-Mostrar Mujeres de Alguna Carrera\n");
    printf(" 8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf(" 9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una determinada comida\n");
    printf("11-Listar cantidad de almuerzos x carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[],
                     int tamC, eAlmuerzo almuerzos[], int tamAl)
{


    char salir = 'n';

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosCarreraSeleccionada(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosDeTodasLasCarreras(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadDeAlumnosPorCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            carreraMasInscriptos(alumnos, tam, carreras, tamC);
            break;

        case 5:
            mejorPromedioCarrera(alumnos, tam, carreras, tamC);
            break;

        case 6:
            alumnosVarones(alumnos, tam, carreras, tamC);
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 8\n");
            break;

        case 10:
            printf("Informe 10\n");
            break;

        case 11:
            printf("Informe 11\n");
            break;

        case 12:

            carreraMilanesa(almuerzos, TAMAL, carreras, TAMC, alumnos, TAM);
            break;

        case 13:
            printf("Informe 13\n");
            break;

        case 20:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}

void mostrarAlumnosCarrera( eAlumno alumnos[],
                            int tam,
                            eCarrera carreras[],
                            int tamC,
                            int idCarrera)
{
    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
    printf("\n\n");
}

void mostrarAlumnosCarreraSeleccionada( eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC
                                      )
{
    int idCarrera;
    system("cls");
    printf("**** Mostrar Alumnos de una Carrera ******\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[],
                                      int tam,
                                      eCarrera carreras[],
                                      int tamC)
{
    //int idCarrera;
    char desc[20];
    system("cls");
    printf("*** Mostrar Alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s\n\n", desc);
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);

    }
}

void mostrarCantidadDeAlumnosPorCarrera(eAlumno alumnos[],
                                        int tam,
                                        eCarrera carreras[],
                                        int tamC)
{
    //int idCarrera;
    char desc[20];
    int cantidad;
    system("cls");
    printf("*** Mostrar Cantidad de alumnos de todas las Carreras***\n\n");
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s: ", desc);
        cantidad = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
        printf(" %d\n\n",cantidad);
    }
}

int contarAlumnosCarrera(eAlumno alumnos[],
                         int tam,
                         eCarrera carreras[],
                         int tamC,
                         int idCarrera)
{
    int cantidad = 0;

    for(int i=0; i < tam; i++)
    {

        if( alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void carreraMasInscriptos(eAlumno alumnos[],
                          int tam,
                          eCarrera carreras[],
                          int tamC)
{
    int inscriptos[tamC];
    int mayor;
    int flag = 0;
    //int idCarrera;
    //char desc[20];
    //int cantidad;
    system("cls");
    printf("*** Carrera mas cursada ***\n\n");
    for(int i=0; i < tamC; i++)
    {
        inscriptos[i] = contarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    for(int i=0; i < tamC; i++)
    {
        if( mayor < inscriptos[i]|| flag == 0)
        {
            mayor = inscriptos[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamC; i++)
    {
        if( inscriptos[i] == mayor)
        {
            printf(" %s \n", carreras[i].descripcion );
        }
    }

    printf("cantidad incriptos %d\n\n", mayor);


}

void mostrarComidas(eComida comidas[], int tam)
{
    printf(" Id   Descripcion      Precio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida(eComida comida)
{

    printf("  %d      %10s     %3.2f\n", comida.id, comida.descripcion, comida.precio);

}

int cargarDescComida(int id, eComida comidas[], int tam, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == comidas[i].id)
        {
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


void inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20000, 5004, {1, 10, 2019}, 0},
        { 60001, 20001, 5002, {1, 10, 2019}, 0},
        { 60002, 20005, 5002, {1, 10, 2019}, 0},
        { 60003, 20003, 5004, {1, 10, 2019}, 0},
        { 60004, 20004, 5001, {2, 10, 2019}, 0},
        { 60005, 20001, 5000, {2, 10, 2019}, 0},
        { 60006, 20002, 5002, {2, 10, 2019}, 0},
        { 60007, 20004, 5004, {2, 10, 2019}, 0},
        { 60008, 20003, 5000, {3, 10, 2019}, 0},
        { 60009, 20009, 5004, {3, 10, 2019}, 0},

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamC)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tamC, descComida);
    printf("  %d    %10s   %d  %02d/%02d/%d\n",
           x.id,
           descComida,
           x.legajo,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC)
{

    int flag = 0;
    system("cls");

    printf(" Id       Comida      Legajo    Fecha \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlmuerzo( eAlmuerzo almuerzos[], int tAlmuerzo,int idAlmuerzo, eComida comidas[],int tComida, eAlumno alumnos[],int tAlumno, eCarrera carreras[],int tCarrera)
{
    int todoOk = 0;
    int indice;
    int idComida;
    int legajo;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarAlmuerzoLibre(almuerzos, tAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tAlumno, carreras, tCarrera);
        printf("Ingrese legajo alumno: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tComida);
        printf("Ingrese id comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha : ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);



        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta Almuerzo exitosa!!\n\n");
    }
    return todoOk;
}

eAlmuerzo newAlmuerzo(int id,int legajo,int idComida, eFecha fecha)
{
    eAlmuerzo al;
    al.id = id;
    al.legajo = legajo;
    al.idComida = idComida;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

int compararFechas( eFecha f1, eFecha f2){
    int sonIguales = 0;

    if( f1.anio == f2.anio && f1.dia == f2.dia && f1.mes == f2.mes){
        sonIguales = 1;
    }
    return sonIguales;

}

void mejorPromedioCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int flag=0;
    int mayor;
    int j=0;
    int indiceMayor;

    for(int i=0; i<tamC; i++){
        for(int j=0; j<tam; j++){
            if(alumnos[j].idCarrera==carreras[i].id){
                if(mayor < alumnos[j].promedio || flag==0){
                    mayor=alumnos[j].promedio;
                    flag=1;
                    indiceMayor=j;
                }
            }
        }
        mostrarCarrera(carreras[i]);
        mostrarAlumno(alumnos[indiceMayor],carreras,tamC);
        flag=0;

    }

}

void alumnosVarones(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    for(int i=0; i<tam; i++){
        if(alumnos[i].sexo == 'm'){
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
}

void carreraMilanesa(eAlmuerzo almuerzos[], int tamAl,
                          eCarrera carreras[], int tamC,
                          eAlumno alumnos[], int tamA)
{
    int numero=0;
    int milaComida [tamC];
    int idComida= 5004;

    for(int i=0; i<tamC; i++){
        milaComida[i]=cantidadComidasPorCarrera(almuerzos, tamAl, carreras[i].id, alumnos, tamA, idComida);
        printf("\nCantidad de milanesas (%d) %d \n\n",carreras[i].id, milaComida[i]);

    }

    /*int idCarrera=1000;

    numero = cantidadComidasPorCarrera(almuerzos, tamAl, idCarrera,
                                       alumnos, tamA, 5004);
    printf("\nCantidad de milanesas TUP(1001) %d \n\n", numero);*/

}

int cantidadComidasPorCarrera(eAlmuerzo almuerzos[], int tamAl,
                          int idCarrera,
                          eAlumno alumnos[], int tamA,
                          int idComida)
{
    int contador=0;



        for(int j=0; j<tamAl; j++){
            if(almuerzos[j].idComida==idComida){
                for(int k=0; k<tamA; k++){
                    if(almuerzos[j].legajo==alumnos[k].legajo){
                        if(alumnos[k].idCarrera==idCarrera){
                            contador++;
                        }
                    }
                }
            }
        }

return contador;
}
