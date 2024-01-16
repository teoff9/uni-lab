//16.01.23 by Matteo Fava
//File contenente il main del compitino

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    //variabili
    array_misura misure;
    int err;
    ofstream results;

    //apri results.out
    results.open("data/results.out");

    //carica le misure da data/dati.dat
    misure = load_misure("data/dati.dat", err);
    if (err != 0) return -1;
    //stampa i dati richiesti dal primo punto
    cout << "Caricate " << misure.used << " misurazioni\n";
    results << "Caricate " << misure.used << " misurazioni\n";
    print_sample(misure, 3);
    int n = 3;
    results << "Prime " << n << " misure:\n";
    for (int i = 0; i<n; i++){
        results << "T = " << misure.raw[i].t << " | Mis = " << misure.raw[i].mis << " | Temp = " << misure.raw[i].temp << " | Stato = " << misure.raw[i].stato << endl;
}
    results << "Ultime " << n << " misure:\n";
    for (int i = misure.used-n; i<misure.used; i++){
        results << "T = " << misure.raw[i].t << " | Mis = " << misure.raw[i].mis << " | Temp = " << misure.raw[i].temp << " | Stato = " << misure.raw[i].stato << endl;
    }
    results << "\n";



    //elimina dall'array le misure con temp > 30
    delete_by_temp(misure, 30);
    //stampa i dati richiesti
    cout << "Rimaste " << misure.used << " misure\n";
    cout << "Frequenza 0: " << frequenza_by_value(misure, 0, 0, misure.used-1) << " | Frequenza 1: " << frequenza_by_value(misure, 1, 0, misure.used-1) << endl;
    results << "Rimaste " << misure.used << " misure\n";
    results << "Frequenza 0: " << frequenza_by_value(misure, 0, 0, misure.used-1) << " | Frequenza 1: " << frequenza_by_value(misure, 1, 0, misure.used-1) << endl;

    //ordina l'array in ordine crescente di temp
    sort(misure.raw, 0, misure.used-1);
    //calcola stati
    calc_stati(misure);
    //stampa dati richiesti
    for (int i = 0; i<misure.used; i++){
        print(misure.raw[i]);
    }



    //pulisci gli array
    delete []misure.raw;
    misure.raw = NULL;
    //chiudi results
    results.close();

    return 0;
}