//14.01.23 by Matteo Fava
//File contenente il main del compitino

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //variabili
    array_ione ioni;
    array_elettrone elettroni;
    int err_i, err_e;
    ofstream risultati;

    //apri ofstream 
    risultati.open("data/risultati.out");

    //carica gli ioni
    ioni = load_ioni("data/ioni.dat", err_i);
    if (err_i != 0) return -1;
    //stampa il numero di ioni e la loro descrizione
    cout << "Caricati da file " << ioni.used << " ioni\n";
    cout << "Descrizione ioni: \n";
    risultati << "Caricati da file " << ioni.used << " ioni\n";
    risultati << "Descrizione ioni: \n";
    for (int i = 0; i<ioni.used; i++) {
        print_ione(ioni.raw[i]); 
        out_ione(risultati, ioni.raw[i]);
    }
    cout << "\n";
    risultati << "\n";

    //carica gli elettroni
    elettroni = load_elettroni("data/elettroni.dat", err_e);
    if (err_e != 0) return -1;
    //stampa il numero di elettroni, i primi 5 e gli ultimi 5
    cout << "Numero di elettroni caricati da file " << elettroni.used << endl;
    cout << "Primi 5 elettroni: \n";
    risultati << "Numero di elettroni caricati da file " << elettroni.used << endl;
    risultati << "Primi 5 elettroni: \n";
    for (int i = 0; i < 5; i++){
        print_elettrone(elettroni.raw[i]);
        out_elettrone(risultati, elettroni.raw[i]);
    } 
    cout << "Ultimi 5 elettroni: \n";
    risultati << "Ultimi 5 elettroni: \n";
    for (int i = elettroni.used-5; i < elettroni.used; i++){
        print_elettrone(elettroni.raw[i]);
        out_elettrone(risultati, elettroni.raw[i]);
    } 
    cout << "\n";
    risultati << "\n";

    //segna gli elettrni gia' catturati nell'istante 0
    int n_catt = aggiorna_esperimento(ioni, elettroni);
    cout << "Catturati " << n_catt << " elettroni al tempo t=0 e rimasti liberi " << elettroni.used-n_catt << "\n";
    risultati << "Catturati " << n_catt << " elettroni al tempo t=0 e rimasti liberi " << elettroni.used-n_catt << "\n";
    //stampa gli ioni
    cout << "Ioni aggiornati: \n";
    risultati << "Ioni aggiornati: \n";
    for (int i = 0; i<ioni.used; i++){
        print_ione(ioni.raw[i]);
        out_ione(risultati, ioni.raw[i]);
    }
    cout << endl;
    risultati << endl;

    //aggiorna le posizoni e e le velocita degli elettroni a t = 0.5
    calc_forze(elettroni, ioni, 0.5);
    //stampa una descrizione dei primi 5 elementi di elettroni non free
    cout << "Primi 5 elettroni dopo 0.5 secondi: \n";
    risultati << "Primi 5 elettroni dopo 0.5 secondi: \n";
    for (int i = 0; i<5; i++){
        if (elettroni.raw[i].free){
            print_elettrone(elettroni.raw[i]);
            out_elettrone(risultati, elettroni.raw[i]); 
        } 
    }
    cout << endl;
    risultati << endl;

    //aggiorna ancora gli ioni con gotcha
    n_catt += aggiorna_esperimento(ioni, elettroni);
    cout << "Catturati in totale " << n_catt << " elettroni e rimasti liberi " << elettroni.used-n_catt << "\n";
    cout << "Ioni: \n";
    risultati << "Catturati in totale " << n_catt << " elettroni e rimasti liberi " << elettroni.used-n_catt << "\n";
    risultati << "Ioni: \n";
    for (int i = 0; i<ioni.used; i++) {
        print_ione(ioni.raw[i]);
        out_ione(risultati, ioni.raw[i]);
    }
    cout << "\n";
    risultati << endl;

    

    //elimina array allocati dinamicamente e chiudi ofstream
    delete []ioni.raw;
    ioni.raw = NULL;
    delete []elettroni.raw;
    elettroni.raw = NULL;
    risultati.close();

    return 0;
}