/*
Nelson García Bravatti
22434
Programa 1, uso de pointers
*/

#include <iostream>
using namespace std;

//variables
int var = 8, numero;
int *ptr;
int *dir_numero;

int main(){
    cout << "Ejemplo 1" << endl;
    ptr = &var;
    cout << "La direccion de memoria de var es: " << &var << endl;
    cout << "La direccion de memoria guardadda en el ptr: " << ptr << endl;

    cout << "Ejemplo 2" << endl;
    ptr = &var;
    cout << "Usando desreferencia, el valor de var es: " << *ptr << endl;
    cout << "Cambiar el valor de var, ahora es: " << (*ptr = 11) << endl;

    return 0;
}

