/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 Programación de microprocesadores
* Semana 05: Introducción Openmp
*
* Hello_Thread.c
* Modificado por: Kimberly Barrera
* Fecha: 15/07/2023
* Descripción: Impresión de texto en consola
------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void openmp_hello(void);

int main(int argc, char* argv[]) {
	int thread_count = strtol(argv[1], NULL, 10);
	clock_t start_time = clock();

	#pragma omp parallel num_threads(thread_count)
	{
		openmp_hello();
	}
	
	clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %lf segundos\n", elapsed_time);
	return 0;
}

void openmp_hello(void) {
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();

	if (my_rank % 2 == 0)
    {
		printf("Hola desde el thread %d de %d, este es par\n", my_rank, thread_count);
    }
    else
    {
		printf("Hola desde el thread %d de %d, este es impar\n", my_rank, thread_count);
    }

	

} 