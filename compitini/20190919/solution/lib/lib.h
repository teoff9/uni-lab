//q4.01.23 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate nel compitino

#include <fstream>
using namespace std;

struct ione {
float x; // coordinata x dello ione
float y; // coordinata y dello ione
float r; // raggio dello ione
int carica; //carica dello ione
};

struct elettrone {
float x; // coord. x dell’elettrone
float y; // coord. y dell’elettrone
float vx;// comp. x velocita‘
float vy; // comp. y velocita‘
bool free; // e‘ libero?
};

struct array_ione {
    int size, used;
    ione* raw;
};

struct array_elettrone {
    int size, used;
    elettrone* raw;
};

//funzione che stampa i valori di uno ione
void print_ione(ione ion);

//funzione che stampa i valori di un elettrone
void print_elettrone(elettrone elett);

//funzione che carica in un vettore gli ioni
array_ione load_ioni(char file_name[], int &err_code);

//funzione che carica in un vettore gli elettroni
array_elettrone load_elettroni(char file_name[], int &err_code);

//funzione che calcoli la distanza tra uno ione e un elettrone
float distanza(elettrone elettrone, ione ione);

//controlla se l'elettrone si trova nel cerchio di cattura di uno ione etc etc
int gotcha(elettrone *el, array_ione ions);

//aggiorna gli elettroni e gli ioni catturati nell'istante 0
//restituisce il numero di elettroni catturati
int aggiorna_esperimento(array_ione ioni,array_elettrone elettroni);

//calcola le nuove velocita' degli elettroni free
void calc_forze(array_elettrone elettroni, array_ione ioni, float dt);

//funzione che stampa il valore di uno ione su file
void out_ione(ofstream& ris, ione ion);

//funzione che stampa il valore di un elettrone su file
void out_elettrone(ofstream& ris, elettrone elett);



