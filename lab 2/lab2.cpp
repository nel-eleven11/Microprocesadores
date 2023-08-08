/*
Laboratorio 2 parte 2
Nelson García 22434
Joaquín Puente 22296
*/

#include <iostream>
#include <cstdlib>
using namespace std;
#include <ctime>
#include <omp.h>

#define N 3

int main() {

    clock_t start_time = clock();
    int hilos;

    do {
        cout << "Ingrese el numero de hilos (minimo 3, multiplos de 3): ";
        cin >> hilos;
    } while (hilos < 3 || hilos % 3 != 0);

    omp_set_num_threads(hilos);


    int A[N][N], B[N][N];
    
    cout << "Matriz A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 100;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    int C[N][N] = {0};
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "Matriz C:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    clock_t end_time = clock();
    
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %lf segundos\n", elapsed_time);

    return 0;
}
