//12.12.23 by Matteo Fava

#include "../lib/arrays/arrays.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    array_int arr;
    int err_code;
    arr = load_array_int("data/input.txt", err_code);

    resize_array_int(arr, 15);

    cout << "\n";
    for (int i = 0; i < arr.size; i++) {
        cout << i << " " << arr.raw[i] << endl;
    }
    cout << "\n" << arr.used << "\n\n";

    resize_array_int(arr, 3);
    cout << "\n";
    for (int i = 0; i < arr.size; i++) {
        cout << i << " " << arr.raw[i] << endl;
    }
    cout << "\n" << arr.used << "\n\n";

    return 0;
}