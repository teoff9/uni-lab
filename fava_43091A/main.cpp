//26.01.24 by Matteo Fava
//File contenente il main dell'esame pratico

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //variabili
    ofstream ris;
    int err;
    array_giocatore iscritti;
    array_mano punteggi;
    array_mano classifica;

    //apri ofstream
    ris.open("data/risultati.dat");


    //ES 1
    cout << "\nES 1\n"; ris << "ES 1\n";
    //carica i giocatori
    iscritti = load_giocatori("data/iscritti.dat", err);
    if (err != 0) return -1;
    //stampa a video i dati richiesti e anche su file
    cout << "Totale iscritti = " << iscritti.used << endl;
    cout << "Di cui " << count_pro(iscritti) << " professionisti e " << iscritti.used-count_pro(iscritti) << " non professionisti\n";
    ris << "Totale iscritti = " << iscritti.used << endl;
    ris << "Di cui " << count_pro(iscritti) << " professionisti e " << iscritti.used-count_pro(iscritti) << " non professionisti\n";
    print_iscritti_sample(iscritti, 3, false);
    out_iscritti_sample(iscritti, 3, false, ris);
    cout << endl; ris << endl;


    //ES 2
    cout << "ES 2\n"; ris << "ES 2\n";
    //carica i punteggi da file
    punteggi = load_mani("data/punteggi.dat", err);
    if (err != 0) return -1;
    //stampare a video le richieste e su file
    cout << "Caricate " << punteggi.used << " mani in totale\n";
    ris << "Caricate " << punteggi.used << " mani in totale\n";
    print_mani_sample(punteggi, 3);
    out_mani_sample(punteggi, 3, ris);
    cout << endl; ris << endl;


    //ES 3
    cout << "ES 3\n"; ris << "ES 3\n";
    //aggiorna i campi di giocatori con i punteggi registrati al torneo
    aggiorna_giocatori(iscritti, punteggi);
    //stampa i primi 3 e gli ultimi 3 giocatori in versione completa a video e a file
    cout << "Dopo aver aggiornato i giocatori con i punteggi:\n";
    ris << "Dopo aver aggiornato i giocatori con i punteggi:\n";
    print_iscritti_sample(iscritti, 3, true);
    out_iscritti_sample(iscritti, 3, true, ris);
    cout << endl; ris << endl;

    //ES 4
    cout << "ES 4\n"; ris << "ES 4\n";
    //sorta in ordine decrescente i punteggi dei giocatori
    merge_sort_giocatori(iscritti.raw, 0, iscritti.used-1);
    //stampa a video e a file le descrizioni di tutti i giocatori
    cout << "Descrizione di tutti i giocatori dopo il sort: \n";
    ris << "Descrizione di tutti i giocatori dopo il sort: \n";
    for (int i = 0; i<iscritti.used; i++) {
        print_giocatore(iscritti.raw[i]);
        out_giocatore(iscritti.raw[i], ris);
    }
    cout << endl; ris << endl;


    //ES 5
    cout << "ES 5\n"; ris << "ES 5\n";
    //carica la classifica da file
    classifica = load_mani("data/classifica.dat", err);
    //aggiorna la classifica nazionale
    aggiorna_classifica(iscritti, classifica);
    //sorta l'array classifica con il merge sort
    merge_sort_mani(classifica.raw, 0, classifica.used-1);
    //stampa la classifica aggiornata dopo il mitico torneo del Masnago!! a video e a file
    cout << "Classifica aggiornata:\n";
    ris << "Classifica aggiornata:\n";
    for (int i = 0; i<classifica.used; i++) {
        print_mano(classifica.raw[i]);
        out_mano(classifica.raw[i], ris);
    }


    //elimina array allocati dinamicamente
    delete []iscritti.raw;
    iscritti.raw = NULL;
    delete []punteggi.raw;
    punteggi.raw = NULL;
    delete []classifica.raw;
    classifica.raw = NULL;
    //chiudi ofstram
    ris.close();

    return 0;
}