//16.01.23 by Matteo Fava
//File contenente le definizioni delle funzioni usate nel compitino

#include "lib.h"
#include <iostream>
#include <fstream>
using namespace std;


//funzione che carica le misure in un array allocato dinamicamente
array_misura load_misure(char file_name[], int &err_code){
    array_misura v;
    ifstream inp;
    int t, mis;
    float temp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load punti" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> t && inp >> mis && inp >> temp){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new misura[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> t && inp >> mis && inp >> temp) {
        v.raw[v.used].t = t;
        v.raw[v.used].mis = mis;
        v.raw[v.used].temp = temp;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione che stamp i valori di una misura
void print(misura mis){
    cout << "T = " << mis.t << " | Mis = " << mis.mis << " | Temp = " << mis.temp << " | Stato = " << mis.stato << endl;
}

//funzione che stampa i primi int n e gli ultimi int n misure di array_misura
void print_sample(array_misura misure, int n){
    cout << "Prime " << n << " misure:\n";
    for (int i = 0; i<n; i++){
        print(misure.raw[i]);
    }
    cout << "Ultime " << n << " misure:\n";
    for (int i = misure.used-n; i<misure.used; i++){
        print(misure.raw[i]);
    }
    cout << "\n";
}

//funzione che elimina un elemento da array_threshold
void delete_misura(array_misura &misure, int where){
    if (where>= 0 && where<=misure.used-1){
            misura tmp = misure.raw[where];
            misure.raw[where] = misure.raw[misure.used-1];
            misure.raw[misure.used-1] = misure.raw[where];
        misure.used -= 1;
    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

//funzione che elimina le misure che hanno temp > float threshold
void delete_by_temp(array_misura &misure, float threshold){
    for (int i = 0; i <misure.used; i++){
        if (misure.raw[i].temp > threshold){
            delete_misura(misure, i);
            i--;
        }
    }
}

//funzione che calcola la frequenza di una misura, tra indice in e indice fin
int frequenza_by_value(array_misura misure, int m, int in, int fin){
    int f = 0;
    for (int i = in; i<=fin; i++){
        if (misure.raw[i].mis == m) f++;
    }
    return f;
}

//funzione che faccia il merge di due sottovettori contigui di array_misura
void merge(misura data[], int i, int m, int f){
    int j, k, z;
    misura* tmp;
    tmp = new misura[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].t <= data[k].t) {
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

//funzione che faccia il merge sort di array_misura
void sort(misura data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        sort(data, init, m);
        sort(data, m+1, final);
        merge(data, init, m, final);
    }
}

//funzione che setta lo status
void set_status(array_misura misure, int k, char status){
    for (int i = 0; i<misure.used; i++){
            if (misure.raw[i].t >= 60*(k-1) && misure.raw[i].t <= 60*k-1){
                misure.raw[i].stato = status;
            }
        }
}

//funzione che calcola gli stati
void calc_stati(array_misura misure){
    for (int k = 1; k < 4; k++){
        int N0 = 0;
        int N1 = 0;
        int N = 0;
        for (int i = 0; i<misure.used; i++){
            if (misure.raw[i].t >= 60*(k-1) && misure.raw[i].t <= 60*k-1){
                N ++;
                if (misure.raw[i].mis == 0) N0++;
                else N1++;
            }
        }
        if ((double)N1/N <= 0.05) set_status(misure, k, '0');
        else if ((double)N1/N >= 0.95) set_status(misure, k, '1');
        else set_status(misure, k, '+');
    }
}



