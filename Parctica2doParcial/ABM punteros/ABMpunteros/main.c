#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a;
    int* b;
    int c;

    c=15; // Asignamos el valor 15 a la variable 'b'
    a=&c; // Obtenemos la posición de memoria de 'b' con el operador '&'
    b=a; // Copiamos el contenido apuntado por el puntero 'a'
    a=a+1;
    a=a-1;

    printf("Valor de a:%d, valor de b:%d, valor de c:%d",*a,*b,c);

    char cadena[20]="Esteban Mato";
    char* p;
    p=cadena;

    printf("\n%s",cadena);
    printf("\n%c",cadena[5]);
    printf("\n%c", *(p+11));
    printf("\n%p",p-1);

    int* punt[10];
    int var=221293;

    punt[2]= &var;

    printf("\n%d", *punt[2]);
    printf("**----\n");

    printf("%d", sizeof(c));

    return 0;
}
