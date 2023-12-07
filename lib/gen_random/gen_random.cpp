//05.11.23 by Matteo Fava
//Contiene le definizioni della libreria
//per generare numeri casuali

#include "gen_random.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
#define PI 3.14159

double rand_n() {
    return (double)rand() / RAND_MAX;
}

double rand_uniform(double min, double max) { 
    
    return (max - min)*rand_n() + min;
}

double rand_gaussian(double median, double dev_std) {
    double u1 = rand_n();
    double u2 = rand_n();
    double N = sqrt(-2*log(u1))*cos(2*PI*u2);

    return  median + dev_std*N;
}

void set_seed() {
    srand(time(NULL));
}