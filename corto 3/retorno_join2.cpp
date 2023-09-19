/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera

Fecha:   09/12/2023

retorno.cpp
Comparte desde subrutina argumento puntero
de tipo void, por medio de return.
---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *calculos(void* argument){
	
	int input, output;
	
	input = (int)(intptr_t) argument;	
	output = input*2;
	
	return (void*)(intptr_t) output;
}
int main(){

	printf("\n\n");
	pthread_t thread_id;
	pthread_attr_t attr;
	
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	void *exit_value;
	unsigned int result = 1;
	
	for(int i = 0; i < 10; i++){
		pthread_create(&thread_id, &attr, calculos, (void*) (intptr_t) i);

	}
	
	for(int i = 0; i < 10; i++){
		pthread_join(thread_id, &exit_value);
		
		int result =(int)(intptr_t)exit_value;
		printf("Resultado multiplicación es: %d\n", result);
	}
	
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
	return 0;
	
}


