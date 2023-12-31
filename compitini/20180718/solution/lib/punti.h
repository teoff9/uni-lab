//31.12.23 by Matteo Fava
//Contenente le dichiarazioni delle funzioni usate per la soluzione


//punto massa di coordinate x, y e massa m
struct punto_m {
    float x;
    float y;
    float m;
    float d;
};

//funzione che carica in un vettore allocato dinamicamente
//i punti massa contenuti nel file data/punti.dat
punto_m* load_punti(char file_name[], int &used, int &size);

//funzione che stampa i fields di un punto massa.
// bool d_flag : true->stampa anche d, false->no
void print_punto(punto_m p, bool d_flag);

//funzione che trovi l'ascissa minima
float find_x_min(punto_m data[], int used);

//funzione che trovi l'ascissa massima
float find_x_max(punto_m data[], int used);

//calcola i dati del centro di massa
punto_m centro_di_massa(punto_m data[], int &used);

//funzione che mergia due sottovettori contigui di un array di punti
void merge(punto_m data[], int i, int m, int f);

//funzione che sorta l'array di punti usando il merge sort
void sort(punto_m data[], int init, int final);