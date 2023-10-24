//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

//elimina il valore in indice where da un vettore
//e shiftando a sinistra i restanti valori
int delete_entry_shift(float[], int, int, int);

int main(){
    float v[5] = {1,2,3,4,0};
    int x = delete_entry_shift(v, 5, 4, 2);

    for(float a : v){
        cout << a << endl;
    }

    cout << "\n" << x << endl;

    return 0;
}

int delete_entry_shift(float v[], int size, int used, int where){
    if (where>= 0 && where<=used-1){
        for (int i = where; i < used-1; i++ ){
            std::swap(v[i], v[i+1]);
        }

        return used-1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
}