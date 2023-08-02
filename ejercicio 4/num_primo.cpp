/*
ejercicio en clase 
Nelson García 22434
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << "ingrese un numero" << endl;
    bool primo = true;
    cin >> num;
    if(num > 0){
        for(int i = 2; i <= (num / 2); i++){
            if(num % i == 0){
                primo = false;
            }
        }
    }
    else{
        cout << "el numero no es valido" << endl;
    }
    if(primo == false)
    {
        cout << "el numero " << num << " no es primo" << endl;
    }
    else{
        cout << "el numero " << num << " es primo" << endl;
    }
    system("pause");
    return 0;
}