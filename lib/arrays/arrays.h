//12.12.23 by Matteo Fava

struct array_int{
    int used;
    int size;
    int* raw;
};

struct array_float{
    int used;
    int size;
    float* raw;
};

struct array_double{
    int used;
    int size;
    double* raw;
};

//carica i dati in un array da file_name
//err_code : 0 bene, 1 prob stream, 2 prob allocazione
array_int load_array_int(char file_name[], int& err_code);

//carica i dati in un array da file_name
//err_code : 0 bene, 1 prob stream, 2 prob allocazione
array_float load_array_float(char file_name[], int& err_code);

//carica i dati in un array da file_name
//err_code : 0 bene, 1 prob stream, 2 prob allocazione
array_double load_array_double(char file_name[], int& err_code);

//ridimensiona array di int, 
//restituisce 0 se tutto bene -1 se va male
int resize_array_int(array_int &myA, int new_size);

//ridimensiona array di float, 
//restituisce 0 se tutto bene -1 se va male
int resize_array_float(array_float &myA, int new_size);

//ridimensiona array di double, 
//restituisce 0 se tutto bene -1 se va male
int resize_array_double(array_double &myA, int new_size);

//ricerca valore in array int, restituisce l'indice
int search_value_int(array_int arr, int value);

//ricerca valore in array float, restituisce l'indice
int search_value_float(array_float arr, float value);

//ricerca valore in array double, restituisce l'indice
int search_value_double(array_double arr, double value);

//elimina valore di posizione i dell'array
void delete_element_int(array_int &arr, int where);

//elimina valore di posizione where dell'array
void delete_element_float(array_float &arr, int where);

//elimina valore di posizione where dell'array
void delete_element_double(array_double &arr, int where);