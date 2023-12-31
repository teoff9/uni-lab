//27.10.2023 by Matteo Fava

#include "sorting.h"
#include <cstddef>


int pos_of_min_float(float data[], int i, int j){
    int k = 0;
    float min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}


void selection_sort_float(float data[], int used){
    for (int i = 0; i < used -1; i++){
        int k = pos_of_min_float(data, i, used-1);
        float tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }
}


int pos_of_min_int(int data[], int i, int j){
    int k = 0;
    int min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}


void selection_sort_int(int data[], int used){
    for (int i = 0; i < used -1; i++){
        int k = pos_of_min_int(data, i, used-1);
        int tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }

}


int pos_of_min_double(double data[], int i, int j){
    int k = 0;
    double min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}


void selection_sort_double(double data[], int used){
    for (int i = 0; i < used -1; i++){
        int k = pos_of_min_double(data, i, used-1);
        double tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }

}


void merge_ints(int data[], int i, int m, int f){
    int j, k, z;
    int* tmp = NULL; 
    tmp = new int[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_int(int data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_int(data, init, m);
        merge_sort_int(data, m+1, final);
        merge_ints(data, init, m, final);
    }
}


void merge_floats(float data[], int i, int m, int f){
    int j, k, z;
    float* tmp; 
    tmp = new float[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_float(float data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_float(data, init, m);
        merge_sort_float(data, m+1, final);
        merge_floats(data, init, m, final);
    }
}


void merge_doubles(double data[], int i, int m, int f){
    int j, k, z;
    double* tmp; 
    tmp = new double[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_double(double data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_double(data, init, m);
        merge_sort_double(data, m+1, final);
        merge_doubles(data, init, m, final);
    }
}