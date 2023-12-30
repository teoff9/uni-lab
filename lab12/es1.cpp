//30.12.23 by Matteo Fava

#include "../lib/sorting/sorting.h"
#include <iostream>
using namespace std;

int main() {
    float data[5] = {23,5,3,9,0};

    merge_sort_float(data, 0, 4);

    for (int a : data) {
        cout << a << "\n";
    }

    return 0;
}