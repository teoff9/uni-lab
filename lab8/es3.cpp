//21.11.23 by Matteo Fava

#include <iostream>
#include <cmath>
using namespace std;

//restituisce true se n e' un perfect square, else false
bool is_perfect_square(int n);

int main(){
    int n;

    cin >> n;

    cout << is_perfect_square(n) << endl;

    return 0;
}

bool is_perfect_square(int n){
    if (n>=1 && n-pow((int)sqrt(n), 2.0) == 0){
        return true;
    } else {
        return false;
    }
}