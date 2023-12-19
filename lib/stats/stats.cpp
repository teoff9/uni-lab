//07.11.2023 by Matteo Fava

#include <cmath>
#include "stats.h"

 
float media_int(int data[], int used){
    float sum = 0;
    for (int i=0; i <used; i++){
        sum += (float)data[i];
    }

    return sum/used;
}


float media_float(float data[], int used){
    float sum = 0;
    for (int i=0; i <used; i++){
        sum += data[i];
    }

    return sum/used;
}


double media_double(double data[], int used){
    double sum = 0;
    for (int i=0; i <used; i++){
        sum += data[i];
    }

    return sum/used;
}


float devstd_int(int data[], int used){
    float m = media_int(data, used);
    float numeratore = 0;
    for (int i = 0; i < used; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(used-1));
}


float devstd_float(float data[], int used){
    float m = media_float(data, used);
    float numeratore = 0;
    for (int i = 0; i < used; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(used-1));
}


double devstd_double(double data[], int used){
    double m = media_double(data, used);
    double numeratore = 0;
    for (int i = 0; i < used; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(used-1));
}



bool is_outlier_float(float val, float media, float std_dev){
    if (fabs(val-media)> 3*std_dev){
        return true;
    } else {
        return false;
    }

}


float mediana_float(float data[], int used){
    if (used%2 != 0){
        return data[(used-1)/2];
    } else {
        return (data[used/2] + data[used/2 - 1])/2;
    }
}