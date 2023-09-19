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

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

//using namespace std;



void *PrintID(void *threadid) {
   //int tid;
   //tid = (int)threadid;
   printf("Subrutina - Thread ID, %ld", pthread_self());
   printf("\n");
   pthread_exit(NULL);
   return NULL;
}

int main () {
    pthread_t threads;
    int rc;
   
    printf("\n--- MAIN() : CREATING NEW THREAD ---");
    rc = pthread_create(&threads, NULL, PrintID, NULL);
	printf("\nMain - Thread ID, %ld\n",threads);
    
	pthread_join(threads, NULL); 
	pthread_exit(NULL);
	
}