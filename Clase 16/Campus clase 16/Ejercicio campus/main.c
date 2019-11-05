#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
    int dni;
}ePersona;

int loadPerson(struct S_Person* pPerson);
void printPerson(struct S_Person* pPerson);

int main()
{

    if(loadPerson(persona1))
    {
        printPerson(persona1);
    }


    return 0;
}
