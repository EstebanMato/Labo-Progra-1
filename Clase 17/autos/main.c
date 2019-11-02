#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[32];
    int modelo;
    float precio;
}eAuto;

//mostrar autos
int mostrarAutos(eAuto** autos, int tam);
int mostrarAuto(eAuto* unAuto);

//getters y setters
int setIdAuto(eAuto* unAuto, int id);
int getIdAuto(eAuto* unAuto);
int setMarcaAuto(eAuto* unAuto, char* marca);
int getMarcaAuto(eAuto* unAuto, char* marca);
int setModeloAuto(eAuto* unAuto, int modelo);
int getModeloAuto(eAuto* unAuto);
int setPrecioAuto(eAuto* unAuto, float precio);
float getPrecioAuto(eAuto* unAuto);
//contructores
eAuto* new_Auto();
eAuto* new_AutoParam(int id, char* marca, int modelo, float precio);
//comparison

// escritura/lectura archivos
int guardarAutosBinario(eAuto** lista, int tam, char* path);
int guardarAutosCSV(eAuto** lista, int tam, char* path);


int main()
{
    int tam=0;
    int cant=0;
    //ver para que es el buffer
    char buffer[4][30];
    /*buena practica a NULL, aca vamos a cargar el csv de autos*/
    FILE* f = NULL;

    /* buena practica inicializar en NULL cada puntero*/
    eAuto* auxAuto = NULL;
    /*este aux es para el realloc*/
    eAuto** auxLista=NULL;

    /*creamos el primer puntero, que apunta a otro puntero, y pedimos un primer lugar donde
    vamos a poner la direccion de memoria de un auto. Despues con realloc vamos a ir
    sumandole mas punteros al array que apuntan a diferentes autos*/
    eAuto ** lista = (eAuto**) malloc(sizeof(eAuto*));

    if(lista == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    //Lo abrimos para leer el archivo
    f = fopen("autos.csv", "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(f))
    {
        /*fscanf devuelve la cantidad de elementos que pudo cargar, si devuelve 4 esta ok.
        lo almacenamos en cant*/
        cant = fscanf(f, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant <4)
        {
            break;
        }
        else
        {
            //atoi parsea a int un string, atof parsea a float un string
            auxAuto = new_AutoParam(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
            /*si pudimos cargar el auto creamos el vector de punteros*/
            if(auxAuto != NULL)
            {
                /*el contenido de auxAuto lo copiamos al array de punteros donde apunta lista */
                *(lista + tam)=auxAuto;
                tam++;
                /*tam + 1 es porque tam= la cantidad de elementos y tam+1=es el proximo espacio libre
                ya preparado*/
                auxLista=(eAuto**) realloc(lista, sizeof(eAuto*) *(tam+1));

                if(auxAuto!=NULL)
                {
                    lista=auxLista;
                }
            }
        }
    }
    /*despues de leerlo cerramos el archivo*/
    fclose(f);

    mostrarAutos(lista, tam);

    //************** GUARDAMOS EN ARCHIVO BINARIO ******************

    if(guardarAutosBinario(lista, tam, "autos.bin"))
    {
        printf("Autos guardados con exitos\n");
    }
    else
    {
        printf("No se pudieron guardar los autos\n");
    }
    // leemos el archivo binario

    int tam2=0;
    eAuto ** lista2 = (eAuto**) malloc(sizeof(eAuto*));
    if(lista2 == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


    //Lo abrimos para leer el archivo
    f = fopen("autos.bin", "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    while(!feof(f))
    {
        //conseguimos el espacio en memorio, guardamos el puntero en auxAuto
        auxAuto=new_Auto();
        if(auxAuto==NULL){
            break;
        }
        //hacemos la lectura y la vamos guardando en la dir de memorio que apunta auxAuto
        cant = fread( auxAuto ,sizeof(eAuto),1, f);
        if(cant <1)
        {
            break;
        }
        else
        {
            /*el contenido de auxAuto lo copiamos al array de punteros donde apunta lista */
            *(lista2 + tam2)=auxAuto;
            tam2++;
            /*tam + 1 es porque tam= la cantidad de elementos y tam+1=es el proximo espacio libre
            ya preparado*/
            auxLista=(eAuto**) realloc(lista2, sizeof(eAuto*) *(tam2+1));

            if(auxAuto!=NULL)
            {
                lista2=auxLista;
            }

        }
    }
    /*despues de leerlo cerramos el archivo*/
    fclose(f);

    mostrarAutos(lista2, tam2);

    if(guardarAutosCSV(lista2, tam2, "listaAutos.csv"))
    {
        printf("Autos guardados con exitos\n");
    }
    else
    {
        printf("No se pudieron guardar los autos\n");
    }


    return 0;
}

int setIdAuto(eAuto* unAuto, int id)
{
    int todoOk=0;
    if(unAuto != NULL && id >=1000 && id<=2000)
    {
        unAuto->id=id;
        todoOk=1;
    }
    return todoOk;
}

int getIdAuto(eAuto* unAuto)
{
    int id=-1;
    if(unAuto != NULL)
    {
        id=unAuto->id;
    }
    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if(unAuto != NULL && marca != NULL && strlen(marca) >= 3)
    {
        strcpy(unAuto->marca , marca);
        todoOk=1;
    }
    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if(unAuto != NULL && marca != NULL)
    {
        strcpy(marca, unAuto->marca);
        todoOk=1;
    }
    return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int todoOk=0;
    if(unAuto != NULL && modelo >=1900 && modelo<=2019)
    {
        unAuto->modelo=modelo;
        todoOk=1;
    }
    return todoOk;
}

int getModeloAuto(eAuto* unAuto)
{
    int modelo=-1;
    if(unAuto != NULL)
    {
        modelo= unAuto->modelo;
    }
    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int todoOk=0;
    //se podria validar que no sean letras
    if(unAuto != NULL && precio >0)
    {
        unAuto->precio=precio;
        todoOk=1;
    }
    return todoOk;
}

float getPrecioAuto(eAuto* unAuto)
{
    float precio=-1;
    //se podria validar que no sean letras
    if(unAuto != NULL && precio >0)
    {
        precio = unAuto->precio;
    }
    return precio;
}

//esta funcion se utiliza para designar el espacio en memoria para el nuevo auto y obtener el puntero
//
eAuto* new_Auto()
{
    eAuto* nuevo;

    nuevo= (eAuto*) malloc(sizeof(eAuto));
    if( nuevo != NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->marca, " ");
        nuevo->modelo=0;
        nuevo->precio=0.0;
    }
    return nuevo;
}

eAuto* new_AutoParam(int id, char* marca, int modelo, float precio)
{
    eAuto* nuevo;

    nuevo= new_Auto();
    if( nuevo != NULL)
    {
        if(setIdAuto(nuevo, id) &&
           setMarcaAuto(nuevo, marca)&&
           setModeloAuto( nuevo, modelo) &&
           setPrecioAuto( nuevo, precio) == 0)
        {
            free(nuevo);//liberamos ese espacio en memoria porque fallo la carga
            nuevo=NULL;
        }
    }
    return nuevo;
}

int mostrarAuto(eAuto* unAuto)
{
    int todoOk=0;
    if(unAuto!= NULL)
    {
        printf("\n%d %20s %d %6.2f");
        todoOk=1;
    }
    return todoOk;
}

//le pasamos el puntero a punteros que guarda la dir de memoria a la estructura auto.
//Osea recibe directamente el array de punteros
int mostrarAutos(eAuto** autos, int tam)
{
    printf("\nId    Marca    Modelo    Precio");
    int todoOk=0;

    if(autos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarAuto(*(autos+i));
        }
        todoOk=1;
    }

    return todoOk;
}

int guardarAutosBinario(eAuto** lista, int tam, char* path)
{
    int todoOk=0;
    FILE *f=NULL;

    if(lista != NULL && tam>0 && path !=NULL)
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            //nunca un exit dentro de una funcion!!
            return todoOk;
        }

        for(int i=0; i<tam; i++)
        {
            fwrite(*(lista+i),sizeof(eAuto),1,f);
        }

        fclose(f);
        todoOk=1;
    }
    return todoOk;
}

int guardarAutosCSV(eAuto** lista, int tam, char* path)
{
    int todoOk=0;
    FILE *f=NULL;

    if(lista != NULL && tam>0 && path !=NULL)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            //nunca un exit dentro de una funcion!!
            return todoOk;
        }

        fprintf(f, "id,marca,model,precio\n");

        for(int i=0; i<tam; i++)
        {
            fprintf(f, "%d,%s,%d,%.2f\n", (*(lista+i))->id, (*(lista+i))->marca, (*(lista+i))->modelo, (*(lista+i))->precio);
        }

        fclose(f);
        todoOk=1;
    }
    return todoOk;
}


