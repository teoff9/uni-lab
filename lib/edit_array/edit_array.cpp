//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "edit_array.h"


void delete_entry_shift_float(float v[], int &used, int where){
    if (where>= 0 && where<=used-1){
        for (int i = where; i < used-1; i++ ){
            float tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = v[i];
        }
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_shift_bool(bool v[], int &used, int where){
    if (where>= 0 && where<=used-1){
        for (int i = where; i < used-1; i++ ){
            bool tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = v[i];
        }
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_shift_int(int v[], int &used, int where){
     if (where>= 0 && where<=used-1){
        for (int i = where; i < used-1; i++ ){
            int tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = v[i];
        }
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_swap_float(float v[], int &used, int where){
    if (where>= 0 && where<=used-1){
            float tmp = v[where];
            v[where] = v[where+1];
            v[where+1] = v[where];
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_swap_bool(bool v[], int &used, int where){
    if (where>= 0 && where<=used-1){
        bool tmp = v[where];
        v[where] = v[where+1];
        v[where+1] = v[where];
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

void delete_entry_swap_int(int v[], int &used, int where){
    if (where>= 0 && where<=used-1){
        int tmp = v[where];
        v[where] = v[where+1];
        v[where+1] = v[where];
        used -= 1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}