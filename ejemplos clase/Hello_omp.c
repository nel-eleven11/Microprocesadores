/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓ
* CC3086 Programación de microprocesadores
* Semana 05: Introducción Openmp
* 
* Hello_mp.c
* Original: Learning Openmp
* Modificado por: Kimberly Barrera
* Fecha: 15/07/2023
* Descripción: Parelización de segmento de programa.
* --------------------------------------------------------*/
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int num_threads = omp_get_max_threads();  // Obtiene el num disponible total de hilos
    clock_t start_time = clock();

    #pragma omp parallel num_threads(num_threads)
    {
        printf("Hello CC3086!\nKind regards, Thread %d\n\n", omp_get_thread_num());
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %lf segundos\n", elapsed_time);
    return 0;
}
