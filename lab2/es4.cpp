//10.10.23 by Matteo Fava

#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << a+b << "\n" << a-b << "\n" << a*b << "\n" << a/b << "\n"<< endl;
    cout << (1.1*a)/b << endl;
    cout << 1.1*(a/b) << endl;
    cout << a/(1.1*b) << endl;

    return 0;
}