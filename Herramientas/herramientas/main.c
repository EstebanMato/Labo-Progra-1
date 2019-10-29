/** \brief Valida que el numero igresado este entre el rango aceptado y no se superen la cantidad de intentos
 *
 * \param numero int*
 * \param mensaje char* primer mensaje
 * \param mensajeError char* mensaje de error
 * \param min int
 * \param max int
 * \param intentos int
 * \return int 1 si cargo, 0 si no pudo
 *
 */
int getIntRange(int* numero, char* mensaje, char* mensajeError, int min, int max, int intentos){

    int auxiliar;
    int todoOk = 1;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    while(auxiliar < min || auxiliar > max){
        intentos--;

        if(intentos == 0){
            todoOk = 0;
            break;
        }

        printf("%s", mensajeError);
        scanf("%d", &auxiliar);
    }

    if(intentos != 0){
        *numero = auxiliar;
    }

return todoOk;
}

/** \brief realiza el factorial de un numero
 *
 * \param num long
 * \return long long, factorial de 0 = 1
 *
 */
long long factorial(long num){
    long long fact;

    if(num == 1 || num == 0){
        fact = 1;
    }else{
        fact = num*factorial (num-1);
    }

    return fact;
}

/** \brief busca el numero en el vector y retorna si lo encontro o no
 *
 * \param vec[] int nombre vector
 * \param tamanio int tamaño del vector
 * \param numero int numero a buscar
 * \return int "loEncontro" 1 lo encontro, 0 no
 *
 */
int buscarNumeroVector(int vec[],int tamanio, int numero){
    int loEncontro = 0;
    for (int i=0; i<tamanio; i++){

        if (numero == vec[i]){
            loEncontro =1;
        break;

        }
    }
return loEncontro;
}

/** \brief recibe un vector, su tamaño y lo imprime por pantalla
 *
 * \param vec[] int nombre del vector
 * \param tamanio int el tamaño del vector
 * \return void
 *
 */
void imprimirVectorInt (int vec[], int tamanio){

    for (int i=0; i<tamanio;i++){
        printf("%d ", vec[i]);

    }
    printf("\n\n");
}

/** \brief ordena el vector de enteros segun criterio ascendente o descendente
 *
 * \param v[] int nombre del vector
 * \param tam int tamaño del vector
 * \param criterio int ascendente = 1 , descendente =0
 * \return void no retorna nada ya que los vectores se pasan directamente por referencia siempre, no por paramentro
 *
 */
void ordenarVectorInt(int v[], int tam, int criterio){

    int aux;

    for(int i=0; i < tam -1; i++){

        for(int j = i + 1; j < tam; j++){

            if( v[i] > v[j]&& criterio){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;

            }else if( v[i] <  v[j]&& !criterio){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

/** \brief carga un vector
 *
 * \param vec[] int nombre del vector
 * \param tam int tamaño del vector
 * \return void
 *
 */
void cargarVectorInt(int vec[], int tam){

     for(int i=0; i<tam; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }
}

/** \brief obtener mayor numero de un vector int
 *
 * \param vec[] int nombre del vector
 * \param tam int tamaño del vector
 * \return int devuelve el mayor numero
 *
 */
int obtenerMayor(int vec[], int tam){
    int max;
    int flag = 0;

     for(int i=0; i < tam; i++)
    {
       if(vec[i] > max || flag ==0){
            max = vec[i];
            flag = 1;
       }
    }
    return max;
}

/** \brief obtener menor numero de un vector int
 *
 * \param vec[] int nombre del vector
 * \param tam int tamaño del vector
 * \return int devuelve el menor numero
 *
 */
int obtenerMenor(int vec[], int tam){
    int min;
    int flag = 0;

    for(int i=0; i<tam; i++){
        if(vec[i]<min || flag==0){
            min=vec[i];
            flag = 1;
        }
    }
    return min;
}


