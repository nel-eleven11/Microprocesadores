/*
Nelson García Bravatti 
22434
Programación de microprocesadores
Laboratorio 5
Ejercicio 3

producto punto de dos vectores 
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

//numero de hilos a utilizar

#define NTHREADS 1000

//Defincion de variables: hilos, contador, variable mutex

pthread_t tid[NTHREADS];	
pthread_attr_t attr[NTHREADS];				
int counter = 0;
int producto_punto = 0;
pthread_mutex_t lock;

//estructura para almacenar los vectores

struct Vector{
    int valores[NTHREADS];
    int id[NTHREADS];
};

// se encarga de realizar el producto de los valores de la n-dimensión de los vectores

void* p_punto(void *arg)	
{

    //se bloquea el mutex 
    pthread_mutex_lock(&lock);

    long resultado;
    counter += 1;

    //se obtienen los vectores de la estructura y se realiza la operación

    struct Vector *vectores = (struct Vector*) arg;

    struct Vector Vec_A = vectores[0];
    struct Vector Vec_B = vectores[1];

    int a = Vec_A.valores[counter-1];
    int b = Vec_B.valores[counter-1];
    int i = Vec_A.id[counter-1];
    
    resultado = a * b;
    
    printf("\n Operación # %d started\n", counter);
	printf("Realizado por hilo No. %d\n",i);

    //se desbloquea el mutex

    pthread_mutex_unlock(&lock);

    //se retorna el resultado de la operación

    return (void*)(intptr_t) resultado;	    
}


int main(void)
{
    long i = 0;		
    int err;		

    //se inicializa el mutex
    if (pthread_mutex_init(&lock, NULL) != 0) 	
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    //se inicializan los vectores

    struct Vector Vectores[3];	

    //se inicializan los atributos de los hilos

    for(int i = 0; i < NTHREADS; i++){
		pthread_attr_init(&attr[i]);
		pthread_attr_setdetachstate(&attr[i], PTHREAD_CREATE_JOINABLE);
	}


    void *exit_value;
	unsigned int result = 1;

    //se inicializan los vectores con valores aleatorios

    for(i=0;i<NTHREADS;i++) 
    {
        Vectores[0].valores[i] = rand() % 11;
        Vectores[1].valores[i] = rand() % 11;
        Vectores[0].id[i] = i;
        Vectores[1].id[i] = i;
    }

    //se crean los hilos

    for(i=0;i<NTHREADS;i++)
    {
        //se pasan los vectores como argumento a la subrutina
        err = pthread_create(&(tid[i]), &attr[i], &p_punto, &Vectores);

        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));		
    }			

    //se unen los hilos		

	for (i=0;i<NTHREADS;i++)
	{ 
		err = pthread_join(tid[i],&exit_value);
        if (err != 0) printf("\ncan't join thread :[%s]", strerror(err));

        //se obtiene el resultado de la operación
        int result = (int)(intptr_t)exit_value;

        //se almacena el resultado en el vector de resultados
        Vectores[2].valores[i] = result;

        printf("\n Resultado parcial: %d, Operación # %ld\n", result, i+1);
	} 

    //se realiza el la sumatoria de los productos parciales, para obtener el producto punto
    for(int i = 0; i < NTHREADS; i++){

        producto_punto = producto_punto + Vectores[2].valores[i];
    }
    printf("\n Resultado final del producto punto: %d\n", producto_punto);

    //se destruye el mutex y los atributos de los hilos
    for(int i = 0; i < NTHREADS; i++){
		pthread_attr_destroy(&attr[i]);
	}
	pthread_mutex_destroy(&lock);
    return 0;
}

//compilar con: g++ -pthread Ejercicio03_Sol.cpp -o Ejercicio03 