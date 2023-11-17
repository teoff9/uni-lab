//14.11/23 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>

//determina diametro medio e dev standard dei 3 colori
void calcola_media_dev_std  (float vdiams[], char vcols[], int used, float medie[], float dev_std[]);

int main(){
    ifstream data;
    float* vdiams = NULL;
    char* vcols = NULL;
    int used = 0;
    float f;
    char c;
    float medie[3]; //{r,g,b}
    float dev_std[3]; //{r,g,b}
    
    //apri data
    data.open("data/sfere.dat");
    if (data.fail()){
        cout << "Failed to read file" << endl;
        return -1;
    }

    //conta il numero di valori con cui poi caricare i vettori
    while (data >> f && data >> c){
        used++;
    }
    data.close();

    //popola i due array di dati
    data.open("data/sfere.dat");
    vdiams = new float[used];
    vcols = new char[used];
    for (int i = 0; i<used; i++){
        data >> vdiams[i];
        data >> vcols[i];
    }

    //determina diametro medio e dev standard delle due




    //elimina arrays

    return 0;
}

void calcola_media_dev_std  (float vdiams[], char vcols[], int used, float medie[], float dev_std[]){
    float sum_r[2] = {0,0}, sum_g[2] = {0,0}, sum_b[2] = {0,0};
    for (int i = 0; i<used; i++){
        if (vcols[i] == 'r'){
            sum_r[0] += vdiams[i];
            sum_r[1] += 1;
        } else if (vcols[i] == 'g'){
            sum_g[0] += vdiams[i];
            sum_g[1] += 1;
        } else {
            sum_b[0] += vdiams[i];
            sum_b[1] += 1;
        }
    }
    //medie
    medie[0] = sum_r[0] / sum_r[1];
    medie[1] = sum_g[0] / sum_g[1];
    medie[2] = sum_b[0] / sum_b[1];

    //calcola le dev standard


}