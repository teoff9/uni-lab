//12.12.23 by Matteo Fava

#include <iostream>
#include "../lib/arrays/arrays.h"
using namespace std;

int main() {
    int err;
    array_double arr = load_array_double("data/interi.dat", err);
    cout << arr.used << " " << arr.size << endl;
    for (int i = 0; i < arr.size; i++) {
        cout << arr.raw[i] << endl;
    }

    return 0;
}