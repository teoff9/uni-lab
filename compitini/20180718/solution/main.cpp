//31.12.23 by Matteo Fava
//Codice main del compitino 18-7-18

#include "lib/punti.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    punto_m* data = NULL;
    int used, size;
    float x_min, x_max;
    punto_m cm;
    ofstream out;

    out.open("data/output/output.dat");


    //carica in un vettore i punti
    data = load_punti("data/punti.dat", used, size);

    //stampa i dati richiesti dal primo punto
    cout << "Caricati " << used << " punti massa." << endl;
    for (int i = 0; i < used; i++){
        print_punto(data[i], false);
        out << "x: " << data[i].x << " y: " << data[i].y << " m: " << data[i].m << endl;
    }

    //trova l'ascissa minima e massima e stampale a video
    x_min = find_x_min(data, used);
    x_max = find_x_max(data, used);
    cout << "Ascissa minima: " << x_min << " | Ascissa massima: " << x_max << endl;
    out << "Ascissa minima: " << x_min << " | Ascissa massima: " << x_max << endl;

    //calcola i dati sul centro di mass
    cm = centro_di_massa(data, used);
    cout << "Centro di massa: ";
    print_punto(cm, false);
    out << "Centro di massa: " << "x: " << cm.x << " y: " << cm.y << " m: " << cm.m << endl;

    //determina le d
    for (int i = 0; i < used; i++){
        data[i].d = sqrt( pow( data[i].x - cm.x, 2 ) + pow( data[i].y - cm.y, 2 ) );
    }
    //sorta l'array di data
    sort(data, 0, used-1);
    for (int i = 0; i < used; i++){
        print_punto(data[i], true);
        out << "x: " << data[i].x << " y: " << data[i].y << " m: " << data[i].m << " d: " << data[i].d << endl;
    }

    delete []data;
    data = NULL;
} 