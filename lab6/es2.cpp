//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
//#include "../lib/stats/stats.h"

#define NN 150

int main(){
    ifstream data;
    float vdiams[NN];
    char vcols[NN];
    int used = 0;

    //apri data
    data.open("data/sfere.dat");
    if (data.fail()){
        cout << "Failed to read file" << endl;
        return -1;
    }

    //carica i dati nei due array con un ciclo spoletini
    while (used < 150 && data >> vdiams[used -1] && data >> vcols[used - 1]){
        used ++;
    }

    cout << used << endl;
    //calcola media e dev standard
    
    
    return 0;
}