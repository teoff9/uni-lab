//14.11.2023 by Matteo Fava

#include <iostream>
using namespace std;

//scambia int: scabia i valori di due int
//int a: primo elemento
//int b: secondo elemento
void scambia_int(int &a, int &b);

//scambia float: scabia i valori di due int
//int a: primo elemento
//int b: secondo elemento
void scambia_float(float &a, float &b);


int main(){
    int a = 5;
    int b = 6;
    scambia_int(a,b);
    cout << a << endl;
    cout << b << endl;

    float c = 5.5;
    float d = 6.6;
    scambia_float(c,d);
    cout << c << endl;
    cout << d << endl;

    return 0;
}

void scambia_int(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void scambia_float(float &a, float &b){
    float tmp = a;
    a = b;
    b = tmp;
}