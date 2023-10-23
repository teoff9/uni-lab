//17.10.23 by Matteo Fava

#include <iostream>
using namespace std;

int main(){
    float a,b;
    float min, max;

    cin >> a >> b;
    
    min = std::min(a,b);
    max = std::max(a,b);

    if (max<0){
        cout << "intervallo negativo" << endl;
    } else if (min > 0) {
        cout << "Intervallo positivo" << endl;
    } else {
        cout << "include lo 0" << endl;
    }

    return 0;
}