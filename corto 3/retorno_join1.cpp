/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2020
Mod:   09/12/2023

retorno_join1.cpp
Comparte desde subrutina argumento puntero
de tipo void, por medio de return.
---------------------------------------*/

//Incluir las librerias que se utilizarán
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

//Definición de la fución que se ejecutará en el hilo
void *calculos(void* argument){
	//Se instancian las variables de tipo entero de entrada y salida
	int input, output;
	
	//Se realiza el casting del argumento que se recibe como parametro a entero para poder operarlo
	input = (int)(intptr_t) argument;	
	//Se establece el valor del output como 2 veces el input
	output = input*2;
	
	//Se retorna el valor del output con el casting a tipo void para que pueda ser retornado por la subrutina
	return (void*)(intptr_t) output;
}
//Definición del punto de entrada del programa (main)
int main(){

	printf("\n\n");
	//Se instancian las variables de tipo pthread_t y pthread_attr_t
	pthread_t thread_id;
	pthread_attr_t attr;
	
	//Se inicializa el atributo de los threads
	pthread_attr_init (&attr);
	//Se establece el atributo de los threads como joinable
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	//Se inicializa la variable de tipo void como la variable donde se guardará el resultado de la subrutina
	void *exit_value;
	//Se inicializa la variable de tipo entero como la variable donde se guardará el resultado de la multiplicación
	unsigned int result = 1;
	
	//Bucle encargado de crear y unir los hilos que ejecutarán la subrutina
	for(int i = 0; i < 100; i++){
		//Se crea el hilo con el id del hilo, el atributo de los hilos, la subrutina que se ejecutará y el argumento que se le pasará a la subrutina
		pthread_create(&thread_id, &attr, calculos, (void*) (intptr_t)i);
		//Una vez se crea el hilo, se une el hilo con el hilo principal
		pthread_join(thread_id, &exit_value);
		//Se realiza el casting del valor de retorno de la subrutina a entero para poder operarlo
		int result = (int)(intptr_t) exit_value;
		//Se imprime el resultado de la multiplicación
		printf("Resultado multiplicación es: %d\n", result);
	}
	
	//Como buena práctica se destruye el atributo de los hilos al terminar la sección paralela del programa
	//Se destruye el atributo de los hilos
	pthread_attr_destroy(&attr);
	//Se finaliza el hilo principal
	pthread_exit(NULL);
	//Se retorna 0 para indicar que el programa finalizó correctamente
	return 0;
	
}
