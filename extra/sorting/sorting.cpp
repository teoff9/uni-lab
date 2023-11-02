//27.10.2023 by Matteo Fava
//main body to test sorting algorithms

#include "sort_algos.h"

#include <iostream>
using namespace std;

int main(){
    float data[13] = {0, -1, 5, 4, -3, 10, 8, 3, 2, 1, 20, 16, -20};
    
    selection_sort(data, 13);
    for (float a : data){
        cout << a << endl;
    }


    
    return 0;
}