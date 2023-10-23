//18.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "alg_euclide.h"

//Funzione che restituisce l'MCD di due int a,b
int MCD(int,int);

int main(){
    int a,b;
    int mcd;
    cin >> a >> b;
    if (a>0 && b>0){
        mcd = MCD(a,b);
        cout << mcd << endl;
        cout << "Checking: a%" << mcd << " = " << a%mcd << endl;
        cout << "Checking: b%" << mcd << " = " << b%mcd << endl;
    } else {
        cout << "Numeri invalidi. \n quitting.. \n";
    }

    return 0;
}


int MCD(int a, int b){
    return alg_euclide(a,b);
}