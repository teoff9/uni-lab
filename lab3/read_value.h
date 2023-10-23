//18.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

//Dati un int min e un in max chiede all'utente un int
//fino a che non risulti incluso nell'intervallo min->max
int read_value(int,int);

int read_value(int min, int max){
    int val = 0;
    do{
        cin >> val;
    } while(val!=0 && (val<min || val>max));
    cout << "Letto il valore " <<  val << endl;
    return val;
}