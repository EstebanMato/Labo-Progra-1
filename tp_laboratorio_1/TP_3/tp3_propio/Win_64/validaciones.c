#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


int esNumeroEntero (char* vStr)
{
    int i=0;
    int todoOk=1;
    while(vStr[i]!='\0')
    {
        if(vStr[i]<'0' || vStr[i]>'9')
        {
            todoOk= 0;
        }
        i++;
    }
    return todoOk;
}

int getNumber(char* pStr, char* msg, char* msgE)
{
    int todoOk=0;

    printf("\n%s",msg);
    fflush(stdin);
    gets(pStr);

    while(!esNumeroEntero(pStr))
    {
        printf("\n%s",msgE);
        fflush(stdin);
        gets(pStr);
    }
    todoOk=1;

    return todoOk;
}

int findEmployee()
