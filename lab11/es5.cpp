//14.12.23 by Matteo Fava

#include <iostream>
#include "../lib/search/search.h"
using namespace std;

int main() {
    int data[11] = {1,2,3,4,5,6,7,8,9,10, 11};
    cout << binary_search_int(data, 0, 10, 7) << endl;


    return 0;
}