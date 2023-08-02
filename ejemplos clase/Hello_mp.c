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

#include <omp.h>					// OpenMP include file
#include <stdio.h>					// stdio library
#include <stdlib.h>


int main( int argc, char *argv[] )	// Main function
{
	#pragma omp parallel			// Parallel region with default number of threads
	{								
		printf("Hello CC3086!\n Kind regards, Thread %d\n\n ",
		omp_get_thread_num());		// Runtime library function to return
	}								// a thread ID
    //system("PAUSE");
	return 0;

}
