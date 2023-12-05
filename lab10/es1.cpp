//05.11.23 by Matteo Fava

#include <iostream>
#include "../lib/gen_random/gen_random.h"
#include "../lib/graphics/graph.h"
using namespace std;

int main(){
    set_seed();
    double med = 3.5;
    double sigma = 0.66;
    float dati[100];
    for (int i = 0; i<100; i++){

        for (int i = 0; i < 100; i++) {
            double n = rand_gaussian(med, sigma);
            cout << n << endl;
            dati[i] = (float)n;
        }
    }

    istogramma(0.0, 5.0, 10, dati, 100, '*', 100);


    return 0;
}

