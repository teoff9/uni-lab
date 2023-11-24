//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "edit_array.h"


void delete_entry_shift_float(float v[], int* used, int where){
    if (where>= 0 && where<=(*used)-1){
        for (int i = where; i < (*used)-1; i++ ){
            std::swap(v[i], v[i+1]);
        }
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}


void delete_entry_swap_float(float v[], int* used, int where){
    if (where>= 0 && where<=(*used)-1){
        std::swap(v[where], v[(*used)-1]);
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_swap_bool(float v[], int* used, int where){
    if (where>= 0 && where<=(*used)-1){
        std::swap(v[where], v[(*used)-1]);
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_swap_int(float v[], int* used, int where){
    if (where>= 0 && where<=(*used)-1){
        std::swap(v[where], v[(*used)-1]);
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_shift_bool(bool v[], int* used, int where){
    if (where>= 0 && where<=(*used)-1){
        for (int i = where; i < (*used)-1; i++ ){
            std::swap(v[i], v[i+1]);
        }
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_shift_int(int v[], int* used, int where){
     if (where>= 0 && where<=(*used)-1){
        for (int i = where; i < (*used)-1; i++ ){
            std::swap(v[i], v[i+1]);
        }
        (*used) -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}