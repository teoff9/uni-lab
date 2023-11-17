//17.11.23 by Matteo Fava

//Definizioni di graph.h

#include "graph.h"
#include <iostream>
using namespace std;

void istogramma(float min, float max, int nbins, float data[], int used, char pixel, int max_n){
    float delta = (max - min) / nbins;
    int* counters;
    
    //crea vettore di contatori
    counters = new int[nbins];
    for (int i = 0; i<nbins; i++){
        counters[i] = 0;
    }

    //conta le frequenze di dati
    for (int i = 0; i<used; i++){
        int k = 1;
        while (min+k*delta < data[i]){
            k++;
        }
        counters[k-1]++;
    }

    //resize se uno dei counters e' maggiore di n_max
    for (int i = 0; i< nbins; i++){
        if (counters[i]> max_n){
            for (int i = 0; i<nbins; i++){
                counters[i] = counters[i]/2 + 1; // in modo da fare per eccesso
            }
        }
    }
    
    //printa l'instogramma
    for (int i = 0; i<nbins; i++){
        cout << "( " << min + i*delta << ", " << min + (i+1)*delta << " ] ";
        for (int j = 0; j < counters[i]; j++){
            cout << pixel;
        }
        cout << endl;
    }
}
