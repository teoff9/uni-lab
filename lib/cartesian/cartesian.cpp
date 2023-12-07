//07.11.23 by Matteo Fava

#include "cartesian.h"
#include <fstream>
#include <iostream>
using namespace std;


array_pointsR2 load_pointsR2_from_file(char nome_file[], int& err_code){
    double x, y;
    ifstream inp;
    array_pointsR2 v;
    
    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(nome_file);
    if (inp.fail()) {
        cout << "Failed to load " << nome_file << endl;
        err_code = -1;
        return v;
    } else { 
        while (inp >> x && inp >> y) {
            v.size ++;
        }
        v.raw = new pointR2[v.size];
        if (v.raw == NULL) {
            err_code = -2;
            return v;
        } else {
            inp.clear();
            inp.seekg(0, ios::beg);

            for (int i = 0; i< v.size; i++) {
                inp >> v.raw[i].x;
                inp >> v.raw[i].y;
                v.used ++;
            }
            inp.close();
            return v;
            }        
    }

}


