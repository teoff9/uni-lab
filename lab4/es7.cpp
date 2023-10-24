//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

//scambia il contenuto delle variabili
void scambia_int(int, int);

//scambia le comp di un vettore n-upla, i con j
void scambia_arr(int[], int, int, int);

int main(){
    int v[5] = {1,2,3,4,5};
    int n = 5;
    cout << v[1] << " " << v[2] << endl;
    scambia_arr(v, n, 2, 1);
    cout << v[1] << " " << v[2] << endl;

    return 0;
}

void scambia_int(int v1, int v2){
    std::swap(v1, v2); 
}

void scambia_arr(int v[], int n, int i, int j){
    if ((i>= 0 && i <=n-1) && (j>= 0 && j <=n-1)){
        std::swap(v[i], v[j]);


    } else {
        cout << "Indici fuori range!" << endl;
    }

}