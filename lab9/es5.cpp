//28.11.23 by Matteo Fava

#include <iostream>
#include "../lib/sfere/sfere.h"
using namespace std;

struct sfera{
    float diam;
    char col;
};

//elimina dall'array sfera data[] i valori
//di sfera che abbiano char col, restituisce
//per side effect la nuova dim del vettore
void delete_spheres(sfera data[], int used, char col, int &new_n);

int main(){
    sfera* v = NULL;
    int used = 0;
    char color = 'g';
    int new_n = 0;

    v = load_spheres("data/sfere.dat", used);
    delete_spheres(v, used, color, new_n);

    for (int i = 0; i<new_n; i++){
        cout << v[i].diam << v[i].col << endl;
    }

    delete []v; 
    v = NULL;

    return 0;
}

void delete_spheres(sfera data[], int used, char color, int &new_n){
    new_n = used;
    for (int i = 0; i<new_n; i++){
        if (data[i].col == color){
            std::swap(data[i], data[new_n-1]);
            new_n --;
            i--;
        }
    }
}