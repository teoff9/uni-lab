//07.11.2023 by Matteo Fava

//Funzione che elimina l'elemento di pos where
//v = array, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_swap_float(float v[], int* used, int where);

//Funzione che elimina l'elemento di pos where
//v = array, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_swap_bool(float v[], int* used, int where);

//Funzione che elimina l'elemento di pos where
//v = array, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_swap_int(float v[], int* used, int where);

//Funzione che elimina l'elemento di pos where svolgendo uno shift a sinistra
//v = array, size = n di elementi di v, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_shift_float(float v[], int* used, int where);

//Funzione che elimina l'elemento di pos where svolgendo uno shift a sinistra
//v = array, size = n di elementi di v, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_shift_bool(bool v[], int* used, int where);

//Funzione che elimina l'elemento di pos where svolgendo uno shift a sinistra
//v = array, size = n di elementi di v, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used per side effect
void delete_entry_shift_int(int v[], int* used, int where);