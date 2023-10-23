//17.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

int main(){

    int a;
    int i = 0;
    int sum = 0;

    cin >> a;
    while (a!=0){
        i ++;
        sum += a;
        cin >> a;
    }

    if (i!=0){
        cout << i << " " << sum << endl;
        cout << "Xbest = " << float(sum)/float(i) << endl;
    } else { cout << "quitting.." << endl;}

    return 0;
}