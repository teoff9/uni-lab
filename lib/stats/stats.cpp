//07.11.2023 by Matteo Fava

#include <cmath>
#include "stats.h"

 
float media_int(int data[], int n_data){
    float sum = 0;
    for (int i=0; i <n_data; i++){
        sum += (float)data[i];
    }

    return sum/n_data;
}


float media_float(float data[], int n_data){
    float sum = 0;
    for (int i=0; i <n_data; i++){
        sum += data[i];
    }

    return sum/n_data;
}


float devstd_int(int data[], int n_data){
    float m = media_int(data, n_data);
    float numeratore = 0;
    for (int i = 0; i < n_data; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(n_data-1));
}


float devstd_float(float data[], int n_data){
    float m = media_float(data, n_data);
    float numeratore = 0;
    for (int i = 0; i < n_data; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(n_data-1));
}


bool is_outlier(float val, float media, float std_dev){
    if (fabs(val-media)> 3*std_dev){
        return true;
    } else {
        return false;
    }

}


float mediana(float data[], int used){
    if (used%2 != 0){
        return data[(used-1)/2];
    } else {
        return (data[used/2] + data[used/2 - 1])/2;
    }
}