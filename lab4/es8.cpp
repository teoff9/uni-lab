//24.10.23 by Matteo Fava

#include <iostream>
using namespace std;

//elimina il valore in indice where da un vettore
//posizionando nell'ultima cella
int delete_entry_swap(float[], int, int, int);

int main(){

    return 0;
}

int delete_entry_swap(float v[], int size, int used, int where){
    if (where>= 0 && where<=used-1){
        for (int i = where; i < used-2; i++ ){
            std::swap(v[i], v[i+1]);
        }

        return used-1;

    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
}