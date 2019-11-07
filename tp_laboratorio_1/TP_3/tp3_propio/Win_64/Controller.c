#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile , pArrayListEmployee))
            {
                fclose(pFile);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile , pArrayListEmployee))
            {
                fclose(pFile);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int repetido=0;//flag para validar Id duplicado
    char id[20];
    char nombre[128];
    char horasTrabajadas[20];
    char sueldo[20];
    Employee* auxEmployee;
    system("cls");
    printf("**ALTA DE EMPLEADO**\n");

    if(pArrayListEmployee != NULL)
    {//obetenemos el id
        do{
            repetido=0;
            if(getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: "))
            {
                if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
                {
                    for (int i=0; i<ll_len(pArrayListEmployee); i++)
                    {
                        auxEmployee = ll_get(pArrayListEmployee, i);

                        if(auxEmployee != NULL)
                        {
                            if(auxEmployee->id==atoi(id))
                            {
                                repetido=1;
                                printf("\nNumero de Id existente.\n");
                            }
                        }
                    }
                }
            }
        }while(repetido);
        //obtenemos el nombre

        getString(nombre,"Ingrese el nombre: ", "ERROR. Nombre invalido, reingrese el nombre: ");
        getNumber(horasTrabajadas,"Ingrese las horas trabajadas: ", "ERROR. Numero invalido, reingrese las horas trabajadas: ");
        getNumber(sueldo,"Ingrese el sueldo: ", "ERROR. Numero invalido, reingrese el sueldo: ");

        auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

        if(auxEmployee != NULL)
        {
            if(ll_add(pArrayListEmployee,auxEmployee) == 0)
            {
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* nEmployee;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
        printf("\n  ID          Nombre Horas  Sueldo \n");

        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            nEmployee = ll_get(pArrayListEmployee, i);

            if(nEmployee != NULL)
            {
                printf ("%4d %15s  %4d  %6d\n", nEmployee->id, nEmployee->nombre, nEmployee->horasTrabajadas, nEmployee->sueldo);
            }
        }

        todoOk=1;
    }
    else
    {
        printf("\nNo hay empleados que mostrar.\n");
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int tam;
    Employee* auxEmpleado;
    FILE* pFile=NULL;



    if(path !=NULL && pArrayListEmployee != NULL)
    {
       tam=ll_len(pArrayListEmployee);
       pFile=fopen(path,"wb");

       if(pFile!=NULL && tam >0)
        {
            for(int i=0; i<tam ; i++)
            {
                auxEmpleado=ll_get(pArrayListEmployee,i);
                //fwrite(pE,sizeof(Employee),1,fp);

                fwrite( auxEmpleado,  sizeof(Employee), 1, pFile);

            }

            fclose(pFile);
            todoOk=1;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo.");
        }

    }
    return todoOk;
}

