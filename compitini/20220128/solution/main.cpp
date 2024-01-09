//09.01.23 by Matteo Fava
//File contenente il main del compitino

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //variabili
    array_packets data;
    int err;
    ofstream risultati, messaggio, corrotti;

    //apri gli ofstream
    risultati.open("data/risultati.dat");
    messaggio.open("data/messaggio.out");
    corrotti.open("data/corrotti.out");


    //carica i dati
    data = load_data("data/data.dat", err);
    //continua se nn ci sono stati problemi nel caricamento dell'array
    if (err != 0){
        return -1;
    }

    //stampa i dati richiesti dal primo punto
    cout << "\nCaricati " << data.used << " data.\n";
    cout << count_by_db(data, 90) << " pacchetti hanno una qualita' >= 90.\n";
    cout << data.used - count_by_db(data, 90) << " pacchetti hanno una qualita' <= 90.\n\n";
    //stampali anche su data/risultati.dat
    dump_num_corretti(data, risultati);

    //rimuovi dai pacchetti quelli difettosi e stampali su data/corrotti.out
    remove_corrotti(data, 90, corrotti);
    //sortali in ordine di timestamp crescente
    merge_sort_packets_by_timestamp(data.raw, 0, data.used-1);
    print_sample(data, 5);
    //stampa sample anche in risultati.dat
    dump_sample(data, 5, risultati);

    //stampa il messaggio a video
    print_message(data);
    //stampa il messaggio su messaggio.out
    dump_message(data, messaggio);

    //chiudi ofstream aperti
    risultati.close();
    corrotti.close();
    messaggio.close();
    //elimina gli array dinamici
    delete []data.raw;
    data.raw = NULL;

    return 0;
}