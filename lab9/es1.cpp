//28.11.23 by Matteo Fava

#include "../lib/spoletini/spoletini.h"
#include <iostream>
using namespace std;

int main(){
    int* v;
    int used;

    v = spoletini_file_int("data/interi.dat", used);

    for (int i = 0; i<used; i++){
        cout << v[i] << endl;
    }
    cout << used << endl;

    return 0;
}