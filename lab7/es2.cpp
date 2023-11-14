//14.11.23 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
#include "../lib/sorting/sorting.h"
#include "../lib/stats/stats.h"

//Funzione che calcoli le statistiche richieste
// prova 
void calcolaStats(float data[], int used, float* min, float* max, float* median, float* med, float* stddev);

int main(){
    ifstream inp;
    ofstream out;
    int used;
    float* data;
    float min, max, median, med, stddev;

    //leggi il numero di dati
    inp.open("data/dati_header.dat");
    if (inp.fail()){
        cout << "Failed to read file." << endl;
        return -1;
    }
    inp >> used;

    //carica i dati su array di float
    data = new float[used];
    for (int i = 0; i<used; i++){
        inp >> data[i];
    }
    inp.close();
    
    //ordina l'array usando il selection sort
    selection_sort(data, used);

    //calcola max, min, media, mediana e dev std
    calcolaStats(data, used, &min, &max, &median, &med, &stddev);
    
    //stampa i dati e salvali in output/out_2.dat
    out.open("data/output/out_2.dat");
    for (int i=0; i<3; i++){
        cout << "Valore " << i << ": " << data[i] << endl;
        out << data[i] << endl;
    }
    for (int i=used-1; i>used-4; i--){
        cout << "Valore " << i << ": " << data[i] << endl;
        out << data[i] << endl;
    }
    
    cout << "Minimo: " << min << endl;
    cout << "Massimo: " << max << endl;
    cout << "Mediana: " << median << endl;
    cout << "Media: " << med << endl;
    cout << "Deviazione Standard: " << stddev << endl;

    out << min << endl;
    out << max << endl;
    out << median << endl;
    out << med<< endl;
    out << stddev << endl;



    //rimuovi array allocato dinamicamente
    delete [] data;

    return 0;
}



void calcolaStats(float data[], int used, float* min, float* max, float* median, float* med, float* stddev){
    *min = data[0];
    *max = data[used-1];
    *median = mediana(data, used);
    *med = media_float(data, used);
    *stddev = devstd_float(data, used);
}