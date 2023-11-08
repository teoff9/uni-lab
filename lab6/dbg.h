#include <iostream>
using namespace std;

void dbg_array(float array[], char chars[], int used){
    cout << "[ ";
    for (int i = 0; i<used; i++){
        cout << "(" << array[i] << ", " << chars[i] << "), ";
    }
    cout << "]" << endl;
}