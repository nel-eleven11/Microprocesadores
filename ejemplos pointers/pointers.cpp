/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
*
* Curso: Programación de microprocesadores
* Actividad: Uso de programación genérica con Template
* Descripción: 
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// variables
int var = 8, numero;
int *ptr;
int *dir_numero;

int main(){
    cout << "EJEMPLO 1" << endl;
    ptr = &var;
    cout << "La direccion de memoria de var es: " << &var << endl;
    cout << "La direccion de memoria guardada en el ptr: " << ptr << endl;

    cout << "EJEMPLO 2" << endl;
    ptr = &var;
    cout << "Usando desreferencia, el valor de var es: " << *ptr << endl;
    cout << "Cambiar el valor de var, ahora es: " << (*ptr = 100) << endl;

    cout << "EJEMPLO 3" << endl;
    dir_numero = &numero;
    cout << "Ingrese un número" << endl;
    cin >> *dir_numero;
    cout << "El numero ingresado es: " << numero << endl;

    if(*dir_numero%2 == 0) {
        cout <<  "El numero es par" << endl;  
    } 
    else{
        cout <<  "El numero es impar" << endl;
    }
    cout <<  "La direccion es: " << dir_numero << endl;
    


    return 0;

}