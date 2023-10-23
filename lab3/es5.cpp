//17.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

int read_value(int max, int min);

int main(){

    int a;
    int i = 0;
    int sum = 0;

    a = read_value(18,30);
    while (a!=0){
        i ++;
        sum += a;
        a = read_value(18, 30);
    }

    if (i!=0){
        cout << i << " " << sum << endl;
        cout << "Xbest = " << float(sum)/float(i) << endl;
    } else { cout << "quitting.." << endl;}

    return 0;
}


int read_value(int min, int max){
    int val = 0;
    do{
        cin >> val;
    } while(val!=0 && (val<min || val>max));
    cout << "Letto il valore " <<  val << endl;
    return val;
}