//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

//restituisce il max tra due float
float massimo(float, float);

int main(){

    return 0;
}

//Dichiarazione massimo
float massimo(float a, float b){
    if (a<=b){
        return b;
    } else {
        return a;
    }
}