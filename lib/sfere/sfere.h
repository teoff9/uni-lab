//28.11.23 by Matteo Fava

//dichiarazione di sfera
struct sfera {
    float diam;
    char color;
    float exact;
    float atoll;
    float discr;
};

//dichiarazione di array_sfera
struct array_sfera {
    int size;
    int used;
    sfera* raw;
};

//load the array of spheres loading the file
//char file_name[] and returning for side effect used.
array_sfera load_spheres(char file_name[]);


//funzione che unisce due sottovettori di un array di sfere
//sfera data[]: array
//int i : indice iniziale
//int m : indice mediano
//int f : indice finale
void merge(sfera data[], int i, int m, int f);


//funzione che implementa il mergesort per un array di sfere
//sfera data[]: array
//int init: indice iniziale
//int final : indice finale
void sort(sfera data[], int init, int final);


//funzione che elimina l'elemento di index int where 
//dall'array di sfere data. Restituisce per side effect 
//la nuova lunghezza dell'array.
//sfera data[] : array di sfere
//int &used : used dell'array
//int where : posizione dell'elemento da eliminare
void delete_element(array_sfera &data, int where);


//funzione che fa il resize di un vettore di sfere. 
//Restituisce un codice: 0 = ha funzionato, -1 = qualcosa non ha funzionato
//sfera data[] : array di sfere
//int &used : used dell'array
//int new_size : new size dell'array
int resize_array(array_sfera &myA, int new_size);


//funzione che stampa a schermo i valori di una sfera sf
void print_sfera(sfera sf);


//funzione che stampa a schermo i primi tre e gli ultimi tre elementi
//di un vettore di sfere data
void print_sfera_sample(array_sfera data);