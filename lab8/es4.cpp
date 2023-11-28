//21.11.23 by Matteo Fava

#include <fstream>
#include <iostream>
using namespace std;
#include "../lib/numbers/numbers.h"
#include "../lib/spoletini/spoletini.h"
#include "../lib/edit_array/edit_array.h"

//delete entry
void delete_entry(int i, int data[], int* used, bool p[],  bool s[]);

int main(){
    ifstream inp;
    ofstream out;
    int used = 0;
    char n_f[16] = "data/interi.dat";
    int* data = spoletini_file_int(n_f, used);
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
    for (int i = 0; i< used; i++){
        isPrime[i] = false;
        isSquare[i] = false;
    }
    for (int i = 0; i< used; i++){
        if (is_prime(data[i])) isPrime[i] = true;
        if (is_perfect_square(data[i])) isSquare[i] = true;
    }

    //elimina dal vettore data tutti i num
    //non primi e non quadrati perfetti
    for (int i = 0; i<used; i++){
        if (!isPrime[i] && !isSquare[i]){
            delete_entry(i, data, &used, isPrime, isSquare);
            i --;
        }
    }


    //stampa a video e su risultati.dat i valori sopravvissuti
    out.open("data/output/risultati.dat");
    for (int i = 0; i < used; i++){
        cout << data[i] << "    " << isPrime[i] << "    " << isSquare[i] << endl;
        out << data[i] << "    " << isPrime[i] << "    " << isSquare[i] << endl;
    }
    out.close();

    //pulisci tutti gli array
    delete []data; delete []isPrime; delete []isSquare;
    data = NULL; isPrime = NULL; isSquare = NULL;


    return 0;
}

void delete_entry(int i, int data[], int* used, bool p[],  bool s[]){
    int u_p = *used;
    int u_s = *used;
    
    delete_entry_swap_int(data, used, i);
    delete_entry_swap_bool(p, &u_p, i);
    delete_entry_swap_bool(s, &u_s, i);
}
