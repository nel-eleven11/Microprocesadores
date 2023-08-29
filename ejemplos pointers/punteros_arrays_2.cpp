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

int numeros[10] , *dir_numeros;

int main(){
    for(int i=0; i<10 ; i++){
        cout << "Ingrese un numero: ";
        cin >> numeros[i];     
    }
    //Agregado
    dir_numeros = &numeros[0];
    for(int i=0; i<10 ; i++){
        if(*dir_numeros%2 == 0){
        cout << "El numero " << *dir_numeros << "es par" << endl;
        cout << "Su direccion es " << dir_numeros << endl;
        }
    //Agregado
    dir_numeros++;
    }


}