//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

#include "stats.h"

#define N 5

int main(){
    int data[N];
    
    for(int i = 0; i < N; i++){
        cin >> data[i];
    }

    float x = media(data, N);
    float dev = devstd(data, N);

    cout << dev << endl;

    return 0;
}