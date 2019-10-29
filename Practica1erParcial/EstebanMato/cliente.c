#include "cliente.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initClientes(eClientes listaC[], int tamC){

    for(int i=0; i<tamC; i++){

        listaC[i].isEmpty = 1;
    }

    return 0;
}

int altaCliente(eClientes listaC[], int tamC, int id, eLocalidad localidades[], int tamLoc)
{
    int todoOk=0;
    int indice;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[21];
    int localidad;

    indice = buscarLibre(listaC, tamC);

    system("cls");
    printf("***Alta de clientes***\n\n");
    if(indice == -1){
        printf("\nSistema de clientes completo.");
    }else{
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(nombre);

        while( !validateChar(nombre, 50)){
            printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el nombre: ");
            fflush(stdin);
            gets(nombre);
        }


        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(apellido);

        while( !validateChar(apellido, 50)){
            printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el apellido: ");
            fflush(stdin);
            gets(apellido);
        }


        printf("\nIngrese el sexo(m/f): ");
        fflush(stdin);
        sexo=getchar();

        while (!validateSex(sexo)){
            printf("ERROR formato invalido. Reingrese el sexo (m/f): ");
            fflush(stdin);
            sexo=getchar();
        }


        printf("\nIngrese el telefono: ");
        fflush(stdin);
        gets(telefono);

        while( !validateChar(telefono, 20)){
            printf("ERROR supera cantidad de caracteres maximos(20).\n\nReingrese el telefono: ");
            fflush(stdin);
            gets(telefono);
        }


        printf("\nIngrese el domicilio: ");
        fflush(stdin);
        gets(domicilio);

        while( !validateChar(domicilio, 20)){
            printf("ERROR supera cantidad de caracteres maximos(20).\n\nReingrese el domicilio: ");
            fflush(stdin);
            gets(domicilio);
        }

        mostrarLocalidades(localidades, tamLoc);
        printf("\nIngrese el id de localidad: ");
        fflush(stdin);
        scanf("%d", &localidad);

        while(localidad>5 || localidad<=0){
            printf("ERROR localidad incorrecta.\n\nReingrese la localidad: ");
            fflush(stdin);
            scanf("%d", &localidad);
        }

        listaC[indice].codigo=id;



        todoOk= addCliente(listaC, indice, nombre, apellido, sexo, telefono, domicilio, localidad);

        if(todoOk){
            printf("\nAlta exitosa!!\n");
        }
    }

    return todoOk;
}

int buscarLibre(eClientes listaC[], int tamC)
{

    int indice = -1;

    for (int i=0; i< tamC; i++){
        if (listaC[i].isEmpty == 1){
            indice = i;
            break;
        }
    }

return indice;
}

int addCliente(eClientes cliente[], int indice, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int localidad)
{
    strcpy(cliente[indice].nombre , nombre);
    strcpy(cliente[indice].apellido, apellido);
    cliente[indice].sexo = sexo;
    strcpy(cliente[indice].telefono, telefono);
    strcpy(cliente[indice].domicilio, domicilio);
    cliente[indice].idLocalidad=localidad;
    cliente[indice].isEmpty=0;

    return 1;
}

void listarClientes(eClientes clientes[], int tamC, eLocalidad localidad[], int tamLoc)
{
    system("cls");
    printf("***Lista de clientes***\n\n");
    printf("Codigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad\n");

    for(int i=0; i<tamC; i++){
        if(clientes[i].isEmpty == 0){
            listarCliente(clientes[i], localidad, tamLoc);
        }
    }

    printf("\n\n");
}

void listarCliente(eClientes clientes, eLocalidad localidad[], int tamLoc)
{
    printf("\n%d   %10s %10s  %c  %15s   %20s ", clientes.codigo, clientes.nombre, clientes.apellido, clientes.sexo, clientes.telefono, clientes.domicilio);

    mostrarLocalidad(clientes.idLocalidad, localidad, tamLoc);
}

void ordenarClientes(eClientes clientes[], int tamC)
{
    eClientes auxArr;
    for(int i=0; i<tamC-1; i++)
    {
        for(int j=i+1; j<tamC; j++)
        {
            if(strcmp(clientes[i].apellido, clientes[j].apellido)>0)
            {
                auxArr =clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=auxArr;
            }else{
                if(strcmp(clientes[i].apellido, clientes[j].apellido)==0){
                    if(strcmp(clientes[i].nombre, clientes[j].nombre)>0){
                        auxArr =clientes[i];
                        clientes[i]=clientes[j];
                        clientes[j]=auxArr;
                    }
                }

            }
        }
    }
}

void modificarCliente(eClientes clientes[], int tamC, eLocalidad localidades[], int tamLoc)
{
    int option;
    int codigo;
    int indice;
    char nombre[51];
    char telefono [21];
    char domicilio [51];

    system("cls");
    printf("***Modificar cliente***\n\n");
    listarClientes(clientes, tamC, localidades, tamLoc);
    printf("Ingrese codigo cliente: ");
    fflush(stdin);
    scanf("%d", &codigo);
    printf("\nCodigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad");
    indice = buscarClientePorId(clientes, tamC, codigo);

    if(indice == -1){
        printf("\nNo existe empleado con ese numero de id\n");
    }else{

        listarCliente(clientes[indice], localidades, tamLoc);
        printf("\n\nQue desea modificar?");
        printf("\n1-Nombre");
        printf("\n2-Domicilio");
        printf("\n3-Telefono");
        printf("\n5-Salir");

        printf("\n\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("\nIngrese el nuevo nombre: ");
            fflush(stdin);
            gets(nombre);

            while( !validateChar(nombre, 50)){
                printf("ERROR supera cantidad de caracteres maximos(50).\n\nReingrese el nombre: ");
                fflush(stdin);
                gets(nombre);
            }
            strcpy(clientes[indice].nombre, nombre);
            printf("\nModificacion exitosa!!\n");
            break;

        case 2:
            printf("\nIngrese el nuevo domicilio: ");
            fflush(stdin);
            gets(domicilio);

            while( !validateChar(domicilio, 20)){
                printf("ERROR supera cantidad de caracteres maximos(20).\n\nReingrese el domicilio: ");
                fflush(stdin);
                gets(domicilio);
            }
            strcpy(clientes[indice].domicilio, domicilio);
            printf("\nModificacion exitosa!!\n");
            break;

        case 3:
            printf("\nIngrese el nuevo telefono: ");
            fflush(stdin);
            gets(telefono);

            while( !validateChar(telefono, 20)){
                printf("ERROR supera cantidad de caracteres maximos(20).\n\nReingrese el telefono: ");
                fflush(stdin);
                gets(telefono);
            }
            strcpy(clientes[indice].telefono, telefono);
            printf("\nModificacion exitosa!!\n");
            break;

        case 5:
            printf("\nSe ha cancelado la modificacion\n");
            break;

        default:
            printf("\nOPCION INVALIDA\n");
            break;
        }
    }

}

int buscarClientePorId(eClientes list[], int tam, int codigo)
{
    int indice=-1;

    for(int i=0; i<tam; i++){

        if(list[i].codigo==codigo && list[i].isEmpty == 0){
            indice = i;
        }
    }
    return indice;
}

int bajaCliente(eClientes vec[], int tamC, eLocalidad localidades[], int tamLoc)
{
    int todoOk = 0;
    int codigo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Cliente *****\n\n");
    listarClientes(vec, tamC, localidades, tamLoc);
    printf("Ingrese codigo de cliente: ");
    fflush(stdin);
    scanf("%d", &codigo);

    indice = buscarClientePorId(vec, tamC, codigo);

    if( indice == -1)
    {
        printf("No existe un cliente con ese numero de codigo\n\n");

    }
    else
    {
        printf("\nCodigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad");
        listarCliente(vec[indice], localidades, tamLoc);

        printf("\n\nConfirma la baja? (s/n): ");
        fflush(stdin);
        confirma=getchar();

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("\nBaja exitosa!!!\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n");
        }
    }
    return todoOk;
}

void mostrarLocalidades(eLocalidad localidades[], int tamLoc)
{
    printf("\nLocalidades");
    for(int i=0; i<tamLoc; i++){
        printf("\n%d %s",localidades[i].id, localidades[i].nombre);
    }
}

void mostrarLocalidad(int localidad, eLocalidad localidades[], int tamLoc)
{
     for(int i=0; i<tamLoc; i++){
                if(localidad==localidades[i].id){
                    printf("  %18s", localidades[i].nombre);
                }
            }
}

