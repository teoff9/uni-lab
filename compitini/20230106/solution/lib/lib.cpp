//14.01.23 by Matteo Fava
//File contenente le definizioni delle funzioni usate nel compitino

#include "lib.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//funzione che carica i dati da file
array_evento load_eventi(char file_name[], int &err_code){
    array_evento v;
    ifstream inp;
    double E1, p1x, p1y, p1z, E2, p2x, p2y, p2z;
    bool segnale;

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
    while (inp >> E1 && inp >> p1x && inp >> p1y && inp >> p1z && inp >> E2 && inp >> p2x && inp >> p2y && inp >> p2z && inp >> segnale){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new evento[v.size];

    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> E1 && inp >> p1x && inp >> p1y && inp >> p1z && inp >> E2 && inp >> p2x && inp >> p2y && inp >> p2z && inp >> segnale) {
        v.raw[v.used].p1[0] = E1;
        v.raw[v.used].p1[1] = p1x;
        v.raw[v.used].p1[2] = p1y;
        v.raw[v.used].p1[3] = p1z;
        v.raw[v.used].p2[0] = E2;
        v.raw[v.used].p2[1] = p2x;
        v.raw[v.used].p2[2] = p2y;
        v.raw[v.used].p2[3] = p2z;
        v.raw[v.used].segnale = segnale;
        v.used ++;
    }
    inp.close();

    return v;
}

//conta i dati evento
int conta_eventi(array_evento eventi){
    int n = 0;
    for (int i = 0; i<eventi.used; i++){
        if (eventi.raw[i].segnale) n++;
    }
    return n;
}

//calcola masse invarianti
void calcola_masse(array_evento eventi){
    for (int i = 0; i<eventi.used; i++){
        double m = pow(eventi.raw[i].p1[0]+eventi.raw[i].p2[0], 2) - (pow(eventi.raw[i].p1[1]+eventi.raw[i].p2[1],2) + pow(eventi.raw[i].p1[2]+eventi.raw[i].p2[2],2) + pow(eventi.raw[i].p1[3]+eventi.raw[i].p2[3],2));
        eventi.raw[i].massainv = sqrt(m);
    }
}

//stampa massa invariante di evento
void stampa_massinv(evento ev){
    cout << "Massa = " << ev.massainv << endl;
}

//stampa masse invarianti di primi n elementi
void stampa_masse(array_evento eventi, int n, bool reverse){
    if (!reverse){
        for (int i = 0; i < n; i++) {
            stampa_massinv(eventi.raw[i]);
        }
    } else {
        for (int i = eventi.used-n; i<eventi.used; i++) {
            stampa_massinv(eventi.raw[i]);
        }
    }
    
}

//mergia due sottoinsiemi di array_evento
void merge(evento data[], int i, int m, int f){
    int j, k, z;
    evento* tmp; 
    tmp = new evento[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].massainv <= data[k].massainv) {
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

//merge sort in base a massainv
void sort_for_massinv(evento data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        sort_for_massinv(data, init, m);
        sort_for_massinv(data, m+1, final);
        merge(data, init, m, final);
    }
}

//calcola media
double calc_media(array_evento eventi, bool solo_segnali){
    double acc = 0;
    int n = 0;
    if (solo_segnali){
        for (int i = 0; i<eventi.used; i++){
            if (eventi.raw[i].segnale){
                acc += eventi.raw[i].massainv;
                n++;
            }
    } 
    } else {
        for (int i = 0; i<eventi.used; i++){
            acc += eventi.raw[i].massainv;
            n++; 
    }
    }
    return acc/(double)n;
}

//calcola dev standard
double calc_dev_standard(array_evento eventi, bool solo_segnali){
    double m = calc_media(eventi, solo_segnali);
    double numeratore = 0;
    int n = 0;
    if (solo_segnali){
        for (int i = 0; i < eventi.used; i++){
            if (eventi.raw[i].segnale){
                numeratore += pow((eventi.raw[i].massainv-m), 2);
                n++;
            }
            
        }
    } else {
        for (int i = 0; i < eventi.used; i++){
            numeratore += pow((eventi.raw[i].massainv-m), 2);
            n++;
        }
    }
    return sqrt(numeratore/(double)n);
}

//min segnali
double min(array_evento eventi){
    for (int i = 0; i<eventi.used; i++){
        if (eventi.raw[i].segnale){
            return eventi.raw[i].massainv;
        }
    }
    return -1;
}

//max segnali 
double max(array_evento eventi){
    for (int i = eventi.used-1; i>=0; i--){
        if (eventi.raw[i].segnale){
            return eventi.raw[i].massainv;
        }
    }
    return -1;
}