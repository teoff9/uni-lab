//28.11.2023 by Matteo Fava

#include <iostream>
#include <fstream>
using namespace std;

struct array_int{
    int used;
    int size;
    int* raw;
};

//carica i dati in un array da file_name
//err_code : 0 bene, 1 prob stream, 2 prob allocazione
array_int load_interi(char file_name[], int& err_code);

int main(){
    array_int v;
    int errore;

    v = load_interi("data/interi.dat", errore);
    cout << v.raw[0] << " " << v.raw[v.used-1] << endl;
    cout << errore << endl;


    return 0;
}

array_int load_interi(char file_name[], int& err_code){
    array_int v;
    ifstream inp;
    int tmp;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load interi" << endl;
        err_code = 1;
        return v;
    }

    while (inp >> tmp) {
        v.size++;
    }
    inp.close();

    v.raw = new int[v.size];
    
    inp.open(file_name);

    for (int i = 0; i < v.size; i++){
        inp >> v.raw[i];
        v.used++;
    }
    if (v.size != v.used){
        err_code = 2;
    } else {
        err_code = 0;
    }

    return v;
}