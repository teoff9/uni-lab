//17.11.23 by Matteo Fava

//Definizioni delle funzioni presenti in spoletini.h

#include "spoletini.h"
#include <fstream>
#include <iostream>
using namespace std;


float* spoletini_file_float(char file_name[], int* n_dati){
    float* data = NULL;
    ifstream inp;
    float tmp;
    *n_dati = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load file." << endl;
        return NULL;
    }

    //conta il numero di valori
    while (inp >> tmp){
        *n_dati += 1;
    }
    inp.close();

    //carica i dati
    inp.open(file_name);
    data = new float[*n_dati];
    for (int i = 0; i<*n_dati; i++){
        inp >> data[i];
    }
    inp.close();

    return data;
}