//17.11.2023 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
#include "../lib/spoletini/spoletini.h"

int main(){
    int n_dati = 0;
    char nome_f[15] = "data/data.dat";
    float* data = spoletini_file_float(nome_f, &n_dati);
    
    cout << n_dati << endl;
    cout << data[0] << endl << data[n_dati-1] << endl;

    return 0;
}