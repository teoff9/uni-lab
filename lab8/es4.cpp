//21.11.23 by Matteo Fava

#include <fstream>
#include <iostream>
using namespace std;
#include "../lib/numbers/numbers.h"
#include "../lib/spoletini/spoletini.h"
#include "../lib/edit_array/edit_array.h"

//delete entry
void delete_entry(int i, int data[], int* used, bool p[], int* u_p, bool s[], int* u_s);

void init_false(bool v[], int used){
    for (int i = 0; i< used; i++){
        v[i] = false;
    }
}

int main(){
    ifstream inp;
    ofstream out;
    int used = 0;
    char n_f[16] = "data/interi.dat";
    int* data = spoletini_file_int(n_f, &used);
    bool* isPrime = NULL;
    bool* isSquare = NULL;

    //check che data non sia NULL
    if (data == NULL){
        cout << "Something went wrong loading the file" << endl;
        return -1;
    }

    //popola isPrime e isSquare
    isPrime = new bool[used];
    isSquare = new bool[used];
    init_false(isPrime, used);
    init_false(isSquare, used);
    for (int i = 0; i< used; i++){
        if (is_prime(data[i])) isPrime[i] = true;
        if (is_perfect_square(data[i])) isSquare[i] = true;
    }


    //elimina dal vettore data tutti i num
    //non primi e non quadrati perfetti
    int u_prime = used;
    int u_square = used;
    int u = used;
    for (int i = 0; i<u; i++){
        if (!isPrime[i] && !isSquare[i]){
            delete_entry(i,data, &used,isPrime, &u_prime, isSquare, &u_square);
        }
    }
    cout << used << endl << u_prime << endl << u_square << endl;

    //stampa a video e su risultati.dat i valori sopravvissuti
    out.open("data/output/risultati.dat");
    for (int i = 0; i < used; i++){
        //cout << data[i] << "    " << isPrime[i] << "    " << isSquare[i] << endl;
        out << data[i] << "    " << isPrime[i] << "    " << isSquare[i] << endl;
    }

    //pulisci tutti gli array
    delete []data; delete []isPrime; delete []isSquare;
    data = NULL; isPrime = NULL; isSquare = NULL;


    return 0;
}

void delete_entry(int i, int data[], int* used, bool p[], int* u_p, bool s[], int* u_s){
    delete_entry_shift_bool(p, u_p, i);
    delete_entry_shift_bool(s, u_s, i);
    delete_entry_shift_int(data, used, i);
}