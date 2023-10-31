//24.10.23 by Matteo Fava

//Libreria di statistica

#include <cmath>

//media di una n-upla con n = n_data
//ritorna la media 
float media(int data[], int n_data){
    float sum = 0;
    for (int i=0; i <n_data; i++){
        sum += (float)data[i];
    }

    return sum/n_data;
}

//dev. std. di n-upla con n = n_data
// ritorna la dev standard
float devstd(int data[], int n_data){
    float m = media(data, n_data);
    float numeratore = 0;
    for (int i = 0; i < n_data; i++){
        numeratore += pow((data[i]-m), 2);
    }
    return sqrt(numeratore/(n_data-1));

}

//restituisce se un val e' |val-media| > 3stdDev
bool is_outlier(int val, float media, float std_dev){
    if (fabs(val-media)> 3*std_dev){
        return true;
    } else {
        return false;
    }

}