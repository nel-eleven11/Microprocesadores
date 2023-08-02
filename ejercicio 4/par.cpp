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
    cin >> num;
    if (num % 2 == 0)
    {
        cout << "el numero es par" << endl;
    }
    else
    {
        cout << "el numero es impar" << endl;
    }
    system("pause");
    return 0;
}