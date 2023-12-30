//27.10.23 by Matteo Fava
//library containing sorting algorithms


//Funzione che restituisca l'index del valore minimo.
//data: array di dati float
//i: index del primo elemento da cui parte la ricerca
//j: index dell'ultimo elemento in cui finisce la ricerca
int pos_of_min_float(float data[], int i, int j);


//Algoritmo che implementa il selection sort.
//data: array di dati float
//used: int che indica il numero di elementi usati nell'array
void selection_sort_float(float data[], int used);


//Funzione che restituisca l'index del valore minimo.
//data: array di dati int
//i: index del primo elemento da cui parte la ricerca
//j: index dell'ultimo elemento in cui finisce la ricerca
int pos_of_min_int(int data[], int i, int j);


//Algoritmo che implementa il selection sort.
//data: array di dati int
//used: int che indica il numero di elementi usati nell'array
void selection_sort_int(int data[], int used);

//Funzione che restituisca l'index del valore minimo.
//data: array di dati double
//i: index del primo elemento da cui parte la ricerca
//j: index dell'ultimo elemento in cui finisce la ricerca
int pos_of_min_double(double data[], int i, int j);


//Algoritmo che implementa il selection sort.
//data: array di dati double
//used: int che indica il numero di elementi usati nell'array
void selection_sort_double(double data[], int used);


//Funzione che unisce due sottovettori contigui ordinandoli di interi
//int data: array di interi
//int i: index del primo elem del primo vettore
//int m: index mediano
//int f: index finale
void merge_ints(int data[], int i, int m, int f);


//Algoritmo di merge sort per array di interi
//int data[]: array di interi
//int used: size dell'array
void merge_sort_int(int data[], int init, int final);


//Funzione che unisce due sottovettori contigui ordinandoli di interi
//float data: array di interi
//int i: index del primo elem del primo vettore
//int m: index mediano
//int f: index finale
void merge_floats(float data[], int i, int m, int f);


//Algoritmo di merge sort per array di interi
//float data[]: array di interi
//int used: size dell'array
void merge_sort_float(float data[], int init, int final);


//Funzione che unisce due sottovettori contigui ordinandoli di interi
//int data: array di interi
//int i: index del primo elem del primo vettore
//int m: index mediano
//int f: index finale
void merge_doubles(double data[], int i, int m, int f);


//Algoritmo di merge sort per array di interi
//int data[]: array di interi
//int used: size dell'array
void merge_sort_double(double data[], int init, int final);
