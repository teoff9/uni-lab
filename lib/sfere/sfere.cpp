//28.11.23 by Matteo Fava

#include <iostream>
#include <fstream>
#include "sfere.h"
using namespace std;

array_sfera load_spheres(char file_name[]){
    array_sfera data;
    data.used = 0;
    data.size = 0;
    data.raw = NULL;
    ifstream inp;
    float d;
    char c;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load spheres" << endl;
        return data;
    }

    while (inp >> d && inp >> c){
        data.size ++;
    }

    inp.clear();
    inp.seekg(0, ios::beg);

    data.raw = new sfera[data.size];

    for (int i = 0; i < data.size; i++){
        inp >> data.raw[i].diam;
        inp >> data.raw[i].color;
        data.used ++;
    }
    inp.close();

    return data;
}


void merge(sfera data[], int i, int m, int f){
    int j, k, z;
    sfera* tmp; 
    tmp = new sfera[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].diam <= data[k].diam) {
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
    tmp = nullptr;

}


void sort(sfera data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        sort(data, init, m);
        sort(data, m+1, final);
        merge(data, init, m, final);
    }
}


void delete_element(array_sfera &data, int where){
    if (where>= 0 && where<= data.used-1){
        for (int i = where; i < data.used-1; i++ ){
            sfera tmp = data.raw[i];
            data.raw[i] = data.raw[i+1];
            data.raw[i+1] = tmp;
        }
        data.used--;
    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}


int resize_array(array_sfera &myA, int new_size){
    sfera* new_array = NULL;
    new_array = new sfera[new_size];
    if (new_array == NULL) {
        return -1;
    }
    
    if (new_size > myA.size) {
        for (int i = 0; i < myA.used; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw;
        myA.raw = NULL;
        myA.raw = new_array;
        myA.size = new_size;

    } else if (new_size < myA.size) {
        for (int i = 0; i < new_size; i++) {
            new_array[i] = myA.raw[i];
        }
        delete []myA.raw; myA.raw = NULL;
        myA.raw = new_array;
        if (new_size < myA.used) {
            myA.used = new_size;
        }
        myA.size = new_size;
    } 

    return 0;
}


void print_sfera(sfera sf){
    cout << "Diam: " << sf.diam << " ";
    cout << "Col: " << sf.color << " ";
    cout << "Exact: " << sf.exact << " ";
    cout << "Toll: " << sf.atoll << " ";
    cout << "Discr: " << sf.discr << endl;
}


void print_sfera_sample(array_sfera data){
    for (int i = 0; i < 3; i++){
        print_sfera(data.raw[i]);
    }
    cout << "\n";
    for (int i = data.used-3; i<data.used; i++){
        print_sfera(data.raw[i]);
    }
    cout << "\n";
}