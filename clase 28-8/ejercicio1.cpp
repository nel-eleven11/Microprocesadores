/*
Nelson García Bravatti
22434
Ejercicio 1, uso de pointers
*/

#include <iostream>
using namespace std;

//variables
int var = 8, numero;
int *ptr;
int *dir_numero;

int main(){

    cout << "Ingrese un numero: " << endl;
    cin >> numero;    
    dir_numero = &numero;

    if(*dir_numero % 2 == 0){
        cout << "El numero es par" << endl;
    }else{
        cout << "El numero es impar" << endl;
    }
    return 0;
}