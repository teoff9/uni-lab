//18.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

#include "read_value.h"

int main(){
    int votes[30];
    int a;
    int n = 0;
    int sum = 0;

    a = read_value(18,30);
    if (a==0){
        cout << "quitting.." << endl;
    } else {
        for (int i=0; i<30; i++){
            votes[i] = a;
            n = i;
            a = read_value(18, 30);
            if (a==0){
                break;
            }

        }

        for (int i = 0; i <= n ; i++){
            sum += votes[i];
        }

        cout << n << " " << sum << " <x> = " << float(sum)/float(n+1) << endl;
    }
    
    

    
    return 0;
}