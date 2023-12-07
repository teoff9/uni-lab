//07.12.23 by Matteo Fava

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "../lib/gen_random/gen_random.h"
using namespace std;

//calcola la posizione di un p materiale
double rileva(double time, double x0, double v);

int main() {
    ofstream out;
    int n = 100;
    double x0 = 2;
    double v = 0.3;

    set_seed();

    out.open("data/output/rilevazioni.dat");
    for (int i = 0; i< n; i++) {
        out << (double)i << setw(12) << rileva((double)i, x0, v) << endl;
    }
    out.close();

    return 0;
}

double rileva(double t, double x0, double v) {
    return x0 + t*v + rand_gaussian(0.0, 0.4);
}