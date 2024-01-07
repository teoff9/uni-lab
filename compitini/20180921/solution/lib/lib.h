//07.01.24 by Matteo Fava
//File contenente le dichiarazioni 

//definizione dello struct punto
struct punto {
    float x;
    float y;
    float w;
    float m;
    float f;
};

//definizione dello struct array_punto
struct array_punto {
    int used;
    int size;
    punto* raw;
};


//funzione che stampi a vide la descrizione di un punto
void print_punto(punto p, bool terna);

//funzione che stampi a video tutte le descrizioni in un array_punto
void print_all(array_punto pts, bool terna);

//funzione che calcoli il raggio di uno struct punto
//punto p: il punto in questione
float R(punto p);

//funzione che calcoli la F centripeta agente su un punto
//punto p: il punto in questione
float calc_f(punto p);

//funzione che calcoli la F centripeta agente su ogni punto
//array_punto pts: i punti in questione
float calc_f_all(array_punto pts);

//funzione che carichi un array_punto dato il nome di un file
//restituisce per side effect un err code: 0=tutto bene, -1= qualcosa e' andato storto
array_punto load_punti(char file_name[], int &err_code);

//funzione accessoria al sort_for_f che unisca due sottovettori
void merge_points(punto data[], int i, int m, int f);

//funzione che sorti l'array di punti in basse alle f centripete
//restituisce per side effect l'f min
void sort_for_f(punto data[], int init, int final);

//funzione che calcola f media di array_punto
float f_media(array_punto data);

//funzione che screma i valori in base all'f media
array_punto screma_for_f(array_punto data);