#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

typedef struct
{

    int id;
    char descripcion[20];

} eCarrera;

#endif // CARRERA_H_INCLUDED

// Funciones Carrera
void mostrarCarreras(eCarrera carreras[], int tam);
void mostrarCarrera(eCarrera carrera);
int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]);
