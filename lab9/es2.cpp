//28.11.23 by Matteo Fava

#include <iostream>
#include "../lib/numbers/numbers.h"
#include "../lib/spoletini/spoletini.h"
using namespace std;

//Funzione che restituisce un array di numeri primi
//selezionandoli da int data[] di dati used, int used.
//Restituisce per side effect int n_dati
int* select_primes(int data[], int used, int& n_primes);

int main(){
    int* v = NULL;
    int* vp =  NULL;
    int u = 0;
    int np = 0;
    
    v = spoletini_file_int("data/interi.dat", u);
    vp = select_primes(v, u, np);

    delete []v; delete []vp;
    v = NULL;
    vp = NULL;

    return 0;
}

int* select_primes(int data[], int used, int& n_primes){
    int* vp = NULL;
    
    //conta numeri primi
    for (int i = 0; i<used; i++){
        if (is_prime(data[i])) n_primes++;
    }

    //carica i numeri primi
    vp = new int[n_primes];
    int j = 0;
    for(int i = 0; i<used; i++){
        if (is_prime(data[i])){
            vp[j] = data[i];
            cout << j << " " << data[i]  << " " << vp[j] << endl;
            j++;
        }
    }
    
    return vp;
}