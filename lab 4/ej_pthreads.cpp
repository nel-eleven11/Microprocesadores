/*
Ejemplo de pthreads
Nelson García 22434
Clase 4/9/2023
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define NUM_THREADS 100

/*subrutina*/
void *say_hello(void *threadNum){
    long tID;
    tID = (long)threadNum;

    //Cast tID to double
    double tIDDouble = static_cast<double>(tID);

    //Calculate the square root of the thread numbe
    double result;
    result = (double) sqrt(tIDDouble);

    printf("Hello World! It's me, thread #%ld! My square root is %f!\n", tID, result);
    pthread_exit(NULL);
}


/*programa principal*/

int main(){
     int rc;
     long i;

    pthread_t tid[NUM_THREADS];//ID de los hilos creados
    pthread_attr_t attr;//atributos de los hilos
    pthread_attr_init(&attr);//inicializa los atributos de los hilos
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);//establece el atributo de los hilos

    for(i=0; i<NUM_THREADS; i++){
        rc = pthread_create(&tid[i], &attr, say_hello, (void *)i);
        if(rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(i=0; i<NUM_THREADS; i++){
        pthread_join(tid[i], NULL);

        if(rc){
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    //liberar espacios creados dinamicamente
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

}

//compilar con g++ -pthread -o ej_pthreads ej_pthreads.cpp

