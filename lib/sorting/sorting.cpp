//27.10.2023 by Matteo Fava

#include "sorting.h"


int pos_of_min(float data[], int i, int j){
    int k;
    float min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}


void selection_sort(float data[], int n_data){
    for (int i = 0; i < n_data -1; i++){
        int k = pos_of_min(data, i, n_data-1);
        int tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }

}