//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "edit_array.h"

//Funzione che elimina l'elemento di pos where svolgendo uno shift a sinistra
//v = array, size = n di elementi di v, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used
int delete_entry_shift(float v[], int size, int used, int where){
    if (where>= 0 && where<=used-1){
        for (int i = where; i < used-1; i++ ){
            std::swap(v[i], v[i+1]);
        }

        return used-1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
}


//Funzione che elimina l'elemento di pos where
//v = array, size = n di elementi di v, used = n di elementi usati di v, where = pos di elem da eliminare
//Return il nuovo used
int delete_entry_swap(float v[], int size, int used, int where){
    if (where>= 0 && where<=used-1){
        std::swap(v[where], v[used-1]);
        return used-1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
}