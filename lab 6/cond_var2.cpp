/*---------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3056 - Programacion de Microprocesadores
* Autor: Ismael Ripoll
* Mod.: KB
* Ver.: 1.01
* Fecha: 2021/08/29
* Mod:   2023/09/29
*
* References:
* ------
* "Sincronización: Mutex, Variables condición y Semáforos."  
* Universidad Politécnica de Valencia
* Dpto. de Informática de Sistemas y Computadores
* http://www.gii.upv.es/rtportal/tutorial/06-sincronizacion/06-sincronizacion.html
* ---------------------------------------
* Modelo Productor-Consumidor con Mutex y 
* variables de condición.
*----------------------------------------
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
	    
int in, out, cont, buffer[10]; 
pthread_cond_t lleno, vacio; 
pthread_mutex_t mutex; 

int Escribe(int DATO){
	// se bloquea el mutex
  pthread_mutex_lock (&mutex); 
  
  while (cont == 10) 
  // se bloquea el hilo hasta que se cumpla la condición
    pthread_cond_wait(& vacio, &mutex); 
  cont++; 
  
  buffer[in]= DATO;
  in = (in+1) % 10;    // 0 0  1 1  para todos valores menor igual 10... indice 1 valor num 11, ind 2 vn 12...
  // se despierta a todos los hilos que estén esperando por la variable de condición lleno
  pthread_cond_broadcast(& lleno); 
  // se desbloquea el mutex
  pthread_mutex_unlock(& mutex); 
  
  return 0;
} 

int Lee(){ 

  int dato;   
  // se bloquea el mutex
  pthread_mutex_lock(&mutex);
  // IMPORTANTE: Se emplea un ciclo, no un if
  while (cont == 0)
    // se bloquea el hilo hasta que se cumpla la condición 
    pthread_cond_wait(& lleno, &mutex); 
  cont--; 
  
  dato = buffer[out]; 
  out = (out+1) % 10;
  // se despierta a todos los hilos que estén esperando por la variable de condición vacio
  pthread_cond_broadcast(& vacio); 
  // se desbloquea el mutex
  pthread_mutex_unlock(&mutex); 
  return dato; 
} 

 void *productor(void * arg){ 
 
  int i; 
  printf("Hilo hijo trabajando...\n");
  // for que ejecuta la función Escribe 20 veces
  for (i= 0; i< 20; i++)
	Escribe(i); 
  // se hace un sleep para que el hilo hijo pueda trabajar
  usleep(1000);
  // sale del hilo
  pthread_exit(0); 
  
  return NULL;
} 

int main(){ 
  int i; 
  pthread_t hijo;
  in = out = cont = 0;

// Inicialización del mutex
  pthread_mutex_init(&mutex, NULL); 
// Inicialización de las variables de condición
  pthread_cond_init(&lleno, NULL); 
  pthread_cond_init(&vacio, NULL);
// Creación del hilo, se le pasa la función productor
  pthread_create(&hijo,NULL,productor,NULL);
  // se hace un sleep para que el hilo hijo pueda trabajar
  usleep(1000);
  printf("Proceso Principal\n");
  // for que ejecuta la función Lee 20 veces
  for (i= 0; i< 20; i++) 
  //se imprime el valor que retorna la función Lee
    printf("%d\n ", Lee());

  exit(0); 
}

// compilar: gcc -o cond_var2 cond_var2.cpp -lpthread