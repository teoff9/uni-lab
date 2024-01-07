//07.01.24 by Matteo Fava
//File contenente il main del programma

#include "lib/lib.h"
#include <fstream>
#include <iostream>
using namespace  std;


int main() {
    int err;
    array_punto data;
    ofstream out;
    float f_min = 0;

    //apri il file data/output.dat
    out.open("data/output.dat");

    //carica data dei dati di data/rotanti.dat
    data = load_punti("data/rotanti.dat", err);
    if (err != 0) {
        return -1;
    }

    //stampa i dati richiesti per il primo punto e caricali nel file
    print_all(data, false);
    cout << "Caricati " << data.used << " punti.\n\n";

    //calcola tutte le f_centripete
    calc_f_all(data);
    //sorta i punti in base alle f
    sort_for_f(data.raw, 0.0, data.used-1);
    //trova f min
    f_min = data.raw[0].f;
    //stampa i dati richiesti
    print_all(data, true);
    
    //calcola f media
    cout << "F media = " << f_media(data) << endl;
    //trova i punti da eliminare
    array_punto elim = screma_for_f(data);
    print_all(elim, true);
    cout << "Eliminati " << elim.used << " punti." << endl;


    //elimina data.raw e elim.raw
    delete []data.raw; data.raw = NULL;
    delete []elim.raw; elim.raw = NULL;
    //chiudi out
    out.close();

    return 0;
}