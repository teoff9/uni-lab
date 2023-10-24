//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

#include "read_valid.h"

#define N 10

int main(){
    int data[N];
    int size = N;
    int used = 0;
    int tmp;

    while(used < size){
        tmp = read_value(18,30);
        if (tmp == 0){
            break;
        } else {
            data[used] = tmp;
            used++;
        }
    }

    if (used != 0) {
        cout << "printing elements of data: " << used << endl;

    for (int i = 0; i < used ; i++){
        cout << data[i] << endl;
    }
    }
    
    return 0;
}