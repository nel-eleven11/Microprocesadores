/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3056 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2019
Mod:   09/12/23

argumentos1.cpp
Comparte a subrutina argumentos en es-
tructura con elementos de múltpiple 
tipo, hacia el thread creado
---------------------------------------*/

//se incluyen las librerias necesarias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


// se define el numero de threads
#define num_th 100

// estructura para los argumentos
struct parameters { 
	int id;
	float val1;
	float val2;
};


//subrutina que realiza un cálculo con los argumentos del thread
void *calculate(void *arg ) {
	//se realiza una asignación y conversión de la variable ps, con el tipo de la estructura
	parameters *ps;
	ps = (parameters *)arg;
	//se declara la variable res
	float res;
	
	//se accede a los valores de la estructura
	res = ps -> val1*ps -> val2;
	//se imprime el thread id y el resultado
	printf("Thread %d ", ps->id); 
	printf(" resultado %f \n", res); 
	//usleep(1000);
	/*
	 * De forma implicita, el thread llama a exit() al terminar
	 * su ejecucion.
	 */
	pthread_exit(NULL);
}

// main del programa
int main() {
	// se declaran los threads, como una lista
	pthread_t thread[num_th];
	int i;
	// se declara la estructura
	parameters p;
	
	/* 
	for para crear los threads, se pasan los argumentos a pthread_create, habrán varios argumentos
	para los threads
	*/
	for(i=1; i<num_th; i++){
		// se asignan los valores de los argumentos
		p.id = i;
		p.val1 = i;
		p.val2 = i-1;
		// se crea el thread, se pasan los argumentos a pthread_create
		// en el pthread_create se pasa la estructura como argumento
		pthread_create(&thread[num_th], NULL, calculate, ( void *)&p);
		// en el join no se espera valor de retorno
		pthread_join(thread[num_th], NULL);
	}

	// se termina el programa
	printf ("\n --- Fin --- \n");
}

//compilar con: g++ -pthread argumentos1.cpp -o argumentos1
//correr con: ./argumentos1