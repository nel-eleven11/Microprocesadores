/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓ
* CC3086 Programación de microprocesadores
* Semana 05: Introducción Openmp
* 
* dotProd_sec.c
* Original: Using OpenMP
* Modificado por: Kimberly Barrera
* Fecha: 15/07/2023
* Descripción: Cálculo secuencial de producto punto.
* --------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{
    clock_t start_time = clock();
    double sum;
    double a[256], b[256];
    int n,i;
    n = 256;
    
    for (int i = 0; i < n; i++) {
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }
    sum = 0;

    //#pragma omp parallel for reduction(+:sum)
    for (i = 1; i <= n; i++ ) {
        sum = sum + a[i]*b[i];
        // printf("Main Thread sum = %f\n ", sum);
    }   
    printf("Total sum = %f", sum);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTiempo de ejecucion: %lf segundos\n", elapsed_time);
    
    
    return 0;
}