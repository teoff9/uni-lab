//26.01.24 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate durante l'esame pratico

#include <fstream>
using namespace std;

struct giocatore {
int cod; //codice giocatore
bool is_pro; //true per punteggio professionista
int tot_punt; //punteggio ottenuto al torneo del Masnago
int nmani; //mani giocate al torneo del Masnago
};

struct mano {
int cod; //codice giocatore
int punti; //punti mano al torneo del Palio/punti classifica nazionale.
};

struct array_giocatore {
    int size, used;
    giocatore* raw;
};

struct array_mano {
    int size, used;
    mano* raw;
};

//funzione per stampare a video il giocatore
void print_giocatore(giocatore gioc);

//funzione per stampare a video la mano
void print_mano(mano m);

//funzione per caricare in array_giocatore da file
array_giocatore load_giocatori(char file_name[], int &err_code);

//funzione per caricare in array_mano da file
array_mano load_mani(char file_name[], int &err_code);

//funzione per contare i professionisti in un array di giocatori
int count_pro(array_giocatore iscritti);

//funzione che stampa a video le specifiche dei primi n e ultimi n giocatori
void print_iscritti_sample(array_giocatore iscritti, int n, bool full);

//funzione che stampa a video le specifiche dei primi e ultimi n punteggfi
void print_mani_sample(array_mano mani, int n);

//funzione che aggiorna i campi dei giocatori
void aggiorna_giocatori(array_giocatore iscritti, array_mano punti);

//funzione accessoria per il sort dell'array di giocatori
//che performa il merge di due sottovettori contigui
void merge_giocatori(giocatore data[], int i, int m, int f);

//funzione che sorta l'array di giocatori in ordine decrescente (dal punteggio piu' alto al piu' piccolo)
//l'array di giocatori usando il merge sort
void merge_sort_giocatori(giocatore data[], int init, int final);

//funzione che aggiorna la classifica nazionale di ogni giocatore che ha partecipato al torneo
//il punteggio viene aggiornato se se solo se nmani == 5
void aggiorna_classifica(array_giocatore iscritti, array_mano classifica);

//funzione accessoria per il sort dell'array di mani
//che performa il merge di due sottovettori contigui
void merge_mano(mano data[], int i, int m, int f);

//funzione che sorta l'array di mani in ordine decrescente (dal punteggio piu' alto al piu' piccolo)
//l'array di giocatori usando il merge sort
void merge_sort_mani(mano data[], int init, int final);

//funzione per stampare a file il giocatore
void out_giocatore(giocatore gioc, ofstream& out);

//funzione per stampare a file la mano
void out_mano(mano m, ofstream& out);

//funzione che stampa a file le specifiche dei primi n e ultimi n giocatori
void out_iscritti_sample(array_giocatore iscritti, int n, bool full, ofstream& out);

//funzione che stampa a file le specifiche dei primi e ultimi n punteggfi
void out_mani_sample(array_mano mani, int n, ofstream& out);