/*
Laboratorio 3 
Nelson García 22434
Joaquín Puente 22296
*/

#include <omp.h>
#include <iostream>
using namespace std;

unsigned int factorial(int n){
    unsigned int res = 1;

    if (n <= 1)
    {
        return 1;
    }

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                {
                    res *= n;
                }
            }
            #pragma omp section
            {
                {
                    res *= n-1;
                }
            }
        }
        #pragma omp single
        {
            if (n >= 3) {
                #pragma omp atomic
                res *= factorial(n-2);
                
            }
        }
    }
    return res;
}

int main()
{
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    cout << "El factorial de " << num << " es: " << factorial(num) << endl;

    return 0;
}
