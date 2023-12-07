//05.12.23 by Matteo Fava

#include <iostream>
#include <cmath>
#include "../lib/gen_random/gen_random.h"
#include "../lib/stats/stats.h"
using namespace std;

struct point {
    double x;
    double y;
};

//genera un punto tra [0,max_x] x [0,max_y]
point gen_point(double max_x, double max_y);

//determina se un punto e' dentro il cerchio
//di raggio r
bool is_inside_circle(point pt, double r);

//conta quanti pt sono caduti in una circ di raggio r
//in quadrato di lato r 
int count_within(int n, double r);

//rileva con n punti pi tramite raggio r
double rilevazione(int n, double r);


int main() {
    set_seed();
    double r = 1.0;
    int M = 50;
    int N = 10000;
    float data[50];
    double media, std;

    for (int i = 0; i < M; i++) {
        data[i] = (float)rilevazione(N, r);
    }
    
    media = media_float(data, M);
    std = devstd_float(data, M);

    cout << media << " +- " << std << endl;
    
    return 0;
}

point gen_point(double max_x, double max_y) {
    point p;
    p.x = rand_uniform(0.0, max_x);
    p.y = rand_uniform(0.0, max_y);
    return p;
}

bool is_inside_circle(point pt, double r) {
    if (pow(pt.x, 2.0) + pow(pt.y, 2.0) <= pow(r, 2.0)) {
        return 1;
    } else {
        return 0;
    }
}

int count_within(int n, double r){
    int inside = 0;
    for (int i = 0; i<n; i++) {
        point pt = gen_point(r,r);
        if (is_inside_circle(pt, r)) {
            inside++;
        }
    }

    return inside;
}

double rilevazione(int n, double r){
    int inside = count_within(n, r);

    return inside * 4.0 * pow(r, 2.0) / (double)n ;
}
