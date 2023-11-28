//28.11.23 by Matteo Fava

#include <iostream>
#include <fstream>
#include "sfere.h"
using namespace std;

struct sfera {
    float diam;
    char color;
};

sfera* load_spheres(char file_name[], int& used){
    sfera* v;
    ifstream inp;
    float d;
    char c;
    used = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load spheres" << endl;
        used = -1;
        return NULL;
    }

    while (inp >> d && inp >> c){
        used ++;
    }

    inp.close();

    v = new sfera[used];
    inp.open(file_name);

    for (int i = 0; i< used; i++){
        inp >> v[i].diam;
        inp >> v[i].color;
    }
    inp.close();

    return v;
}