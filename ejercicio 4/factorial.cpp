/*
ejercicio en clase 
Nelson García 22434
*/

#include <iostream>
using namespace std;

int main()
{
    
    int num = 0;
    int num_2 = 1;
    cout << "ingrese un numero" << endl;
    cin >> num;
    if(num >= 0){
        for(int i = 1; i <= num; i++){
            num_2 = num_2 * i;
        }
    }
    cout << "el factorial del numero " << num << " es " << num_2 << endl;
    system("pause");
    return 0;
}