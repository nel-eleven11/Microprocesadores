/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2019
Mod:   09/12/2023

test_self.cpp
Hilo realiza rutina para impresión de 
thread id 
---------------------------------------*/

//se incluyen las librerias necesarias

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

//using namespace std;

// subrutina para imprimir el thread id
void *PrintID(void *threadid) {
   //int tid;
   //tid = (int)threadid;
   //se indica que se esta imprimiendo el thread id desde la subrutina
   printf("Subrutina - Thread ID, %ld", pthread_self());
   printf("\n");
   //se termina el thread
   pthread_exit(NULL);
   //se retorna NULL
   return NULL;
}

// main del programa
int main () {
    // se declara el thread
    pthread_t threads;
    int rc;
    
    printf("\n--- MAIN() : CREATING NEW THREAD ---");

    // se crea el thread, se pasan los argumentos a pthread_create
    rc = pthread_create(&threads, NULL, PrintID, NULL);
    //se imprime el thread id del main
	printf("\nMain - Thread ID, %ld\n",threads);
    
    // se usan la función pthread_join() para esperar a que el thread termine, no se espera un valor de retorno
	pthread_join(threads, NULL); 
    // se termina el thread
	pthread_exit(NULL);
	
}

//compilar con: g++ -pthread test_self.cpp -o test_self
//correr con: ./test_self