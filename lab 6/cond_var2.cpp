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
	
  pthread_mutex_lock (&mutex); 
  
  while (cont == 10) 
    pthread_cond_wait(& vacio, &mutex); 
  cont++; 
  
  buffer[in]= DATO;
  in = (in+1) % 10;    // 0 0  1 1  para todos valores menor igual 10... indice 1 valor num 11, ind 2 vn 12...
  pthread_cond_broadcast(& lleno); 
  pthread_mutex_unlock(& mutex); 
  
  return 0;
} 

int Lee(){ 

  int dato;   
  pthread_mutex_lock(&mutex);
  // IMPORTANTE: Se emplea un ciclo, no un if
  while (cont == 0) 
    pthread_cond_wait(& lleno, &mutex); 
  cont--; 
  
  dato = buffer[out]; 
  out = (out+1) % 10;
  pthread_cond_broadcast(& vacio); 
  pthread_mutex_unlock(&mutex); 
  return dato; 
} 
 void *productor(void * arg){ 
 
  int i; 
  printf("Hilo hijo trabajando...\n");
  for (i= 0; i< 20; i++)
	Escribe(i); 
  usleep(1000);
  pthread_exit(0); 
  
  return NULL;
} 

int main(){ 
  int i; 
  pthread_t hijo;
  in = out = cont = 0;

  pthread_mutex_init(&mutex, NULL); 
  pthread_cond_init(&lleno, NULL); 
  pthread_cond_init(&vacio, NULL);
  
  pthread_create(&hijo,NULL,productor,NULL);
  
  usleep(1000);
  printf("Proceso Principal\n");
  
  for (i= 0; i< 20; i++) 
    printf("%d\n ", Lee());
  exit(0); 
}