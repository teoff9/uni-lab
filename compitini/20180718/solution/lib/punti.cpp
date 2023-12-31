//31.12.23 by Matteo Fava
//Contenente le def delle funzioni usate per la soluzione

#include "punti.h"
#include <fstream>
#include <iostream>
using namespace std;

punto_m* load_punti(char file_name[], int &used, int &size){
    punto_m* data = NULL;
    ifstream inp;
    float x, y, m;
    used = 0, size = 0;;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to open specified file" << endl;
    } else {
        //conta i punti
        while(inp >> x && inp >> y && inp >> m){
            size++;
        }
        //alloca dinamicamente il vettore data
        data = new punto_m[size];
        if (data == NULL) {
            cout << "Failed to allocate memory necessary for array of punti" << endl;
            return data;
        }
        inp.clear();
        inp.seekg(0, ios::beg);
        //load punti
        for (int i = 0; i < size; i++){
            inp >> data[i].x;
            inp >> data[i].y;
            inp >> data[i].m;
            used++;
        }
    }

    inp.close();
    return data;
}

void print_punto(punto_m p, bool d_flag){
    if (d_flag) {
        cout << "x: " << p.x << " y: " << p.y << " m: " << p.m << " d: " << p.d << endl;
    } else {
        cout << "x: " << p.x << " y: " << p.y << " m: " << p.m << endl;
    }
    
}

float find_x_min(punto_m data[], int used){
    float min = data[0].x;
    for (int i = 1; i < used; i++){
        if ( data[i].x < min){
            min = data[i].x;
        }
    }

    return min;
}

float find_x_max(punto_m data[], int used){
    float max = data[0].x;
    for (int i = 1; i < used; i++){
        if ( data[i].x > max){
            max = data[i].x;
        }
    }

    return max;
}

punto_m centro_di_massa(punto_m data[], int &used){
    punto_m cm;
    cm.m = 0;
    float tmp_x = 0, tmp_y = 0;
    for (int i = 0; i < used; i++){
        cm.m += data[i].m;
        tmp_x += data[i].m * data[i].x;
        tmp_y += data[i].m * data[i].y;
    }

    cm.x = tmp_x / cm.m;
    cm.y = tmp_y /cm.m;

    return cm;
}

void merge(punto_m data[], int i, int m, int f){
    int j, k, z;
    punto_m* tmp; 
    tmp = new punto_m[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].d <= data[k].d) {
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

void sort(punto_m data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        sort(data, init, m);
        sort(data, m+1, final);
        merge(data, init, m, final);
    }
}