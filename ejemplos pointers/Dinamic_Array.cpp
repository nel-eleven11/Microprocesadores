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

//Prototipo de funcion
void pedirNotas();
void mostrarNotas();

//Variables
int numCalif, *calif;

int main(){
    pedirNotas();
    mostrarNotas();
    delete[] calif; //liberacion del espacio utilizado

    return 0;
}

void pedirNotas(){
    cout<<"Digite el numero de calificaciones: ";
    cin>>numCalif;
    calif= new int[numCalif]; //Crear arreglo
    for (int i = 0; i < numCalif;i++){
        cout << "Ingrese una nota: ";
        cin >> calif[i];
    }
}

void mostrarNotas(){
    cout << "\nNotas del usuario: \n";
    for (int i = 0; i < numCalif; i++){
        cout << *calif++ << endl;
    }
    calif = calif - numCalif;
}

