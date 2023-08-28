/*
Nelson García Bravatti
22434
Corto 2, ejemplo de directiva, constructor o función de OpenMP que no se ha estudiado en clase
funcion omp_set_nested
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int hilos_fuera = 2;
    int hilos_dentro = 3;

    omp_set_num_threads(hilos_fuera);

    #pragma omp parallel
    {
        printf("Hilos de afuera %d\n", omp_get_thread_num());
        
        omp_set_nested(1); 

        #pragma omp parallel num_threads(hilos_dentro)
        {
            printf("Hilos de adentro %d (Hilo de afuera%d)\n", omp_get_thread_num(), omp_get_ancestor_thread_num(1));
        }

        omp_set_nested(0); 
    }

    return 0;
}


