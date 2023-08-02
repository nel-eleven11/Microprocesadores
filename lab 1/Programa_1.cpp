/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programación de microprocesadores
* Ciclo II - 2023
*
* Actividad: Laboratorio No. 1
* Descripción: llamada al sistema para creación de procesos hijos
------------------------------------------------------------------------------*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	printf("   --- PARENT PROCESS STARTED ----\n\n");
	
	pid = fork();							/*Fork a child process*/
	
	if (pid < 0) {						/*Error occurred */
		fprintf(stderr, "WARNING!! Fork failed");
		return 1;
	}
	else if (pid==0) {					/*Child process */
		printf("This is the CHILD process  - STATUS: CREATED\n");
	}
	else { 								/*PARENT PROCESS */
										/*Parent will wait for the child to complete */
		printf("This is the PARENT process - STATUS: RUNNING\n"); 

	}
	