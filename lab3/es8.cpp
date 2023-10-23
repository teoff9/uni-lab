//18.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "alg_euclide.h"


int main(){
    int a, b = 0;
    
    cin >> a >> b;
    
    if (a<0 || b<0){
        cout << "Non funziono su numeri negativi" << endl;
    } else if (a==0 || b==0){
        cout << "Operazione non definita" << endl;
    } else {
        cout << alg_euclide(a,b) << endl;
    }

    return 0;
}