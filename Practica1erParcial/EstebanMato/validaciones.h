#include "alquileres.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida la cantidad de caracteres ingresados
 *
 * \param word[] char
 * \param length int, cantidad maxima de caracteres
 * \return int, si esta todo ok retorna 1
 *
 */
int validateChar(char word[], int length);

/** \brief valida que el sexo ingresado sea 'f' o 'm'
 *
 * \param sexo char
 * \return int
 *
 */
int validateSex(char sexo);

/** \brief verifica si el vector de clientes tiene al menos un cliente cargado y activo
 *
 * \param vec[] eClientes
 * \param tamC int
 * \return int
 *
 */
int loadedVector(eClientes vec[], int tamC);

/** \brief valida si el codigo de juego ingresado es correcto con los ya cargados en el vector juego
 *
 * \param juego[] eJuego
 * \param tamJ int
 * \param codigo int
 * \return int
 *
 */
int validarCodJuego(eJuego juego[], int tamJ, int codigo);

/** \brief valida si el codigo de cliente ingresado coincide con uno ya cargado en el vector clientes
 *
 * \param cliente[] eClientes
 * \param tamC int
 * \param codigo int
 * \return int
 *
 */
int validarCodCliente(eClientes cliente[], int tamC, int codigo);
