//q4.01.23 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate nel compitino


struct bersaglio {
float x,y; // coordinate bersaglio
float c; // capacita‘ di corazza
bool distr; // stato (distrutto o meno)
};

struct colpo {
float theta,phi; // alzo e angolo di tiro
float xf,yf; // coordinate impatto
bool hit; // a segno
};

struct array_bersaglio {
    int used;
    int size;
    bersaglio* raw;
};

struct array_colpo {
    int used;
    int size;
    colpo* raw;
};


//array che carica dinamicamente un array di colpi
array_colpo load_colpi(char file_name[], int &err_code);

//array che carica dinamicamente un array di bersagli
array_bersaglio load_bersagli(char file_name[], int &err_code);

//funzione che conta i bersagli distrutti
int count_distrutti(array_bersaglio bersagli);

//funzione che printa colpo
void print_colpo(colpo c);

//funzione che printa bersagli
void print_bersaglio(bersaglio b);

//funzione che stampa i primi tre bersagli distrutti e i primi tre non distrutti
void stamp_b(array_bersaglio bersagli);

//stampa primi tre e ultimi tre colpi
void print_sample_colpi(array_colpo colpi);

//aggiorna bersagli
void aggiorna_bersagli(array_bersaglio &bersagli, array_colpo &colpi, int &distrutti, int &s);