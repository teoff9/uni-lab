//12.12.23 by Matteo Fava

#include <iostream>
#include "../lib/arrays/arrays.h"
using namespace std;

int main() {
    int err;
    array_int arr_i = load_array_int("data/interi.dat", err);
    array_float arr_f = load_array_float("data/interi.dat", err);
    array_double arr_d = load_array_double("data/interi.dat", err);

    cout << search_value_int(arr_i, 4738) << endl;
    
    for (int i = 0; i < arr_i.used; i++) {
        cout << arr_i.raw[i] << " " << i << endl;
    }

    return 0;
}