//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
#include "../lib/sorting/sorting.h"
#include "../lib/stats/stats.h"

#define N 150

int main(){
    ifstream inp;
    ofstream out;
    float data[N];
    int used;

    //open l'array
    inp.open("data/dati_header.dat");
    if (inp.fail()){
        cout << "Failed to read file" << endl;
        return -1;
    }

    //riempi l'array di dati leggendo used dal primo valore
    inp >> used;
    for (int i = 0; i < used; i++){
        if (!(inp >> data[i])){
            cout << "Something bad happened" << endl;
            return -1;
        }
    }
    inp.close();

    //ordina l'array
    selection_sort(data, used);

    //determina minimo, massimo, mediana, media, dev standard
    float min = data[0];
    float max = data[99];
    float median = mediana(data, used);
    float media = media_float(data, used);
    float dev = devstd_float(data, used);

    //stampa i valori richiesti
    out.open("data/output/risultati.dat");
    for (int i=0; i<3; i++){
        cout << "Valore " << i << ": " << data[i] << endl;
        out << data[i] << endl;
    }
    for (int i=99; i>96; i--){
        cout << "Valore " << i << ": " << data[i] << endl;
        out << data[i] << endl;
    }

    cout << "Minimo: " << min << endl;
    cout << "Massimo: " << max << endl;
    cout << "Mediana: " << median << endl;
    cout << "Media: " << media << endl;
    cout << "Deviazione Standard: " << dev << endl;


    //registrali nel file ~/data/output/out.dat
    out << min << endl;
    out << max << endl;
    out << median << endl;
    out << media << endl;
    out << dev << endl;


    return 0;
}