#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "empleado.h"


int initEmployees(eEmployee list[], int tam){

    for(int i=0; i<tam; i++){

        list[i].isEmpty = 1;
    }

    return 0;
}

int altaEmployee(eEmployee list[], int tam, int id){

    int todoOk=0;
    int indice;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    indice = buscarLibre(list, tam);


    system("cls");
    printf("***Alta de empleado***\n\n");
    if(indice == -1){
        printf("\nSistema de empleados completo.");
    }else{

        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(name);

         while( !validateChar(name, 50)){
            printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el nombre: ");
            fflush(stdin);
            gets(name);
        }

        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(lastName);

        while( !validateChar(lastName, 50)){
            printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el apellido: ");
            fflush(stdin);
            gets(lastName);
        }

        printf("\nIngrese el salario: ");
        scanf("%f", &salary);

        printf("\nIngrese el sector: ");
        scanf("%d", &sector);

        list[indice].id=id;

        todoOk=addEmployee(list, tam, indice, name, lastName, salary, sector);
        if( todoOk ){
            printf("\n\nAlta exitosa!!");
        }
    }
return todoOk;
}

int buscarLibre(eEmployee list[], int tam){

    int indice = -1;

    for (int i=0; i< tam; i++){
        if (list[i].isEmpty == 1){
            indice = i;
            break;
        }
    }

return indice;
}

int addEmployee(eEmployee list[], int tam, int id, char name[],char lastName[],float salary,int sector){

    strcpy(list[id].name , name);
    strcpy(list[id].lastName, lastName);
    list[id].salary=salary;
    list[id].sector=sector;
    list[id].isEmpty=0;

    return 1;
}

void printEmployee(eEmployee empleado)
{
    printf("\n%d  %10s  %10s  %10.3f  %7d", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);

}

void printEmployees( eEmployee list[], int tam)
{

    system("cls");
    printf("***Lista de empleados***\n\n");
    printf("Id         Nombre    Apellido     Salario   Sector");

    for(int i=0; i<tam; i++){
        if(list[i].isEmpty == 0){
            printEmployee(list[i]);
        }
    }
}

int findEmployeeById(eEmployee list[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++){

        if(list[i].id==id && list[i].isEmpty == 0){
            indice = i;
        }
    }
    return indice;
}

int removeEmployee(eEmployee list[], int tam)
{
    int flag=0;
    char borrar;
    int idEmployee;
    int indiceEmployee;

    system("cls");
    printf("***Baja de empleado***\n");
    printf("\nIngrese el id de empleado: ");
    scanf("%d",&idEmployee);
    indiceEmployee = findEmployeeById(list, tam, idEmployee);

    if( indiceEmployee==-1 ){

        printf("\nNo existe empleado con numero de id ingresado");

    }else{

        printEmployee(list[indiceEmployee]);
        printf("\n\nConfirma la baja del empleado? (s/n): ");
        fflush(stdin);
        scanf("%c", &borrar);

        if(borrar=='s'){
            list[indiceEmployee].isEmpty=1;
            flag=1;
            printf("\nBaja exitosa!!\n");
        }else{
            printf("\nLa operacion se ha cancelado\n");
        }
    }

return flag;
}

void modifyEmployee(eEmployee list[], int tam)
{

    int option;
    int id;
    int indice;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");
    printf("***Modificar empleado***\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    indice = findEmployeeById(list, tam, id);

    if(indice==-1){
        printf("\nNo existe empleado con ese numero de id\n");
    }else{
        printEmployee(list[indice]);
        printf("\n\nQue desea modificar?");
        printf("\n1-Nombre");
        printf("\n2-Apellido");
        printf("\n3-Salario");
        printf("\n4-Sector");

        printf("\n\nIngrese opcion: ");
        scanf("%d", &option);

        switch(option){

        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(name);

            while( !validateChar(name, 50)){
                printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el apellido: ");
                fflush(stdin);
                gets(name);
            }

            strcpy(list[indice].name, name);
            printf("\nModificacion exitosa!!");
            break;

        case 2:
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(lastName);

            while( !validateChar(lastName, 50)){
                printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el apellido: ");
                fflush(stdin);
                gets(lastName);
            }

            strcpy(list[indice].lastName, lastName);
            printf("\nModificacion exitosa!!");
            break;

        case 3:
            printf("Ingrese el nuevo salario: ");
            scanf("%f", &salary);
            list[indice].salary=salary;
            printf("\nModificacion exitosa!!");
            break;

        case 4:
            printf("Ingrese el nuevo sector: ");
            scanf("%d", &sector);
            list[indice].sector=sector;
            printf("\nModificacion exitosa!!");
            break;

        default:
            printf("Opcion incorrecta");
        }
    }
}

int sortEmployees(eEmployee empleados[], int tam, int option, int order)
{
    eEmployee auxArr;

    int counter=0;
    float accumulator=0;
    int cantEmployees=0;
    float average=0;

    switch(option)
    {

    case 1:

        if(order == 1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(strcmp(empleados[i].lastName, empleados[j].lastName)>0){
                        auxArr =empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxArr;
                    }

                    if( empleados[i].sector>empleados[j].sector ){
                        auxArr =empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxArr;
                    }
                }
            }
        }else{

             for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(strcmp(empleados[i].lastName, empleados[j].lastName)<0){
                        auxArr =empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxArr;
                    }

                    if( empleados[i].sector>empleados[j].sector ){
                        auxArr =empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxArr;
                    }
                }
            }
        }
        printEmployees(empleados, tam);

        break;

    case 2:

        for(int i=0; i<tam; i++){
            if(empleados[i].isEmpty==0){
                counter ++;
                accumulator = accumulator + empleados[i].salary;
            }
        }

        system("cls");
        printf("**Sueldo promedio**\n\n");
        printf("El total de los salarios es %.3f\n", accumulator);
        average= (float) accumulator / counter;
        printf("El promedio es de %.3f\n", average);

        printf("\nLos empleados que superan el sueldo promedio son: \n");

        for(int i=0; i<tam; i++){
            if(empleados[i].salary>=average && empleados[i].isEmpty==0){
                printEmployee(empleados[i]);
                cantEmployees ++;
            }
        }

        printf("\nTotal: %d", cantEmployees);

        break;

    default:
        printf("\nOpcion incorrecta.");
    }



return 0;
}

int validateChar(char word[], int length)
{
    int todoOk=0;

    if(strlen(word)<=length){
        todoOk=1;
    }
return todoOk;
}

int loadedVector(eEmployee vec[], int tam)
{
    int loaded=0;

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty==0){
            loaded=1;
            break;
        }
    }
    return loaded;
}
