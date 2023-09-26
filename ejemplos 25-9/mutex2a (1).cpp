/*---------------------------------------
Modificado por: Kimberly Barrera
Fecha: 	01/09/2019
Mod.: 	2020/08/30 (JJCelada)

mutex2a.cpp
Demuestra utilización básica de mutexes
---------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

const int THREADS = 8;
//Defincion de variables: hilos, contador, variable mutex
pthread_t tid[THREADS];
int counter;
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{
    pthread_mutex_lock(&lock);					//establecer bloqueo antes utilizar recurso

    unsigned long i = 0;
    counter += 1;								//incialización variable utilizada para retardo
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0x07000000);i++);
    printf("\n Job %d finished\n", counter);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0) 						//inicializacion de mutex no completada
    {
        printf("\n mutex init failed\n");
        return 1;
    }
    while(i < THREADS)													//se crean solo 2 hilos
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL); 	//creacion de hilos sin paso de parametros
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));	//impresion de mensaje si el hilo no se crea correctamente
        i++;
    }
	
	for(i=0;i<THREADS;i++)
	{
		pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);									//destruccion de mutex dinamica ya usada

    return 0;
}