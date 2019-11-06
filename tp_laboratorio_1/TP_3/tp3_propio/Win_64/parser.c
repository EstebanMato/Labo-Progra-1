#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char buffer[4][1000];
    Employee *nEmpleado=NULL;
    int cantidad;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cantidad<4)
            {
                break;
            }

            nEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(nEmpleado != NULL)
            {
                if(ll_add(pArrayListEmployee,nEmpleado))
                {
                    todoOk = 1;
                }
            }

        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* nEmpleado;
    int cantidad;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            nEmpleado = employee_new();

            if(nEmpleado == NULL)
            {
                break;
            }

            cantidadDatos = fread(nEmpleado, sizeof(Employee), 1, pFile);

            if(cantidadDatos < 1)
            {
                break;
            }

            if(ll_add(pArrayListEmployee, pEmpleado))
            {
                todoOk=0;
            }
            else
            {
                employee_delete(pEmpleado); // si no obtengo la línea de datos que esperaba, borro el espacio que separé
            }
        }
    }

    return retorno;
    return 1;
}
