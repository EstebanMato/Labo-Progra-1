#include "cliente.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[51];
    int importe;
    int idCategoria;
}eJuego;

typedef struct
{
    int id;
    char descrpcion [51];
}eCategoria;


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
    //int isEmpty;
}eAlquileres;

#endif // ALQUILERES_H_INCLUDED

/** \brief pide los datos para generar un nuevo alquiler y realiza la llamada a las funciones que realizan las validaciones
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param clientes[] eClientes
 * \param tamC int
 * \param idAlquiler int
 * \return int
 *
 */
int altaAlquiler(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eClientes clientes[], int tamC, int idAlquiler, eLocalidad localidades[], int tamLoc);

/** \brief busca la primer posicion libre del array
 *
 * \param listaA[] eAlquileres
 * \param tamA int
 * \return int >=0 si encontro una posicion libre, -1 en caso de no haber espacio
 *
 */
int buscarLibreAlquiler(eAlquileres listaA[], int tamA);

/** \brief inicializa el array de alquileres poniendo el campo "codAlquiler" en 0
 *
 * \param listaAlq[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int initAlquileres(eAlquileres listaAlq[], int tamA);

/** \brief lista los alquileres en pantalla
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return void
 *
 */
void listarAlquileres(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC, eJuego juegos[], int tamJ);

/** \brief muestra los juegos por pantalla
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \return void
 *
 */
void printJuegos(eJuego juegos[], int tamJ);
