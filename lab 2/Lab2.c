/*
*----------------------------------------
* Lab2.c
* ---------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Laboratorio No.2
* ---------------------------------------
*
* Analizar código y explicar cuál es el 
* funcionamiento del programa.
* Corregir código y documentar.
*
*----------------------------------------*/


#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#define TRUE 1
#define FALSE 0

#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#endif

#define N 40

int main ()
{
	int A[N], B[N];
	int i, j;
	
	for (i=0; i<N; i++) A[i] = i;
	for (i=0; i<N; i++) B[i] = i;
	
	// impresion de resultados
	printf("\n Vector A, consecutive distribution \n\n");
	printf(" 0 1 2 3 4 5 6 7 8 9\n");
	printf("-----------------------------------------\n");
	
	for (i=0; i<N/10; i++)
	{
		printf("\n");
		for (j=i*10; j<(i+1)*10; j++) printf("%3d ", A[j]);
		printf("\n");
	}
	
	printf("\n\n");
	printf(" Vector B, interlaced distribution \n\n");
	printf(" 0 1 2 3 4 5 6 7 8 9\n");
	printf("-----------------------------------------\n");
	for (i=0; i<N/10; i++)
	{
		
		printf ("\n");
		for (j=i*10; j<(i+1)*10; j++) printf("%3d ", B[j]);
		printf ("\n");
	}
	printf ("\n");
	return 0;
}