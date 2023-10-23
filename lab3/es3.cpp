//17.10.23 by Matteo Fava

#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int a, b;
    int min, max;
    int val;
    
    cin >> a >> b;

    //riordinali se non corretto
    min = std::min(a,b);
    max = std::max(a,b);

    do {
        cin >> val;
    } while(val < min || val > max);

    cout << abs(val-min) << " " << abs(max-val) << endl;

    return 0;
}