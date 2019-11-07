#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char salir = 'n';

    if(listaEmpleados!=NULL)
    {
        do{
            switch(menu())
            {
                case 1:
                    if(!flag)
                    {
                        if(controller_loadFromText("data.csv",listaEmpleados))
                        {
                            flag=1;
                            printf("\nArchivo cargado correctamente.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo cargar el archivo correctamente.\n");
                        }
                    }
                    else
                    {
                        printf("\nYa se cargo el archivo.\n");
                    }
                    break;

                case 2:
                    if(!flag)
                    {
                        if(controller_loadFromBinary("data.bin",listaEmpleados))
                        {
                            flag=1;
                            printf("\nArchivo cargado correctamente.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo cargar el archivo correctamente.\n");
                        }
                    }else
                    {
                        printf("\nYa se cargo el archivo.\n");
                    }
                    break;

                case 3:
                    controller_addEmployee(listaEmpleados);
                    break;

                case 6:
                    controller_ListEmployee(listaEmpleados);
                    break;

                case 9:
                    if(flag)
                    {
                        controller_saveAsBinary("data.bin" , listaEmpleados);
                        printf("\nSe genero el archivo binario(.bin) correctamente.\n");
                    }else
                    {
                        printf("\nDebe cargarse un archivo primeramente.\n");
                    }

                    break;

                case 10:
                    printf("\nConfirma la salida del sistema? (s/n): ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;

                default:
                    printf("\nOPCION INVALIDA\n");

            }
        system("pause");
        }while(salir == 'n');
    }
    else
    {
        printf("\nERROR. No se consiguio espacio en memoria para el LinkedList");
    }
    return 0;
}
