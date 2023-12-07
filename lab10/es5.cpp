//07.11.23 by Matteo Fava

#include <iostream>
#include "../lib/cartesian/cartesian.h"
using namespace std;

int main() {
    int err = 0;
    char file[100] = "data/points.dat";

    array_pointsR2 v;
    v = load_pointsR2_from_file(file, err);
    cout << v.size << " " << v.used << " " << endl;
    for (int i = 0; i< v.used; i++) {
        cout << v.raw[i].x << " " << v.raw[i].y << endl;
    }

    return 0;
}
