/*
ejercicio en clase 
Nelson García 22434
*/

#include <iostream>
using namespace std;

int potencia(int base, int exp){
    int num = 1;
    for(int i = 0; i < exp; i++){
        num *= base;
    }
    return num;
}

int main()
{
    int num = 0;
    string binario = "";
    cout << "ingrese un numero de 0 a 15" << endl;
    bool primo = true;
    cin >> num;
    if(num < 0 || num > 15){
        cout << "numero invalido" << endl;
    }
    else{
        for(int i = 3; i >= 0; i--){
            if(num >= potencia(2,i)){
                binario += "1";
                num -= potencia(2,i);
            }
            else{
                binario += "0";
            }
        }
        cout << "el numero " << num << " en binario es: "<< endl;
        cout << binario << endl;
    }
    system("pause");
    return 0;
}

