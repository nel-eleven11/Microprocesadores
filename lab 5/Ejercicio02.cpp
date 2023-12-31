/** ---------------------------------------------------------
 * UNIVERSIDAD DEL VALLE DE GUATEMALA
 * CC3056 - Programacion de Microprocesadores
 * Auth: 	Kimberly Barrera
 * Date:	2021/08/25
 * Mod.:    2023/09/20
 * ---------------------------------------------------------
 * Ejercicio02.cpp
 * Laboratorio 05
 * Realizar: sincronización trabajo con mutex
 * ---------------------------------------------------------*/
 
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define NTHREADS 10

//Defincion de variables: hilos, contador
pthread_t tid[NTHREADS];					
int counter;
pthread_mutex_t lock;

void* function(void *arg)												//subrutina de inicio: imprime inicio y fin thread
{
    pthread_mutex_lock(&lock);											//bloqueo de mutex
    long i; 
	i = (long) arg;
	unsigned long j = 0;												//incialización variable utilizada para retardo
    	
	counter += 1;

    printf("\n----    Job %d started    ----\n", counter);	
	printf("    Realizado por hilo No. %ld\n",i);
	
    for(j=0; j<(0xFFFFF);j++);											//retardo
    printf("\n----   Job %d finished   ----\n", counter);
    pthread_mutex_unlock(&lock);			//indicador fin procesos de iésimo hilo
    pthread_exit(0);

    
    NULL;
}

int main(void)
{
    long i = 0;		
    int err;									

    while(i < NTHREADS)													//se crean  hilos
    {
        err = pthread_create(&(tid[i]), NULL, &function, (void *)i);	//creacion de hilos con paso de parametros
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));		//impresion de mensaje si el hilo no se crea correctamente
        i++;													
    }

	for (i=0;i<NTHREADS;i++)
	{ 
		pthread_join(tid[i],NULL);
	} 
	
    return 0;
}

//compilacion: gcc Ejercicio02.cpp -o Ejercicio02 -lpthread