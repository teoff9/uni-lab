//16.01.23 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate nel compitino

#include <fstream> using namespace std;

struct misura {
int t; //instante della misura in secondi
int mis; //0 o 1 rilevato dagli strumenti
float temp; //temperatura del qubit in kelvin
char stato; //nome della configurazione
};

struct array_misura {
    int used;
    int size;
    misura* raw;
};

//funzione che carica le misure in un array allocato dinamicamente
array_misura load_misure(char file_name[], int &err_code);

//funzione che stamp i valori di una misura
void print(misura mis);

//funzione che stampa i primi int n e gli ultimi int n misure di array_misura
void print_sample(array_misura misure, int n);

//funzione che elimina un elemento da array_threshold
void delete_misura(array_misura &misure, int where);

//funzione che elimina le misure che hanno temp > float threshold
void delete_by_temp(array_misura &misure, float threshold);

///funzione che calcola la frequenza di una misura, tra indice in e indice fin
int frequenza_by_value(array_misura misure, int m, int in, int fin);

//funzione che faccia il merge di due sottovettori contigui di array_misura
void merge(misura data[], int i, int m, int f);

//funzione che faccia il merge sort di array_misura
void sort(misura data[], int init, int final);

//funzione che calcola gli stati
void calc_stati(array_misura misure);
