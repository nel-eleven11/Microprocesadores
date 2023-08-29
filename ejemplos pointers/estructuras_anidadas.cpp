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

struct info_direccion{
    char direccion[30];
    char ciudad[20];
};

struct empleado{
    char nombre[20];
    struct info_direccion dir_empleado;
    double salario;
}empleados[2]; //Arreglo de estructuras

int main(){
    for(int i=0; i<2; i++){
        //Para vaciar buffer y permitir digitar valores
        fflush(stdin);
        cout << "\nDigite Nombre: " << endl;
        cin.getline(empleados[i].nombre, 20, '\n');
        cout << "\nDigite su direccion: " << endl;
        cin.getline(empleados[i].dir_empleado.direccion, 30, '\n');        
        cout << "\nDigite su ciudad: " << endl;
        cin.getline(empleados[i].dir_empleado.ciudad, 20, '\n'); 
        cout << "\nDigite Salario: " << endl;
        cin >> empleados[i].salario;
        cout << "\n";
    }

    for(int i=0; i<2; i++){
        cout <<"\nNombre: "<<empleados[i].nombre<<endl;
        cout <<"Direccion: "<<empleados[i].dir_empleado.direccion<<endl;
        cout <<"Ciudad: "<<empleados[i].dir_empleado.ciudad<<endl;
        cout <<"Salario: "<<empleados[i].salario<<endl;
    }
    return 0;
}


