#include <stdio.h>
#include <stdlib.h>


int isNumberInt (char* pStr);

int main()
{
    char numero[]={"123"};
    int numero2 = 5;
    numero2 = atoi(numero);
    int retorno;

    retorno = isNumberInt(numero);
    printf("%d",retorno);
    printf("\n\n%d %d", numero2,numero);

    return 0;
}

int isNumberInt (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
