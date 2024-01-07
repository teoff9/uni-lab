//07.01.24 by Matteo Fava
//File contenente le definizioni

#include "lib.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


//funzione che stampi a vide la descrizione di un punto
void print_punto(punto p, bool terna){
    if (!terna) {
        cout << "(x,y) = (" << p.x << ", " << p.y << ") | w = " << p.w << " | m = " << p.m << '\n';
    } else {
        cout << "w = " << p.w << " | m = " << p.m << " | f = " << p.f <<  '\n';
    }
}

//funzione che stampi a video tutte le descrizioni in un array_punto
void print_all(array_punto pts, bool terna){
    for (int i = 0; i < pts.used; i++){
        print_punto(pts.raw[i], terna);
    }
    cout << endl;
}

//funzione che calcoli il raggio di uno struct punto
//punto p: il punto in questione
float R(punto p){
    return sqrtf( powf(p.x, 2.0) +  powf(p.y, 2.0));
}

//funzione che calcoli la F centripeta agente su un punto
//punto p: il punto in questione
float calc_f(punto p) {
    return p.m * powf(p.w, 2.0) * R(p);
}

//funzione che calcoli la F centripeta agente su ogni punto
//array_punto pts: i punti in questione
float calc_f_all(array_punto pts){
    for (int i = 0; i< pts.used; i++){
        pts.raw[i].f = calc_f(pts.raw[i]);
    }
}

//funzione che carichi un array_punto dato il nome di un file
//restituisce per side effect un err code: 0=tutto bene, 
//-1= se nn trova il fil
//-2= se nn riesce ad allocare abbastanza memoria per l'array
array_punto load_punti(char file_name[], int &err_code){
    array_punto v;
    ifstream inp;
    float x, y, w, m;

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
    while (inp >> x && inp >> y && inp >> w && inp >> m){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new punto[v.size];

    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> x && inp >> y && inp >> w && inp >> m) {
        v.raw[v.used].x = x;
        v.raw[v.used].y = y;
        v.raw[v.used].w = w;
        v.raw[v.used].m = m;
        v.used ++;
    }
    inp.close();

    return v;
}

void merge_points(punto data[], int i, int m, int f){
    int j, k, z;
    punto* tmp; 
    tmp = new punto[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].f <= data[k].f) {
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

//funzione che sorti l'array di punti in basse alle f centripete
//restituisce per side effect l'f min
void sort_for_f(punto data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        sort_for_f(data, init, m);
        sort_for_f(data, m+1, final);
        merge_points(data, init, m, final);
    }
}

//funzione che calcola f media di array_punto
float f_media(array_punto data){
    float f = 0;
    for (int i = 0; i<data.used; i++){
        f += data.raw[i].f;
    }
    return f/data.used;
}

//funzione che screma i valori in base all'f media
array_punto screma_for_f(array_punto data){
    float f_med = f_media(data);
    int us = 0;
    int j = 0;
    bool* indexes = new bool[data.used];

    for (int i = 0; i<data.used; i++){
        indexes[i] = 0;
        if (data.raw[i].f > 1.2 * f_med){
            indexes[i] = 1;
            us ++;
        }
    }
    array_punto elim;
    elim.size = us;
    elim.used = us;
    elim.raw = new punto[elim.size];
    for (int i = 0; i< data.used; i++){
        if (indexes[i]){
            elim.raw[j] = data.raw[i];
            j++;
        }
    }

    return elim;
}