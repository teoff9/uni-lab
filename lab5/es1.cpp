//31.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "lib_statistica.h"

//Prende un array, n_data, n_used e ritorna il numero di pari (per i dispari fare n-pari)
int conta_pari(int[], int, int);

//determina se un array contiene una sequenza di z valori int maggiori di M
bool esistenza_sequenza(int[], int, int, int);


int main(){
    float data[6] = {1., 2., 3., 4., 5., 6.};

    cout << mediana(data, 6) << endl;



    return 0;
}

int conta_pari(int v[], int n, int used){
    int pari = 0;
    for (int i=0; i < used; i++){
        if (v[i]%2 == 0){
            pari ++;
        }
    }

    return pari;
}

bool esistenza_sequenza(int v[], int used, int z, int M){
    int j = 0;
    for (int i=0; i<used; i++){
        if (v[i] > M){
            j++;
        }
        if (j==z) return 1;
    }

    return 0;
}