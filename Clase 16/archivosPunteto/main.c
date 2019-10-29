#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
}eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);

int main()
{
    escribirBinario("miEmpleado.dat");
    leerBinario("miEmpleado.dat");
    return 0;
}

void escribirBinario(char* path)
{
    int len=2;
    eEmpleado miEmpleado [2] = {{100, "Ezequiel",1000}, {101,"Esteban", 1200}};
    FILE* miArchivo;

    miArchivo=fopen(path,"wb");

    if(miArchivo == NULL)
    {
        printf("ERROR al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fwrite(&len, sizeof(int), 1, miArchivo);

    for(int i=0; i<len ;i++){
        fwrite(miEmpleado+i, sizeof(eEmpleado), 1, miArchivo);
    }
    fclose(miArchivo);

}

void leerBinario(char* path)
{
    int len;
    eEmpleado miEmpleado[2];
    FILE* miArchivo;

    miArchivo = fopen(path, "rb");


    if(miArchivo!=NULL){
        fread(&len, sizeof(int), 1, miArchivo);
        printf("%d\n",len);
        fread(miEmpleado, sizeof(eEmpleado), len, miArchivo);

        for(int i=0;i<len; i++){
            printf("%d %s %f\n",miEmpleado[i].legajo, miEmpleado[i].nombre, miEmpleado[i].salario);
        }
    }

}
