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

//Variables
string letras[] = {"U","A","V","B","G"}; 
string *dir_letras;
float numeros[] = {1.0, 2.0, 3.0, 4.0, 5.0};
float *dir_numeros;

int main(){
    dir_letras = &letras[0];    //Esto es igual a:  dir_letras = letras;
    cout << "IMPRESION ARRAY LETRAS" << endl;
    //Impresión UVG
    cout << *dir_letras;
    dir_letras = dir_letras + 2;
    cout << *dir_letras;
    dir_letras = dir_letras + 2; 
    cout << *dir_letras << endl;

    //Regresar puntero a posición inicial de array
    dir_letras = dir_letras - 4;
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento del vector[" << i << "]: " << *dir_letras++;
        cout << " y su posicion en memoria es: " << dir_letras << endl;
        //*dir_numeros++;
    }
    dir_numeros = numeros;    //Esto es igual a:  dir_numeros = &numeros[0];
    cout <<"\nIMPRESION ARRAY NUMEROS DECIMALES" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento del vector[" << i << "]: " << *dir_numeros++;
        cout << " y su posicion en memoria es: " << dir_numeros << endl;
        //*dir_numeros++;
    }
    
   return 0;
}

