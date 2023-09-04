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
int numCalif, *calif, *calif2, *calif3;
string *estudiantes;
int notas[3][3];
int *promedio;
int promedio_total;

int main(){
    pedirNotas();
    mostrarNotas();
    delete[] calif; //liberacion del espacio utilizado
    delete[] calif2;
    delete[] calif3;
    delete[] estudiantes;

    return 0;
}

void pedirNotas(){
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>numCalif;
    calif = new int[numCalif]; //Crear arreglo
    calif2 = new int[numCalif];
    calif3 = new int[numCalif];
    estudiantes = new string[numCalif];
    promedio = new int[numCalif];
    for (int i = 0; i < numCalif;i++){
        cout << "Ingrese el nombre del estudiante: " << endl;
        cin >> estudiantes[i];

        cout << "Ingrese una nota del lab 1: " << endl;
        cin >> calif[i];

        cout << "Ingrese una nota del lab 2: " << endl;
        cin >> calif2[i];

        cout << "Ingrese una nota del lab 3: " << endl;
        cin >> calif3[i];
        promedio[i] = (calif[i] + calif2[i] + calif3[i])/3;
    }
    //calcular el promedio total
    for (int i = 0; i < numCalif; i++){
        promedio_total += promedio[i];
    }
    promedio_total = promedio_total / numCalif;
}

void mostrarNotas(){
    cout << "\nNotas de los estudiantes: \n";
    for (int i = 0; i < numCalif; i++){
        cout << "\n---------------------------------------" << endl;
        cout << "\nNombre del estudiante: " << estudiantes[i] << endl;
        cout << "\nNota del lab 1: " << calif[i] << endl;
        cout << "\nNota del lab 2: " << calif2[i] << endl;
        cout << "\nNota del lab 3: " << calif3[i] << endl;
        cout << "\nPromedio del estudiante: " << promedio[i] << endl;
    }
    cout << "\nPromedio total de los estudiantes: " << promedio_total << endl;
    calif = calif - numCalif;
    calif2 = calif2 - numCalif;
    calif3 = calif3 - numCalif;
    estudiantes = estudiantes - numCalif;
    promedio = promedio - numCalif;
}

