//17.11.23 by Matteo Fava

#include <iostream>
#include "../lib/graphics/graph.h"
using namespace std;

int main(){
    float min, max;
    int nbins;
    float data[15] = {1.5, 2.3, 2.7, 3.2, 3.3, 3.7, 3.9, 4.0,4.1, 4.4, 5.0, 5.3, 6.1, 6.3, 7.8};
    int used = 15;
    int max_n = 5;

    do {
    cout << " Inserire: min max n_intervalli ";
    cin >> min >> max >> nbins;
    } while (min >= max);

    istogramma(min, max, nbins, data, used, '#', max_n);

    return 0;
}