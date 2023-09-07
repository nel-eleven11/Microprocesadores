/*
 *----------------------------------------
 * UNIVERSIDAD DEL VALLE DE GUATEMALA
 * CC3086 - Programacion de Microprocesadores
 * Modificado por: KB
 * Fecha: 2023/09/03
 * Referencias:
 * "Predicates" - The C++ Standard Library (Josuttis)
 * pp.226-227
 * "Shared Objects and Synchronization" - The Art of 
 * Multiprocessor Programming (Herlihy & Shavit)
 * pp.3-5
 * 
 * primes3.cpp - V3.2023
 * ---------------------------------------
 * Imprime los números primos en un rango de 10^n
 * Implementación simplista usando pthreads
 * ----------------------------------------
 */

#include <iostream>     //cout, cin, endl
#include <cmath>        //pow
#include <pthread.h>    //pthread_
#include <ctime>        //time_t, clock, difftime   

using namespace std;

// Estructura para contener el rango de números para cada hilo
struct Range {
    long start;
    long end;
};

// Prototipo de la función para verificar si un número es primo
bool isPrime(int number);

// Prototipo de la rutina del hilo
void *primeTest(void *range);

int main() {
    int exponente, numThreads;

    // Contadores para el tiempo
    clock_t start_t, end_t;
    double total_t;
    
    cout << "-----------------------------------------------\n";
    cout << "Imprimir números primos menores que 10^n\n";
    cout << "-----------------------------------------------\n";
    cout << "Ingrese el valor del exponente para la base 10: ";
    cin >> exponente;
    
    cout << "Ingrese el número de hilos: ";
    cin >> numThreads;
    
    long limit = pow(10, exponente);
    long numerosPorHilo = limit / numThreads;

    cout << "Buscando primos entre 0 y " << limit << "...";
    cout << endl;

    int rc;

    // Definir objeto pthread
    pthread_t threadID[numThreads];
    Range intervalos[numThreads];

    start_t = clock();

    // Crear hilos y asignarles un rango de números
    for (int i = 0; i < numThreads; i++) {
        intervalos[i].start = i * numerosPorHilo;
        intervalos[i].end = (i + 1) * numerosPorHilo - 1;

        if (i == numThreads - 1) {
            intervalos[i].end = limit;  // Asegurar que el último hilo llegue hasta el límite
        }

        rc = pthread_create(&threadID[i], NULL, primeTest, &intervalos[i]);
        if (rc) {
            cout << "No se pudo crear el hilo " << i << endl;
            exit(-1);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < numThreads; i++) {
        rc = pthread_join(threadID[i], NULL);
        if (rc) {
            cout << "No se pudo unir el hilo " << i << endl;
            exit(-1);
        }
    }

    end_t = clock();
    total_t = difftime(end_t, start_t) / CLOCKS_PER_SEC;
    cout << "Tiempo total: " << total_t << endl;

    pthread_exit(NULL);

    return 0;
}

// Rutina del hilo para verificar si los números en un rango son primos
void *primeTest(void *arg) {
    Range *rango = (Range *)arg;

    for (long i = rango->start; i <= rango->end; i++) {
        if (isPrime(i)) {
            cout << i << " desde el hilo num: " << pthread_self() << endl;
        }
    }
    pthread_exit(NULL);
}

// Función para verificar si un número es primo
bool isPrime(int number) {
    if (number == 0 || number == 1) {
        return false;
    }
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;  // Algoritmo rápido para encontrar el residuo de un primo
    }
    if (divisor != 1) {
        return false;  // El residuo <> si el número NO es primo
    } else {
        return true;   // El residuo es 1 si el número es primo
    }
}
