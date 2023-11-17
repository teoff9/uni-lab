//14.11/23 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
#include <cmath>
#include "../lib/sorting/sorting.h"
#include "../lib/stats/stats.h"

//determina diametro medio e dev standard dei 3 colori
void calcola_media_dev_std  (float vdiams[], char vcols[], int used, float medie[], float dev_std[], int* n);

//calcola stats
void calcolaStats(float data[], int used, float* median, float* med, float* stddev);

int main(){
    ifstream data;
    float* vdiams = NULL;
    char* vcols = NULL;
    int used = 0;
    float f;
    char c;
    float medie[3]; //{r,g,b}
    float dev_std[3]; //{r,g,b}
    int n_rosse;
    float * rdiams = NULL;
    float median, med, stddev;
    
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
    calcola_media_dev_std(vdiams, vcols, used, medie, dev_std, &n_rosse);
    for (int i = 0; i < 3; i++){
        cout << medie[i] << " " << dev_std[i] << endl;
    }

    //inizializza rdiams
    cout << "Numero di palline rosse: " << n_rosse << endl;
    rdiams = new float[n_rosse];
    int i =0, j = 0;
    while (i<used && j < n_rosse){
        if (vcols[i] == 'r'){
            rdiams[j] = vdiams[i];
            j++;
        }
        i++;
    }

    //elimina arrays
    delete []vdiams; delete []vcols;
    vdiams = NULL; vcols = NULL;
    
    //sortalo
    selection_sort(rdiams, n_rosse);
    cout << "Mimino: " << rdiams[0] << endl;
    cout << "Massimo: " << rdiams[n_rosse -1] << endl;
    calcolaStats(rdiams, n_rosse, &median, &med, &stddev);
    cout << "Mediana: " << median << endl;
    cout << "Media: " << med << endl;
    cout << "Deviazione Standard: " << stddev << endl;

    //clean arrays
    delete []rdiams;
    rdiams = NULL;

    return 0;
}

void calcola_media_dev_std  (float vdiams[], char vcols[], int used, float medie[], float dev_std[], int* n){
    float sum_r[2] = {0.f,0.f}, sum_g[2] = {0.f,0.f}, sum_b[2] = {0.f,0.f};
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
    sum_r[0] = 0; sum_g[0] = 0; sum_b[0] = 0;
    for (int i = 0; i<used; i++){
        if (vcols[i] == 'r'){
            sum_r[0] += powf(vdiams[i]-medie[0], 2.f);
        } else if (vcols[i] == 'g'){
            sum_g[0] += powf(vdiams[i]-medie[1], 2.f);
        } else {
            sum_b[0] += powf(vdiams[i]-medie[2], 2.f);
        }
    }
    dev_std[0] = powf(sum_r[0] / sum_r[1], 0.5);
    dev_std[1] = powf(sum_g[0] / sum_g[1], 0.5);
    dev_std[2] = powf(sum_b[0] / sum_b[1], 0.5);

    *n = sum_r[1];
}

void calcolaStats(float data[], int used, float* median, float* med, float* stddev){
    *median = mediana(data, used);
    *med = media_float(data, used);
    *stddev = devstd_float(data, used);
}