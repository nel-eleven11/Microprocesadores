/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
*
* Curso: Programación de microprocesadores
* Actividad: 
* Descripción: 
------------------------------------------------------------------------------*/
#include <iostream>
//#include <stdlib>
using namespace std;

struct Persona{
    char nombre[20];
    int edad;
} persona1 = {"Manolo", 20},
  persona2;//= {"Diego", 25};

int main(){
    cout << "Nombre1: " << persona1.nombre << endl;
    cout << "Edad1: " << persona1.edad << endl;
    
    cout << "\nIngrese Nombre 2: " << endl;
    cin.getline(persona2.nombre, 20, '\n');
    cout << "Ingrese Edad 2: " << endl;
    cin >> persona2.edad;
    cout << "\nNombre2: " << persona2.nombre << endl;
    persona2.edad = 28;
    cout << "Edad2: " << persona2.edad << endl;
    return 0;
}


