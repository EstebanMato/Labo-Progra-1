#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcion;
    char salir = 'n';
    int flag1 = 0;


    do{
        system("cls");
        printf("-------Menu de opciones-----\n\n");
        printf("a- Sumar\n");
        printf("b- Restar\n");
        printf("c- Multiplicar\n");
        printf("d- Dividir\n");
        printf("e- Salir\n\n");
        printf("Indique opcion: ");
        fflush(stdin);

        opcion=getchar();

        switch(opcion){
            case 'a':
                printf("Usted eligio sumar\n");
                flag1=1;
                system("pause");
                break;

            case 'b':
                if(flag1 == 0){
                    printf("Para restar previamente hubo que haber sumado");
                }else{
                printf("Usted eligio restar\n");
                system("pause");
                break;
                }

            case 'c':
                printf("Usted eligio multiplicar\n");
                system("pause");
                break;

            case 'd':
                printf("Usted eligio dividir\n");
                system("pause");
                break;

            case 'e':
                printf("Confirma salida\n");
                salir = getchar();
                fflush(stdin);
                system("pause");
                break;

            default:
                printf("Opcion invalida\n");
                system("pause");
                break;



        }


    }while(salir == 'n');


    return 0;
}
