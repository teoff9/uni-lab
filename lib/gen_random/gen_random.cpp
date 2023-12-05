//05.11.23 by Matteo Fava
//Contiene le definizioni della libreria
//per generare numeri casuali

#include "gen_random.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
#define PI 3.14159

double rand_uniform(double min, double max) { 
    
    return (max - min)*((double)rand()/RAND_MAX) + min;
}

double rand_gaussian(double median, double dev_std) {
    double u1 = (double) rand()/RAND_MAX;
    double u2 = (double) rand()/RAND_MAX;
    double N = sqrt(-2*log(u1))*cos(2*PI*u2);

    return  median + dev_std*N;
}

void set_seed() {
    srand(time(NULL));
}