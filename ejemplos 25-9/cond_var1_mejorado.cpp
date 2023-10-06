/*---------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3056 - Programacion de Microprocesadores
* Autor: Andrés Mondragón Contreras
* Mod.: KB
* Ver.: 1.01
* Fecha: 2021/08/29
*
* References:
* ------
* "Sincronización: Mutex, Variables condición y Semáforos."  
* Universidad Nacional Autonoma de Mexico
* Facultad de Ingenieria
* "Laboratorio Intel para la academia"
* ---------------------------------------
* Variables de condición p/acceder a 
* region crítica 
* variables de condición.
*----------------------------------------
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *menos(void *arg)
{
	printf("\nEntrando a subrutina MENOS: resta 1 al valor de x\n");
    int i;
	int *x = (int *)arg;
    
	for (i = 0; i < 9; i++) {
		pthread_mutex_lock(&mutex);	//  -1 -2 -3 -4 -5 -6 -7 -8 -9 ... 
        //printf("MENOS: mutex bloqueada.\n");
		*x = *x - 1;
		printf("%3d ", *x);
		pthread_mutex_unlock(&mutex);	// despierta al hilo que está esperando
        //printf("MENOS: mutex desbloqueada.\n");
	}
    pthread_cond_signal(&cond);
    printf("\nMENOS: libera a cond y a todos los hilos que la esperaban\n");
	return NULL;
}


void *mas(void *arg)
{
    printf("\nEntrando a subrutina MAS: suma 1 al valor de x\n");
	int i;
	int *x = (int *)arg;
	pthread_mutex_lock(&mutex);
    printf("MAS: mutex bloqueada & evaluando condición *x=0?...\n"); 
	if (*x == 0){            
        printf("MAS SUSPENDIDO: La condición *x=0 se cumplió \n");      // Bloquea al hilo que la llama hasta que la
		printf("Libera a mutex! El hilo MAS queda a la espera de liberar cond\n");
        pthread_cond_wait(&cond, &mutex);           // señal signal se habilita sobre cond
    }
    printf("MAS: despierta de la espera!\n");
	for (i = 0; i < 15; i++) {
	*x = *x + 1;
	printf("%3d ", *x);
	}
	
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
    printf("-- BIENVENIDOS AL PROGRAMA DE PRODUCCIÓN DE NÚMEROS --\n");
    printf("-- Esta es la forma básica de productor-consumidor.\n");

	pthread_t hilo_mas, hilo_menos;
	int x = 0;
	
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	
	pthread_create(&hilo_mas, NULL, mas, (void *)&x);
	pthread_create(&hilo_menos, NULL, menos, (void *)&x);

	pthread_join(hilo_mas, NULL);
	pthread_join(hilo_menos, NULL);
	printf("\n");
	
	
	pthread_cond_destroy (&cond);

}
