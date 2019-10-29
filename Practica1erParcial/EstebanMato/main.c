#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"
#include "alquileres.h"

#define CLIENTES 100
#define ALQUILERES 100
#define JUEGOS 20
#define CATEGORIAS 5
#define LOCALIDADES 5



//funciones clientes

int hardcodearClientes(eClientes vec[], int tamC, int cantidad);
int hardcodearAlquileres(eAlquileres vec[], int tamA, int cantidad);


//funciones informes
void menuInformes(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat, eClientes clientes[], int tamC, eLocalidad localidaes[], int tamLoc);
void listarJuegosCatMesa(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);
void listarAlquileresCliente(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC, eLocalidad localidades[],int tamLoc, eJuego juegos[], int tamJ);
void totalImportesCliente(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eLocalidad localidades[], int tamLoc);
void listadoNoAlquila(eClientes clientes[], int tamC, eAlquileres alquileres[], int tamA,  eLocalidad localidades[], int tamLoc);
void listaJuegoNoAlquilado(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat);

//nuevos informes
void listaJuegoPorClienteDeterminado(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquiler[], int tamA, eLocalidad localidades[], int tamLoc);
void listaJuegoMujeres(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquiler[], int tamA, eLocalidad localidades[], int tamLoc);
void mostrarClientesPorLocalidad(eClientes clientes[], int tamC, eLocalidad localidades[], int tamLoc);
void listarJuegos(eJuego juegos[], int tamJ);

int main()
{
    eJuego listaJ[]=
    {
        {10, "TEG",       200, 3},
        {11, "Brujas",    250, 5},
        {12, "Clue",      350, 1},
        {13, "Poker",     500, 2},
        {14, "Pelotero", 1500, 4},
        {15, "Mago nego", 250, 5},
        {16, "Monopoly",  200, 1},
        {17, "Truco",     350, 2},
        {18, "MilMillas", 500, 3},
        {19, "Tobogan",  1500, 4},
        {20, "Ajedrez",   200, 3},
        {21, "Clue Sim",  350, 1},
        {22, "BlackJack", 500, 2},
        {23, "Hamaca",   1500, 4},
        {24, "Magia",     250, 5},
        {25, "Estanciero",200, 1},
        {26, "Chinchon",  350, 2},
        {27, "Damas",     500, 3},
        {28, "Columpio", 1500, 4},
        {29, "Hechizo",   250, 5},
    };

    eCategoria listaCat[]=
    {
        {1,"mesa"},
        {2,"azar"},
        {3,"estrategia"},
        {4,"salon"},
        {5,"magia"},
    };

    eLocalidad listaLoc[]=
    {
        {1, "Buenos Aires"},
        {2, "Avellaneda"},
        {3, "San Telmo"},
        {4, "Berazategui"},
        {5, "Parque patricios"},
    };



    eClientes listaC[CLIENTES];
    initClientes(listaC,CLIENTES);

    eAlquileres listaAlq[ALQUILERES];
    initAlquileres(listaAlq, ALQUILERES);



    int idCliente=1001;
    int idCodigoAlquiler=1;
    int option;
    char salir='n';
    char salirTot='n';

    idCodigoAlquiler+= hardcodearAlquileres(listaAlq, ALQUILERES, 20);
    idCliente+= hardcodearClientes(listaC, CLIENTES, 10);

    do{
        system("cls");
        printf("***ABM***\n\n");
        printf("1- Clientes\n");
        printf("2- Alquileres\n");
        printf("3- Informes\n");
        printf("5- Salir\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            do{
                system("cls");
                printf("***MENU CLIENTES***\n\n");
                printf("1- Alta\n");
                printf("2- Modificar\n");
                printf("3- Baja\n");
                printf("4- Listar\n");
                printf("5- Salir\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                scanf("%d", &option);

                switch(option)
                {
                case 1:
                        if(altaCliente(listaC, CLIENTES, idCliente, listaLoc, LOCALIDADES)){
                            idCliente++;
                        }

                    break;

                case 2:
                    if(loadedVector(listaC, CLIENTES)){
                        modificarCliente(listaC, CLIENTES, listaLoc, LOCALIDADES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 3:
                    if(loadedVector(listaC, CLIENTES)){
                        bajaCliente(listaC, CLIENTES, listaLoc, LOCALIDADES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 4:
                    if(loadedVector(listaC, CLIENTES)){
                        ordenarClientes(listaC, CLIENTES);
                        listarClientes(listaC, CLIENTES, listaLoc, LOCALIDADES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 5:
                    printf("\nConfirma la salida del menu? (s/n): ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;

                default:
                    printf("\n\nOPCION INVALIDA\n");
                    break;

                }

                system("pause");
            }while(salir == 'n');
        break;

        case 2:
            do{
                system("cls");
                printf("***MENU ALQUILERES***\n\n");
                printf("1- Alta\n");
                printf("2- Listar\n");
                printf("5- Salir\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                scanf("%d", &option);

                switch(option)
                {
                case 1:
                    if(altaAlquiler(listaAlq, ALQUILERES, listaJ, JUEGOS, listaC, CLIENTES, idCodigoAlquiler, listaLoc, LOCALIDADES)){
                        idCodigoAlquiler++;
                    }
                    break;

                case 2:
                    listarAlquileres(listaAlq, ALQUILERES, listaC, CLIENTES, listaJ, JUEGOS);
                    break;

                case 5:
                    printf("\nConfirma la salida del menu? (s/n): ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;

                default:
                    printf("\n\nOPCION INVALIDA\n");
                    break;

                }

                system("pause");
            }while(salir == 'n');
            break;

        case 3:
            menuInformes(listaJ, JUEGOS, listaAlq, ALQUILERES, listaCat, CATEGORIAS, listaC, CLIENTES, listaLoc, LOCALIDADES);
            break;


        case 5:
            printf("\nConfirma la salida del sistema? (s/n): ");
            fflush(stdin);
            scanf("%c",&salirTot);
            break;

        default:
            printf("\n\nOPCION INVALIDA");
            break;
        }

        printf("\n\n");
        system("pause");

    }while(salirTot == 'n');

    return 0;
}


int hardcodearClientes( eClientes vec[], int tamC, int cantidad)
{
    int cont = 0;

    eClientes suplentes[]=
    {
        {1001, "Esteban", "Mato",      'm', "1154770922", "peru 1225",2,0},
        {1002, "Alberto", "Rodriguez", 'm', "1198543265", "bolivar 432",2,0},
        {1003, "Ana", "Luaccino",      'f', "1178453288", "chacabuco 2352",3,0},
        {1004, "Luis", "Veliz",        'm', "1199874566", "defensa 234",4,0},
        {1005, "Alicia", "Mendoza",    'f', "1133648795", "humberto primo 756",5,0},
        {1006, "Diego", "Aaron",       'm', "1154701269", "san juan 541",2,0},
        {1007, "Sofia", "Zotela",      'f', "1197535412", "cochabamba 12357",2,0},
        {1008, "Clara", "Abbe",        'f', "1199755003", "paseo colon 2348",3,0},
        {1009, "Maria", "Mas",        'f', "1103694107", "uspallate 3160",4,0},
        {1010, "Ricardo", "Gimenez",   'm', "1198736812", "piedras 9865",5,0},
    };

    if( cantidad <= 10 && tamC >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

int hardcodearAlquileres(eAlquileres vec[], int tamA, int cantidad)
{
    int cont = 0;

    eAlquileres suplentes[]=
    {
        {1, 10, 1001, {22, 12, 2000}},
        {2, 11, 1002, {16, 2, 2001}},
        {3, 12, 1004, {14, 3, 2002}},
        {4, 13, 1005, {2, 6, 2001}},
        {5, 14, 1001, {1, 9, 2006}},
        {6, 15, 1008, {28, 2, 2000}},
        {7, 16, 1009, {30, 4, 2015}},
        {8, 17, 1001, {13, 11, 2000}},
        {9, 18, 1002, {9, 10, 2018}},
        {10, 19, 1004, {8, 8, 2004}},
        {11, 11, 1005, {27, 5, 2006}},
        {12, 12, 1005, {11, 1, 2017}},
        {13, 13, 1008, {3, 7, 2003}},
        {14, 14, 1009, {21, 9, 2005}},
        {15, 15, 1002, {12, 11, 2018}},
        {16, 16, 1003, {7, 3, 2009}},
        {17, 17, 1004, {3, 6, 2008}},
        {18, 18, 1008, {31, 12, 2013}},
        {19, 19, 1008, {19, 9, 2001}},
        {20, 20, 1002, {1, 8, 2002}},
    };

    if( cantidad <= 20 && tamA >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

void menuInformes(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat, eClientes clientes[], int tamC, eLocalidad localidades[], int tamLoc)
{
    int option;
    char salir='n';

    do{
        system("cls");
        printf("***MENU INFORMES***\n\n");
        printf("1- Mostrar juegos categoria mesa\n");
        printf("2- Mostrar alquileres por cliente seleccionado\n");
        printf("3- Mostar total de importe pagado por cliente seleccionado\n");
        printf("4- Listado clientes que no alquilaron juegos\n");
        printf("5- Listado de juegos no alquilados\n");
        printf("6- Clientes de una determinada localidad\n");
        printf("7- Listado de juegos por mujeres\n");
        printf("8- Listado clientes por determinado juego\n");
        printf("90- Salir\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            listarJuegosCatMesa(juegos, tamJ, categorias, tamC);
            break;

        case 2:
            listarAlquileresCliente(alquileres, tamA, clientes, tamC, localidades, tamLoc, juegos, tamJ);
            break;

        case 3:
            totalImportesCliente(clientes, tamC, juegos, tamJ, alquileres, tamA, localidades, tamLoc);
            break;

        case 4:
            listadoNoAlquila(clientes, tamC, alquileres, tamA, localidades, tamLoc);
            break;

        case 5:
            listaJuegoNoAlquilado(juegos, tamJ, alquileres, tamA, categorias, tamCat);
            break;

        case 6:
            mostrarClientesPorLocalidad(clientes, tamC, localidades, tamLoc);
            break;

        case 7:
            listaJuegoMujeres(clientes, tamC, juegos, tamJ, alquileres, tamA, localidades, tamLoc);
            break;

        case 8:
            listaJuegoPorClienteDeterminado(clientes, tamC, juegos, tamJ, alquileres, tamA, localidades, tamLoc);
            break;

        case 90:
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\n\nOPCION INVALIDA");
                break;
        }

        printf("\n\n");
        system("pause");
    }while(salir == 'n');

}

void listarJuegosCatMesa(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    printf("\nCod         Descrip    Importe  Categoria");
    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria == 1)
        {
            printf("\n%d  %15s      %5d       %s",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe, categorias[juegos[i].idCategoria-1].descrpcion );
        }
    }
}

void listarAlquileresCliente(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC, eLocalidad localidades[],int tamLoc, eJuego juegos[],int tamJ)
{

    int codCliente;
    int flag=-1;
    char desJuego[20];

    listarClientes(clientes, tamC, localidades, tamLoc);

    printf("\nIngrese codigo de cliente: ");
    fflush(stdin);
    scanf("%d", &codCliente);

    while(!validarCodCliente(clientes, tamC, codCliente))
    {
        printf("\nERROR. No existe el codigo de empleado ingresado, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
    }

    printf("\n\nCod Alq        Juego   Cliente     Fecha de alquiler ");

    for(int i=0; i<tamA; i++)
    {
        if(codCliente==alquileres[i].codCliente)
        {
            for(int j=0; j<tamJ; j++)
            {
                if(alquileres[i].codJuego==juegos[j].codigo)
                {
                    strcpy(desJuego, juegos[i].descripcion);
                }
            }
            printf("\n%02d        %10s      %4d            %02d/%02d/%d ", alquileres[i].codAlquiler, desJuego, alquileres[i].codCliente, alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio);
            flag=1;
        }
    }

    if(flag==-1){
        printf("\n\nNo hay alquileres realizados por este cliente");
    }
}

void totalImportesCliente(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eLocalidad localidades[], int tamLoc)
{
    int totalImportes=0;
    int codCliente;

    listarClientes(clientes, tamC, localidades, tamLoc);

    printf("\nIngrese codigo de cliente: ");
    fflush(stdin);
    scanf("%d", &codCliente);

    while(!validarCodCliente(clientes, tamC, codCliente))
    {
        printf("\nERROR. No existe el codigo de empleado ingresado, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
    }

    for(int i=0; i<tamA; i++)
    {
        if(codCliente==alquileres[i].codCliente)
        {
            for(int j=0; j<tamJ; j++)
            {
                if(alquileres[i].codJuego==juegos[j].codigo)
                {
                    totalImportes += juegos[j].importe;
                }
            }
        }
    }

    printf("\nEl total de los importes pagados por el cliente es: $%d", totalImportes);
}

void listadoNoAlquila(eClientes clientes[], int tamC, eAlquileres alquileres[], int tamA, eLocalidad localidades[], int tamLoc)
{
    int flag=2;
    int contador=0;

    printf("\nLos clientes que no alquilaron ningun juego son: \n\n");
    printf("Codigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad");
    for (int i=0; i<tamC; i++)
    {
        flag=0;
        for(int j=0; j<tamA; j++)
        {
            if(clientes[i].codigo==alquileres[j].codCliente){
                flag=1;
                break;
            }
        }
        if(!flag && clientes[i].isEmpty==0)
        {

            listarCliente(clientes[i], localidades, LOCALIDADES);
            contador++;
        }
    }

    if(!contador){
        printf("\nNo hay clientes que no hayan alquilado al menos un juego\n");
    }
}

void listaJuegoNoAlquilado(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat)
{
    int flag;
    int contador=0;

    printf("\nLos juegos que no se alquilaron son: \n");
    printf("\nCod    Descrip Importe Categoria");
    for (int i=0; i<tamJ; i++)
    {
        flag=0;
        for(int j=0; j<tamA; j++)
        {
            if(juegos[i].codigo==alquileres[j].codJuego){
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            printf("\n%d  %10s   %5d %s",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe, categorias[juegos[i].idCategoria-1].descrpcion );
            contador++;
        }
    }

    if(!contador){
        printf("\nNo hay juegos que no hayan sido alquilados\n");
    }
}

void mostrarClientesPorLocalidad(eClientes clientes[], int tamC, eLocalidad localidades[], int tamLoc)
{
    int flag=0;
    mostrarLocalidades(localidades, tamLoc);
    int localidad;
    printf("\n\nIngrese el id de localidad: ");
    fflush(stdin);
    scanf("%d", &localidad);

    while(localidad>5 || localidad<=0){
        printf("ERROR localidad incorrecta.\n\nReingrese la localidad: ");
        fflush(stdin);
        scanf("%d", &localidad);
    }
    printf("\nCodigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad");
    for(int i=0; i<tamC; i++)
    {
        if(clientes[i].idLocalidad==localidad && clientes[i].isEmpty==0){
            listarCliente(clientes[i], localidades, tamLoc);
            flag=1;
        }

    }

    if(flag==0){
        printf("\nNo hay clientes para la localidad ingresada");
    }
}

void listaJuegoMujeres(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquiler[], int tamA, eLocalidad localidades[], int tamLoc)
{
    printf("\nCodigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad    Nombre juego");
    for(int i=0; i<tamA; i++)
    {
        for(int j=0; j<tamC; j++)
        {
            if(alquiler[i].codCliente==clientes[j].codigo)
            {
                if(clientes[j].sexo=='f')
                {

                   for(int k=0; k<tamJ; k++)
                   {
                       if(alquiler[i].codJuego==juegos[k].codigo)
                       {


                           listarCliente(clientes[j], localidades, tamLoc);
                           printf(" %15s",juegos[k].descripcion);
                       }
                   }
                }
            }
        }
    }
}

void listaJuegoPorClienteDeterminado(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquiler[], int tamA, eLocalidad localidades[], int tamLoc)
{
    listarJuegos(juegos, tamJ);

    int idJuego;
    int flag=0;
    printf("\nIngrese el id de juego: ");
    fflush(stdin);
    scanf("%d", &idJuego);

    while(idJuego>29 || idJuego<10){
        printf("ERROR id de juego incorrecto.\n\nReingrese el id: ");
        fflush(stdin);
        scanf("%d", &idJuego);
    }

    printf("\nCodigo     Nombre   Apellido  Sexo      Telefono              Domicilio            Localidad");
    for(int i=0; i<tamA; i++)
    {
        if(alquiler[i].codJuego==idJuego)
        {
            for(int j=0; j<tamC; j++)
            {
                if(alquiler[i].codCliente==clientes[j].codigo)
                {
                    listarCliente(clientes[j], localidades, tamLoc);
                    flag=1;
                }
            }
        }
    }

    if(!flag){
        printf("\nNo hay clientes que alquilaran este juego");
    }

}

void listarJuegos(eJuego juegos[], int tamJ)
{
    printf("\nId Descripcion\n");
    for(int i=0; i<tamJ; i++)
    {
       printf("%d %s\n",juegos[i].codigo, juegos[i].descripcion);
    }
}

