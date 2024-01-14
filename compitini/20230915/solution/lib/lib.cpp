//14.01.23 by Matteo Fava
//File contenente le definizioni delle funzioni usate nel compitino

#include "lib.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define sigma 10

//array che carica dinamicamente un array di colpi
array_colpo load_colpi(char file_name[], int &err_code){
    array_colpo v;
    ifstream inp;
    float theta, phi;

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
    while (inp >> theta && inp >> phi){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new colpo[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> theta && inp >> phi) {
        v.raw[v.used].theta = theta;
        v.raw[v.used].phi = phi;
        float g = powf(100, 2)/9.81*sinf(2*v.raw[v.used].theta);
        v.raw[v.used].xf = g*cosf(v.raw[v.used].phi);
        v.raw[v.used].yf = g*sinf(v.raw[v.used].phi);
        v.raw[v.used].hit = 0;
        v.used ++;
    }
    inp.close();

    return v;
}

//array che carica dinamicamente un array di bersagli
array_bersaglio load_bersagli(char file_name[], int &err_code){
    array_bersaglio v;
    ifstream inp;
    float x,y;
    float c;

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
    while (inp >> x && inp >> y && inp >> c){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new bersaglio[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> x && inp >> y && inp >> c) {
        v.raw[v.used].x = x;
        v.raw[v.used].y = y;
        v.raw[v.used].c = c;
        if (c < 0) v.raw[v.used].distr = true;
        else v.raw[v.used].distr = false;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione che conta i bersagli distrutti
int count_distrutti(array_bersaglio bersagli){
    int n = 0;
    for (int i = 0; i<bersagli.used; i++){
        if (bersagli.raw[i].distr) n++;
    }
    return n;
}

//funzione che printa colpo
void print_colpo(colpo c){
    cout << "Theta = " << c.theta << " | Phi = " << c.phi << " | (xf, yf) = (" << c.xf << ", " << c.yf << ") | Hit = " << c.hit << endl;
}

//funzione che printa bersagli
void print_bersaglio(bersaglio b){
    cout << "X = " << b.x << " | Y = " << b.y << " | C = " << b.c << " | Distr = " << b.distr << endl;
}

//funzione che stampa i primi tre bersagli distrutti e i primi tre non distrutti
void stamp_b(array_bersaglio bersagli){
    int used_d= 0, used_i = 0;
    bersaglio* distrutti = new bersaglio[3];
    bersaglio* interi = new bersaglio[3];

    for (int i = 0; i < bersagli.used; i++){
        if (bersagli.raw[i].distr == true && used_d<3){
            distrutti[used_d] = bersagli.raw[i];
            used_d++;
        } else if (bersagli.raw[i].distr == false && used_i<3){
            interi[used_d] = bersagli.raw[i];
            used_i++;
        }
    }
    cout << "Primi tre bersagli interi:\n";
    for (int i = 0; i<3; i++){
        print_bersaglio(interi[i]);
    }
    cout << "Primi tre bersagli distrutti:\n";
    for (int i = 0; i<3; i++){
        print_bersaglio(distrutti[i]);
    }
    cout << "\n";
    delete []distrutti;
    delete []interi;
    distrutti = NULL;
    interi = NULL;
}


//stampa primi tre e ultimi tre colpi
void print_sample_colpi(array_colpo colpi){
    cout << "Primi tre colpi:\n";
    for (int i = 0; i<3; i++){
        print_colpo(colpi.raw[i]);
    }
    cout << "Ultimi 3 colpi:\n";
    for (int i = colpi.used-3; i<colpi.used; i++){
        print_colpo(colpi.raw[i]);
    }
    cout << "\n";
}

//aggiorna bersagli
void aggiorna_bersagli(array_bersaglio &bersagli, array_colpo &colpi, int &distrutti, int &s){
    for (int i = 0; i<bersagli.used; i++){
        for (int k = 0; k<colpi.used; k++){
            float d = sqrtf(powf(bersagli.raw[i].x - colpi.raw[k].xf , 2) + powf( bersagli.raw[i].y - colpi.raw[k].yf , 2));
            if (d < sigma){
                colpi.raw[k].hit = true;
                s++;
                bersagli.raw[i].c -= d*(1-d/sigma);
                if (bersagli.raw[i].c < 0){
                    bersagli.raw[i].distr = true;
                    distrutti++;
                }
            }
        }
    }
}