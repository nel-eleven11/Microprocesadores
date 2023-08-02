/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programación de microprocesadores
* Ciclo II - 2023
*
* Actividad: Laboratorio No. 1
* Descripción: Asignación de diferentes actividades a padre e hijo.
------------------------------------------------------------------------------*/
//#include <windows.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

void rutina() 
{
    int var = fork();
    if (var == 0){
	// valor de sleep para child es 10					    //Child process, return 0
	sleep(10);
        printf("Hello from Child!\n"); 
	printf("Fork value from Child is: %d\n", var);
  }
    else {	
	// valor de sleep para parent es 10								 // pid =! 0. 
	sleep(10);
        printf("Hello from Parent!\n"); 
	printf("Fork value from Parent is: %d\n", var);
  }
} 

int main() 
{ 
    rutina(); 
    return 0; 
} 
