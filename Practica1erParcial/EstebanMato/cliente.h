#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono [51];
    char domicilio[21];
    int idLocalidad;
    int isEmpty;
}eClientes;

typedef struct
{
    int id;
    char nombre[51];
}eLocalidad;


#endif // CLIENTE_H_INCLUDED

/** \brief inicializa el array de clientes
 *
 * \param listaC[] eClientes vector
 * \param tamC int
 * \return int
 *
 */
int initClientes(eClientes listaC[], int tamC);


/** \brief Pide los datos para generar un nuevo cliente, también llama a las funciones que hacen validaciones
 *
 * \param listaC[] eClientes vector
 * \param tamC int
 * \param id int
 * \return int
 *
 */
int altaCliente(eClientes listaC[], int tamC, int id, eLocalidad localidades[], int tamLoc);


/** \brief busca la primer posicion libre del array
 *
 * \param listaC[] eClientes vector
 * \param tamC int
 * \return int int >=0 si encontro una posicion libre, -1 en caso de no haber espacio
 *
 */
int buscarLibre(eClientes listaC[], int tamC);

/** \brief Agrega un empleado al array
 *
 * \param cliente[] eClientes vector
 * \param id int
 * \param nombre[] char
 * \param apellido[] char
 * \param sexo char
 * \param telefono[] char
 * \param domicilio[] char
 * \return int
 *
 */
int addCliente(eClientes cliente[], int indice, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int localidad);

/** \brief llama a "listarCliente" y le va pasando distintas posiciones
 * del array de clientes para que los muestre por pantalla
 *
 * \param clientes[] eClientes vector
 * \param tamC int
 * \return void
 *
 */
void listarClientes(eClientes clientes[], int tamC, eLocalidad localidad[], int tamLoc);

/** \brief muestra un cliente por pantalla
 *
 * \param clientes eClientes
 * \return void
 *
 */
void listarCliente(eClientes clientes, eLocalidad localidad[], int tamLoc);

/** \brief ordena el array de clientes alfabeticamente por nombre y apellido y llama a la
 * funciones necesarias para hacer la impresion por pantalla
 *
 * \param clientes[] eClientes vector
 * \param tamC int
 * \return void
 *
 */
void ordenarClientes(eClientes clientes[], int tamC);

/** \brief busca un cliente ingresando el numero de codigo de cliente
 *
 * \param list[] eClientes
 * \param tam int
 * \param codigo int
 * \return int, el indicie donde se encuentra el cliente en el array
 *
 */
int buscarClientePorId(eClientes list[], int tam, int codigo);

/** \brief solicita un numero de codigo de cliente y permite la modificacion de sus campos
 *
 * \param clientes[] eClientes
 * \param tamC int
 * \return void
 *
 */
void modificarCliente(eClientes clientes[], int tamC, eLocalidad localidades[], int tamLoc);

/** \brief solicita un numero de codigo de cliente y realiza la baja logica del mismo, colocando el campo "isEmpty" en 1
 *
 * \param vec[] eClientes
 * \param tamC int
 * \return int
 *
 */
int bajaCliente(eClientes vec[], int tamC, eLocalidad localidades[], int tamLoc);

/** \brief muestra las localidades por pantalla
 *
 * \param localidades[] eLocalidad
 * \param tamLoc int
 * \return void
 *
 */
void mostrarLocalidades(eLocalidad localidades[], int tamLoc);

/** \brief
 *
 * \param localidad int
 * \param localidad[] eLocalidad
 * \param tamLoc int
 * \return void
 *
 */
void mostrarLocalidad(int localidad, eLocalidad localidades[], int tamLoc);
