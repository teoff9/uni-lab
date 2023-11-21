//21.11.23 by Matteo Fava

#include <iostream>
#include <fstream>
using namespace std;

//crivello di eratostene, applicato a v
//quando l'indice e' primo
//bool v[] : vettore di max+1 values
//int max : used e' max + 1
//restituisce n_primi per side effect
void crivello_eratostene(bool v[], int max, int* n);

int main(){
    int max;
    bool* values = NULL;
    int n_primi = 0;
    ofstream out;

    //richiedi n-max
    do { cin >> max;} while (max <=1);

    //alloca dinamicamente il vettore max+1
    values = new bool[max+1];

    //applica il crivello di eratostene
    crivello_eratostene(values, max, &n_primi);

    //stampa i dati richiesti su data/output/primi.dat 
    out.open("data/output/primi.dat");
    out << "Il valore n-max: " << max << endl;
    out << "N primi: " << n_primi << endl;
    out << "Densita Np / Nmax: " << (float)(max-1)/n_primi << endl;
    out << "Primi determinati: " << endl;
    for (int i = 0; i < max+1; i++){
        if (values[i]){
            out << i << endl;
        }
    }
    out.close();

    //elimina il vettore values
    delete []values;

    return 0;
}


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