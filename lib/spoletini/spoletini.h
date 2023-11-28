//17.11.23 by Matteo Fava

//Libreria per cicli spoletini per file(s)

//funzione che restituisce un vettore di float di n_dat allocato dinamicamente
//char file_name[] : file name con path relativo o assoluto
//char* n_dati : dato che sara' passato per side effect
// RETURNS NULL IF SOMETHING WENT WRONG
float* spoletini_file_float(char file_name[], int& n_dat);

//funzione che restituisce un vettore di int di n_dat allocato dinamicamente
//char file_name[] : file name con path relativo o assoluto
//char* n_dati : dato che sara' passato per side effect
// RETURNS NULL IF SOMETHING WENT WRONG
int* spoletini_file_int(char file_name[], int& n_dat);

