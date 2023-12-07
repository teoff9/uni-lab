//07.12.23 by Matteo Fava

#include <iostream>
#include <cmath>
#include "../lib/gen_random/gen_random.h"
#include "../lib/stats/stats.h"
using namespace std;

//funzione
double f(double x);

//integrale di f(x) tra a e b con N punti
double integrate(double a, double b, int N);


int main() {
    int M = 20;
    int k = 1000;
    float data[20];
    float media, std;

    for (int i = 0; i < M; i++) {
        data[i] = (float)integrate(0,2, k);
    }

    cout << media_float(data, M) << " +- " << devstd_float(data, M) << endl;


    return 0;
}


double f(double x) {
    return pow(x, 3.0) * cos(x);
}

double integrate(double a, double b, int N){
    set_seed();
    double sum = 0;
    for (int i = 0; i<N; i++){
       sum += f(rand_uniform(a, b));
    }
    
    return (b-a) * sum / (double)N;
}