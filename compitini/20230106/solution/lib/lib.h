//q4.01.23 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate nel compitino

#include <fstream>
using namespace std;

struct evento {
double p1[4];// energia-momento particella 1 (E1, p1x, p1y, p1z)
double p2[4];// energia-momento particella 2 (E2, p2x, p2y, p2z)
bool segnale;// Segnale se 1|true, background se 0|false
double massainv; // Massa invariante
};

struct array_evento {
    int used;
    int size;
    evento* raw;
};

//funzione che carica i dati da file
array_evento load_eventi(char file_name[], int &err_code);

//conta i dati evento
int conta_eventi(array_evento eventi);

//calcola masse invarianti
void calcola_masse(array_evento eventi);

//stampa massa invariante di evento
void stampa_massinv(evento ev);

//stampa masse invarianti di primi n elementi, reverse bool
void stampa_masse(array_evento eventi, int n, bool reverse);

//mergia due sottoinsiemi di array_evento
void merge(evento data[], int i, int m, int f);

//merge sort in base a massainv
void sort_for_massinv(evento data[], int init, int final);

//calcola media
double calc_media(array_evento eventi, bool solo_segnali);

//calcola dev standard
double calc_dev_standard(array_evento eventi, bool solo_segnali);

//min segnali
double min(array_evento eventi);

//max segnali 
double max(array_evento eventi);

