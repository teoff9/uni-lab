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
int resize_array_int(array_float &myA, int new_size);

//ridimensiona array di double, 
//restituisce 0 se tutto bene -1 se va male
int resize_array_int(array_double &myA, int new_size);