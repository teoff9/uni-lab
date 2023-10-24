//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

#define N 10

int main(){
    int data[N];
    int size = N;
    int used = 0;

    for (used; used < 10; used++){
        cin >> data[used];
    }

    cout << "printing elements of data:" << endl;

    for (int a : data){
        cout << a << endl;
    }

    return 0;
}