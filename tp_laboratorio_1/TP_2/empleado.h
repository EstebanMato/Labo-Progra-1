#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

#endif // EMPLEADO_H_INCLUDED

/** \brief Para inicializar el array de empleados
 *
 * \param list[] eEmployee array de empleados
 * \param tam int
 * \return int
 *
 */
int initEmployees(eEmployee list[], int tam);

/** \brief Agrega un empleado al array
 *
 * \param list[] eEmployee
 * \param tam int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(eEmployee list[], int tam, int id, char name[],char lastName[],float salary,int sector);

/** \brief busca la primer posicion libre en el array
 *
 * \param list[] eEmployee
 * \param tam int
 * \return int >=0 si encontro una posicion libre, -1 en caso de no haber espacio
 *
 */
int buscarLibre(eEmployee list[],int tam);

/** \brief Pide los datos para generar un nuevo empleado, también llama a las funciones que hacen validaciones
 *
 * \param list[] eEmployee
 * \param tam int
 * \param id int
 * \return int
 *
 */
int altaEmployee(eEmployee list[], int tam, int id);

/** \brief muestra un empleados por pantalla
 *
 * \param empleado eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee empleado);

/** \brief llama a "printEmployee" y le va pasando distintas posiciones
 * del array de empleados para que los muestre por pantalla
 *
 * \param list[] eEmployee
 * \param tam int
 * \return void
 *
 */
void printEmployees(eEmployee list[], int tam);

/** \brief busca un empleado ingresando el numero de ID
 *
 * \param list[] eEmployee
 * \param tam int
 * \param id int
 * \return int, el indicie donde se encuentra el empleado en el array
 *
 */
int findEmployeeById(eEmployee list[], int tam, int id);

/** \brief realiza la baja logica de un empleado en el sistema, colocando el campo "isEmpty" en 1
 *
 * \param list[] eEmployee
 * \param tam int
 * \return int
 *
 */
int removeEmployee(eEmployee list[], int tam);

/** \brief pide un numero de id y permite la modificacion de sus campos
 *
 * \param list[] eEmployee
 * \param tam int
 * \return void
 *
 */
void modifyEmployee(eEmployee list[], int tam);

/** \brief ordena el array de empleados segun criterio y llama a la funciones necesarias para hacer la impresion por pantalla
 *
 * \param empleados[] eEmployee
 * \param tam int
 * \param option int
 * \param order int
 * \return int
 *
 */
int sortEmployees(eEmployee empleados[], int tam, int option, int order);

/** \brief valida la cantidad de caracteres de un string
 *
 * \param word[] char
 * \param length int
 * \return int 1 si esta ok, 0 en caso contrario
 *
 */
int validateChar(char word[], int length);

/** \brief recorre el array y valida si hay algun empleado cargado anteriormente o no
 *
 * \param vec[] eEmployee
 * \param tam int
 * \return int 1 si esta cargado, 0 en caso contrario
 *
 */
int loadedVector(eEmployee vec[], int tam);
