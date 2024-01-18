//14.01.23 by Matteo Fava
//File contenente il main del compitino

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //variabili
    ofstream risultati;
    int err;
    array_evento eventi;

    //apri ofstream
    risultati.open("data/risultati.dat");

    //carica i punti
    eventi = load_eventi("data/eventi.dat", err);
    if (err != 0) return -1;
    //stampa i dati richiesti
    cout << "Caricati " << eventi.used << " eventi\n";
    cout << "Eventi n = " << conta_eventi(eventi) << " e " << eventi.used - conta_eventi(eventi) << " non eventi\n";
    cout << "Percentuali richieste " << (double)100*conta_eventi(eventi)/eventi.used << " e non eventi " << (double)100*(eventi.used - conta_eventi(eventi))/eventi.used << endl;
    //stampa i dati richiesti
    risultati << "Caricati " << eventi.used << " eventi\n";
    risultati << "Eventi n = " << conta_eventi(eventi) << " e " << eventi.used - conta_eventi(eventi) << " non eventi\n";
    risultati << "Percentuali richieste " << (double)100*conta_eventi(eventi)/eventi.used << " e non eventi " << (double)100*(eventi.used - conta_eventi(eventi))/eventi.used << endl;

    //calcola masse invarianti
    calcola_masse(eventi);
    //stampa masse dei primi 10 eventi
    stampa_masse(eventi, 10, false);


    //ordina elementi
    sort_for_massinv(eventi.raw, 0, eventi.used-1);
    cout << "Primi 4 elementi:\n";
    stampa_masse(eventi, 4, false);
    cout << "Ultimi 4 elementi:\n";
    stampa_masse(eventi, 4, true);


    //statistiche
    cout << "Media eventi segnale e dev standard: " << calc_media(eventi, true) << " | " << calc_dev_standard(eventi, true) << endl;
    cout << "Media eventi totali e dev standard: " << calc_media(eventi, false) << " | " << calc_dev_standard(eventi, false) << endl;
    cout << "Massimo e minimo di segnali: " << min(eventi) << " | " << max(eventi) << endl;
    cout << "Massimo e minimo totali " << eventi.raw[0].massainv << " | " << eventi.raw[eventi.used-1].massainv << endl;

    risultati << "Media eventi segnale e dev standard: " << calc_media(eventi, true) << " | " << calc_dev_standard(eventi, true) << endl;
    risultati << "Media eventi totali e dev standard: " << calc_media(eventi, false) << " | " << calc_dev_standard(eventi, false) << endl;
    risultati << "Massimo e minimo di segnali: " << min(eventi) << " | " << max(eventi) << endl;
    risultati << "Massimo e minimo totali " << eventi.raw[0].massainv << " | " << eventi.raw[eventi.used-1].massainv << endl;


    //pulisci array dinamici
    delete []eventi.raw;
    eventi.raw = NULL;

    //chiudi ris
    risultati.close();

    return 0;
}