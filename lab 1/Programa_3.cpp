/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programación de microprocesadores
* Ciclo II - 2023
*
* Actividad: Laboratorio No. 1
* Descripción: Modificación de valores de variables en padre e hijo
------------------------------------------------------------------------------*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>	
  
void rutina() 
{ 
	pid_t pid;
	int status;
	pid = fork();
    int x = 10; 
  
    if (pid == 0) {
        printf("Child: Variable value  x = %d\n", ++x); 
		_exit(0);
		}
    else {
        printf("Parent: Variable value x = %d\n", --x); 
		(void)waitpid(pid,&status,0);
		}
} 

int main() 
{ 
    rutina(); 
    return 0; 
} 