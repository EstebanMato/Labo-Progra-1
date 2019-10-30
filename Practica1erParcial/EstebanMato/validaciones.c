#include "validaciones.h"
#include <stdlib.h>
#include <string.h>

int validateChar(char word[], int length)
{
    int todoOk=0;

    if(strlen(word)<=length){
        todoOk=1;
    }
return todoOk;
}

int validateSex(char sexo)
{
    int ok=0;
    if(sexo == 'm' || sexo == 'f')
    {
        ok=1;
    }
    return ok;
}


int loadedVector(eClientes vec[], int tamC)
{
    int loaded=0;

    for(int i=0; i<tamC; i++){
        if(vec[i].isEmpty==0){
            loaded=1;
            break;
        }
    }
    return loaded;
}

int validarCodJuego(eJuego juego[], int tamJ, int codigo)
{
    int encontro = 0;
    for(int i=0; i<tamJ; i++)
    {
        if(juego[i].codigo == codigo)
        {
            encontro =1;
            break;
        }
    }
    return encontro;
}

int validarCodCliente(eClientes cliente[], int tamC, int codigo)
{
    int encontro = 0;
    for(int i=0; i<tamC; i++)
    {
        if(cliente[i].codigo== codigo &&cliente[i].isEmpty==0)
        {
            encontro =1;
            break;
        }
    }
    return encontro;
}

int validarLocalidad(eLocalidad localidades[], int tamLoc, int id)
{
    int encontro =0;
    for(int i=0; i<tamLoc; i++)
    {
        if(localidades[i].id==id)
        {
            encontro=1;
            break;
        }
    }
    return encontro;
}
