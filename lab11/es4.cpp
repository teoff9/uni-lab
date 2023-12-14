//14.12.23 by Matteo Fava

#include <iostream>
#include <fstream>
#include <cmath>
#include "../lib/arrays/arrays.h"
#include "../lib/stats/stats.h"
using namespace std;


int main() {
    int* times = NULL;
    double* xs = NULL;
    int ttmp;
    double xtmp;
    ifstream inp;
    int used = 0;
    double m;
    double q;
    double num = 0;
    double det = 0;
    double scarto_medio = 0;
    double dev_std_scarto = 0;


    inp.open("data/rilevazioni.dat");
    if (inp.fail()) {
        cout << "failed to open file" << "\n";
        return -1;
    } 

    while (inp >> ttmp && inp >> xtmp) {
        used ++;
    }
    inp.clear();
    inp.seekg(0, ios::beg);

    times = new int[used];
    xs = new double[used];
    if (times == NULL or xs == NULL) {
        cout << "failed to allocate memory for data" << "\n";
        return -1;    
    }
    int i = 0;
    while (inp >> ttmp && inp >> xtmp) {
        times[i]= ttmp;
        xs[i] = xtmp;
        i++;
    }
    
    ttmp = 0; xtmp = 0;
    for (int i = 0; i<used; i++) {
        ttmp += times[i];
        xtmp += xs[i];
    }
    ttmp = ttmp / used;
    xtmp = xtmp /used;
    for (int i = 0; i<used; i++){
        num += ((double)times[i] - ttmp)*(xs[i] - xtmp);
        det += pow(((double)times[i] - ttmp), 2);
    }
    m = num/det;
    q = xtmp - m * ttmp;

    for (int i = 0; i<used; i++) {
        scarto_medio += xs[i] - (double)times[i]*m - q;
        dev_std_scarto += pow(xs[i] - (double)times[i]*m - q, 2);
    }
    scarto_medio = scarto_medio / used;
    dev_std_scarto = pow(dev_std_scarto / (used-1), 0.5);

    cout << "m = " << m << "\n" << "q = " << q << "\n";
    cout << scarto_medio << " " << dev_std_scarto << endl;



    return 0;
}