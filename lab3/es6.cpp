//18.10.2023 by Matteo Fava

#include <iostream>
using namespace std;

//Dati un int min e un in max chiede all'utente un int
//fino a che non risulti incluso nell'intervallo min->max
int read_value(int,int);

int main(){
    int nvoti, a;
    int sum = 0;

    cin >> nvoti;

    for (int i = 0; i < nvoti; i++){
        cout << i;
        a = read_value(18, 30);
        sum += a;
    }

    cout << nvoti << " " << sum << endl;
    cout << "Xbest = " << float(sum)/float(nvoti) << endl;

    return 0;
}

int read_value(int min, int max){
    int val = 0;
    do{
        cin >> val;
    } while(val<min || val>max);
    cout << "Letto il valore " <<  val << endl;
    return val;
}