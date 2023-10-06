
/*
*----------------------------------------
* colaSemaforo.cpp
* ---------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Ver.: 1.0 2020/09/06
* Mod.: 2.1 2023/09/27
*
* References:
* "Communication and Syncronization of Concurrent Tasks" - 
* Professional Multicore Programming (Hughes & Hughes)
* pp.245 - 250
* ------
* "Shared-Memory Programming with Pthreads" - Intro to
* Parallel Programming (Pacheco) pp.153 - 181
* ------
* "Syncronizing Threads with POSIX Semaphores" (Damian) - 
* Computer Science Department - Villanova University
* http://www.csc.villanova.edu/~mdamian/threads/posixsem.html
* ---------------------------------------
* Produder-consumer model with semaphores
*----------------------------------------
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
	    
int in, out, cont, buffer[10]; 
pthread_mutex_t m;

/*----- creacion global de semaforos -----*/
sem_t espacios_en_cola, datos_en_cola; 

/*
** ---------------
** Funcion para escritura al buffer
** ---------------
*/
int Escribe(int DATO)
{
	sem_wait(&espacios_en_cola);
	
	pthread_mutex_lock(&m);
	buffer[in]= DATO;
	in = (in+1) % 10;
	pthread_mutex_unlock(&m);
	
	/*----- desbloquea el semaforo de lleno -----*/
	sem_post(&datos_en_cola);
} 

/*
** ---------------
** Subrutina para hilo productor (hijo)
** ---------------
*/
 void *productor(void * arg){ 
  int i; 
  //printf("Inicia ejecución de Hilo 1\n");
  for (i= 0; i< 100; i++) 
    Escribe(i); 
  pthread_exit(0); 
} 

/*
** ---------------
** Funcion para lectura del buffer
** ---------------
*/
int Lee()
{
	int dato; 
	if((out)%10==0)
		printf("<<<Cola vacia \n");
	sem_wait(&datos_en_cola);
	
	pthread_mutex_lock(&m);	
	dato = buffer[out]; 
	out = (out+1) % 10;
	pthread_mutex_unlock(&m);
	
	/*---- desbloquea el semaforo de vacio -----*/
	sem_post(&espacios_en_cola);
  return dato; 
} 


/*
** ---------------  MAIN  --------------- **
*/

int main(int argc, char *argv[])
{
	int i;
	pthread_t hijo;
	in = out = cont = 0;
	
	pthread_mutex_init(&m,NULL);
	
	/*----- inicializacion local de semaforos -----*/
	sem_init(&datos_en_cola,0,0);
	sem_init(&espacios_en_cola,0,10);
	
	pthread_create(&hijo,NULL,productor,NULL);
	//usleep(1000);
	//printf("Continua ejecución Hilo Principal\n");
	
	for (i= 0; i< 100; i++)
	{
		printf("%d ", Lee());
		if(i+1==100)
			printf("<<<Fin de cola\n");
	}
	exit(0); 
}