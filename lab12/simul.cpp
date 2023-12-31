//30.12.23 by Matteo Fava
//Esercizion 2 --> 5 del lab 12

#include "../lib/sfere/sfere.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    array_sfera data;

    //ES 2
    data = load_spheres("data/sfere.dat");
    cout << "ES 2:" << endl;
    print_sfera_sample(data);

    //ES 3
    sort(data.raw, 0, data.used-1);
    cout << "ES 3:" << endl;
    print_sfera_sample(data);

    //ES 4 
    for (int j = 0; j<data.used; j++){
        if (data.raw[j].color == 'r'){
            data.raw[j].exact = 90.;
            data.raw[j].atoll = 0.09;
        } else if (data.raw[j].color == 'g'){
            data.raw[j].exact = 70.;
            data.raw[j].atoll = 0.07;
        } else {
            data.raw[j].exact = 50.;
            data.raw[j].atoll = 0.05;
        }
        data.raw[j].discr = data.raw[j].diam - data.raw[j].exact;
    }
    cout << "ES 4:" << endl;
    print_sfera_sample(data);

    //ES 5
    array_sfera eliminated = data;
    for (int i = 0; i < eliminated.used; i++){
        if (fabs(eliminated.raw[i].discr) < eliminated.raw[i].atoll){
            delete_element(eliminated, i);
            i -= 1;
        }
    }
    resize_array(eliminated, eliminated.used);

    cout << "Eliminated " << eliminated.used << " sfere" << "\n\n";
    for (int i = 0; i < eliminated.used; i++){
        print_sfera(eliminated.raw[i]);
    }
        

    return 0;
}
