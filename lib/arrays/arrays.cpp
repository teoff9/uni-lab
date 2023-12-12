//12.12.23 by Matteo Fava
//Definizioni delle funzioni della libreria arrays

#include "arrays.h"
#include <fstream>
#include <iostream>
using namespace std;

array_int load_interi(char file_name[], int& err_code){
    array_int v;
    ifstream inp;
    int tmp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load interi" << endl;
        err_code = -1;
        return v;
    }

    while (inp >> tmp) {
        v.size++;
    }
    inp.close();

    v.raw = new int[v.size];
    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }

    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }
    
    inp.open(file_name);

    for (int i = 0; i < v.size; i++){
        inp >> v.raw[i];
        v.used++;
    }

    return v;
}

array_int load_array_int(char file_name[], int& err_code){
    array_int v;
    ifstream inp;
    int tmp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load interi" << endl;
        err_code = -1;
        return v;
    }

    while (inp >> tmp) {
        v.size++;
    }
    inp.close();

    v.raw = new int[v.size];
    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }

    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }
    
    inp.open(file_name);

    for (int i = 0; i < v.size; i++){
        inp >> v.raw[i];
        v.used++;
    }

    return v;
}

array_float load_array_float(char file_name[], int& err_code){
    array_float v;
    ifstream inp;
    float tmp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load interi" << endl;
        err_code = -1;
        return v;
    }

    while (inp >> tmp) {
        v.size++;
    }
    inp.close();

    v.raw = new float[v.size];
    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }

    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }
    
    inp.open(file_name);

    for (int i = 0; i < v.size; i++){
        inp >> v.raw[i];
        v.used++;
    }

    return v;
}

array_double load_array_double(char file_name[], int& err_code){
    array_double v;
    ifstream inp;
    double tmp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load interi" << endl;
        err_code = -1;
        return v;
    }

    while (inp >> tmp) {
        v.size++;
    }
    inp.close();

    v.raw = new double[v.size];
    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }

    if (v.raw == NULL) {
        err_code = -2;
        return v;
    }
    
    inp.open(file_name);

    for (int i = 0; i < v.size; i++){
        inp >> v.raw[i];
        v.used++;
    }

    return v;
}


int resize_array_int(array_int &myA, int new_size){
    int* new_array = NULL;
    new_array = new int[new_size];
    if (new_array == NULL) {
        return -1;
    }
    
    if (new_size > myA.size) {
        for (int i = 0; i < myA.used; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw;
        myA.raw = NULL;
        myA.raw = new_array;
        myA.size = new_size;

    } else if (new_size < myA.size) {
        for (int i = 0; i < new_size; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw; myA.raw = NULL;
        myA.raw = new_array;
        if (new_size < myA.used) {
            myA.used = new_size;
        }
        myA.size = new_size;
    } 

    return 0;
}


int resize_array_float(array_float &myA, int new_size){
    float* new_array = NULL;
    new_array = new float[new_size];
    if (new_array == NULL) {
        return -1;
    }
    
    if (new_size > myA.size) {
        for (int i = 0; i < myA.used; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw;
        myA.raw = NULL;
        myA.raw = new_array;
        myA.size = new_size;

    } else if (new_size < myA.size) {
        for (int i = 0; i < new_size; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw; myA.raw = NULL;
        myA.raw = new_array;
        if (new_size < myA.used) {
            myA.used = new_size;
        }
        myA.size = new_size;
    } 

    return 0;
}


int resize_array_double(array_double &myA, int new_size) {
    double* new_array = NULL;
    new_array = new double[new_size];
    if (new_array == NULL) {
        return -1;
    }
    
    if (new_size > myA.size) {
        for (int i = 0; i < myA.used; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw;
        myA.raw = NULL;
        myA.raw = new_array;
        myA.size = new_size;

    } else if (new_size < myA.size) {
        for (int i = 0; i < new_size; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw; myA.raw = NULL;
        myA.raw = new_array;
        if (new_size < myA.used) {
            myA.used = new_size;
        }
        myA.size = new_size;
    } 

    return 0;
}
