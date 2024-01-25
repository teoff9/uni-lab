//14.01.23 by Matteo Fava
//File contenente le definizioni delle funzioni usate nel compitino

#include "lib.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//funzione che stampa i valori di uno ione
void print_ione(ione ion){
    cout << "X = " << ion.x << " | Y = " << ion.y << " | R = " << ion.r << " | Carica = " << ion.carica << endl;
}

//funzione che stampa i valori di un elettrone
void print_elettrone(elettrone elett){
    cout << "X = " << elett.x << " | Y = " << elett.y << " | Vx = " << elett.vx << " | Vy = " << elett.vy << " | Free = " << elett.free << endl;
}

//funzione che carica in un vettore gli ioni
array_ione load_ioni(char file_name[], int &err_code){
    array_ione v;
    ifstream inp;
    float x, y, r;
    int carica;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load ioni" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> x && inp >> y && inp >> r && inp >> carica){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new ione[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> x && inp >> y && inp >> r && inp >> carica) {
        v.raw[v.used].x = x;
        v.raw[v.used].y = y;
        v.raw[v.used].r = r;
        v.raw[v.used].carica = carica;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione che carica in un vettore gli elettroni
array_elettrone load_elettroni(char file_name[], int &err_code){
    array_elettrone v;
    ifstream inp;
    float x,y;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load elettroni" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> x && inp >> y){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new elettrone[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> x && inp >> y) {
        v.raw[v.used].x = x;
        v.raw[v.used].y = y;
        v.raw[v.used].vx = 0;
        v.raw[v.used].vy = 0;
        v.raw[v.used].free = true;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione che calcoli la distanza tra uno ione e un elettrone
float distanza(elettrone elettrone, ione ione){
    return sqrt( pow(ione.x - elettrone.x, 2) + pow(ione.y - elettrone.y, 2));
}

//controlla se l'elettrone si trova nel cerchio di cattura di uno ione etc etc
int gotcha(elettrone *el, array_ione ions){
    for (int i = 0; i<ions.used; i++){
        if (distanza(*el, ions.raw[i]) < ions.raw[i].r){
            (*el).free = false;
            ions.raw[i].carica -= 1;
            return 1;
        }
    }
    return 0;
}

//aggiorna gli elettroni e gli ioni catturati nell'istante 0
//restituisce il numero di elettroni catturati
int aggiorna_esperimento(array_ione ioni,array_elettrone elettroni){
    int n = 0;
    for (int i = 0; i<elettroni.used; i++){
        if (gotcha(&elettroni.raw[i], ioni)) n++;
    }
    return n;
}

//calcola le nuove velocita' degli elettroni free
void calc_forze(array_elettrone elettroni, array_ione ioni, float dt){
    for (int i = 0; i<elettroni.used; i++){
        if (elettroni.raw[i].free){
            float fx = 0;
            float fy = 0;
            
            for (int j = 0; j<elettroni.used; j++){
                if (j != i){
                    float dx = elettroni.raw[i].x - elettroni.raw[j].x;
                    float dy = elettroni.raw[i].y - elettroni.raw[j].y;
                    float d = sqrt( pow(dx, 2) + pow(dy, 2));
                    fx += dx/pow(d, 3);
                    fy += dy/pow(d, 3);
                }
            }
            
            for (int k = 0; k<ioni.used; k++){
                float d = distanza(elettroni.raw[i], ioni.raw[k]);
                float dx = elettroni.raw[i].x - ioni.raw[k].x;
                float dy = elettroni.raw[i].y - ioni.raw[k].y;
                fx -= (float)ioni.raw[k].carica * dx/pow(d, 3);
                fy -= (float)ioni.raw[k].carica * dy/pow(d, 3);
            }
            elettroni.raw[i].vx = elettroni.raw[i].vx + fx*dt;
            elettroni.raw[i].vy = elettroni.raw[i].vy + fy*dt;
            elettroni.raw[i].x = elettroni.raw[i].x + elettroni.raw[i].vx*dt + 0.5*fx*dt*dt;
            elettroni.raw[i].y = elettroni.raw[i].y + elettroni.raw[i].vy*dt + 0.5*fy*dt*dt;
        }
    }
}

//funzione che stampa il valore di uno ione su file
void out_ione(ofstream& ris, ione ion){
    ris << "X = " << ion.x << " | Y = " << ion.y << " | R = " << ion.r << " | Carica = " << ion.carica << endl;
}

//funzione che stampa il valore di un elettrone su file
void out_elettrone(ofstream& ris, elettrone elett){
    ris << "X = " << elett.x << " | Y = " << elett.y << " | Vx = " << elett.vx << " | Vy = " << elett.vy << " | Free = " << elett.free << endl;
}