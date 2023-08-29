/*
Nelson García Bravatti
22434
programa 2, uso de pointers, arreglos
*/

//compilar con g++ -o prg2 prg2.cpp

#include <iostream>
using namespace std;

int numreos[10], *dir_numeros;

int main(){
    for(int i = 0; i < 10; i++){
        cout << "Ingrese un numero: " << endl;
        cin >> numreos[i];
    }

    dir_numeros = numreos;
    for(int i = 0; i < 10; i++){
        if(*dir_numeros % 2 == 0){
            cout << "El numero es par" << endl;
        }else{
            cout << "El numero es impar" << endl;
        }
        cout << "Su direccion es " << dir_numeros << endl;
        dir_numeros++;
    }
    

    for(int i = 0; i < 10; i++){
        dir_numeros = &numreos[i];
        cout << "El numero " << *dir_numeros << " esta en la posicion " << i << endl;
    }
    return 0;
}

