//21.11.23 by Matteo Fava

#include <iostream>
using namespace std;

//restituisce true se int n e' primo e positivo, else false
bool is_prime(int n);

int main(){
    int n;

    cin >> n;

    cout << is_prime(n) << endl;

    return 0;
}

bool is_prime(int n){
    if (n<=1){
        return false;
    } else {
        for (int i = 2; i<n; i++){
            if (n%i == 0){
                return false;
            }
        }
        return true;
    }


}