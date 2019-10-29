#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcion;
    char salir = 'n';
    int flag = 0;


    do{
            system("cls");
        printf("-------  MENU DE OPCIONES  -------\n\n");
        printf("A- Sumar \n");
        printf("B- Restar \n");
        printf("C- Multiplicar \n");
        printf("D- Dividir \n");
        printf("E- Salir \n\n");
        printf("Indique opcion: ");

        fflush(stdin);
        opcion = getchar();
        opcion = tolower(opcion);

        switch(opcion){

            case 'a':
                printf("\nEligio sumar\n\n");
                flag = 1;
                system("pause");
                break;
            case 'b':
                if(flag == 0){
                    printf("para restar antes sumar\n\n");
                }else{
                     printf("\nEligio restar\n\n");
                }

                system("pause");
                break;
            case 'c':
                printf("\nEligio multiplicar\n\n");
                system("pause");
                break;
            case 'd':
                printf("\nEligio dividir\n\n");
                system("pause");
                break;
            case 'e':
                printf("\nConfirma salida?  ");
                fflush(stdin);
                salir = getchar();
                salir = tolower(salir);
                if(salir == 's'){
                    printf("\nSalida correcta\n\n");
                }
                system("pause");
                break;
            default:
                printf("Opcion invalida!!");

        }

    }while(salir == 'n');



    return 0;
}
