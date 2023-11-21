//21.11.23 by Matteo Fava
// Definizioni delle funzioni

#include <cmath>
#include "numbers.h"

void crivello_eratostene(bool v[], int max, int* n){
    
    //inizializza la lista a true da indice = 2
    for (int i=2; i<max+1;i++){
        v[i] = true;
    }

    //due loop annidati:
        // 1: che trova il primo valore true.
        // 2: elimina i multipli dell'indice trovato '1.
    for (int i = 2; i < max+1; i++){
        if (v[i]){
            (*n) ++;
            for (int k = 2; k*i < max+1; k++){
                v[k*i] = false;
            }
        }
    }
}

bool is_prime(int n){
    if (n<=1){
        return false;
    } else {
        for (int i = 2; i<n; i++){
            if (n%i == 0){
                return false;
            }
        }
        return true;
    }
}

bool is_perfect_square(int n){
    if (n>=1 && n-pow((int)sqrt(n), 2.0) == 0){
        return true;
    } else {
        return false;
    }
}
