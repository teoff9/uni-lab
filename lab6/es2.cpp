//07.11.2023 by Matteo Fava

#include <iostream>
using namespace std;
#include <fstream>
#include <cmath>


#define NN 150

//Funzione che restituisce la media dei valori vdiams riferiti al colore
// vdiams e vcols, array contenenti diametri e char b,g,r
// used: numero di dati in vdiams, vcols
// c: char di cui vogliamo fare la media dei diametri
float media_by_char(float vdiams[], char vcols[], int used, char c);

//Funzione che restituisce la dev std dei valori vdiams riferiti al colore
// vdiams e vcols, array contenenti diametri e char b,g,r
// used: numero di dati in vdiams, vcols
// c: char di cui vogliamo fare la dev std dei diametri
float dev_std_by_char(float vdiams[], char vcols[], int used, char c);

//Funzione che ordini i valori: b < g < r con i valori di vdiams
// vdiams e vcols, array contenenti diametri e char b,g,r
// used: numero di dati in vdiams, vcols
void sorting_spheres(float vdiams[], char vcols[], int used);

//Pos of min 
//vdiams and vcols: vectors of floats and chars
//int i: initial index of the search
//int j: final index of the search
int pos_of_min(float vdiams[], char vcols[], int i, int j);


void sorting(float vdiams[], char vcols[], int used);


int main(){
    ifstream data;
    ofstream out;
    float vdiams[NN];
    char vcols[NN];
    int used = 0;

    //apri data
    data.open("data/sfere.dat");
    if (data.fail()){
        cout << "Failed to read file" << endl;
        return -1;
    }

    //carica i dati nei due array con un ciclo spoletini
    while (used < 150 && data >> vdiams[used] && data >> vcols[used]){
        used ++;
    }
    data.close();

    //calcola media e dev standard
    float m_r = media_by_char(vdiams, vcols, used, 'r');
    float dev_r = dev_std_by_char(vdiams, vcols, used, 'r');
    float m_b = media_by_char(vdiams, vcols, used, 'b');
    float dev_b = dev_std_by_char(vdiams, vcols, used, 'b');
    float m_g = media_by_char(vdiams, vcols, used, 'g');
    float dev_g = dev_std_by_char(vdiams, vcols, used, 'g');

    //print
    cout << m_r << " " << dev_r << endl;
    cout << m_b << " " << dev_b << endl;
    cout << m_g << " " << dev_g << endl;

    //sorting e output in differente file
    sorting_spheres(vdiams, vcols, used);
    out.open("data/output/sorted_spheres.dat");
    for (int i = 0; i < used; i++){
        out << vdiams[i] << " " << vcols[i] << endl;
    }
    out.close();


    return 0;
}



//Definizioni
float media_by_char(float vdiams[], char vcols[], int used, char c){
    float sum = 0;
    int N = 0;
    for (int i = 0; i < used; i++){
        if (vcols[i] == c){
            sum += vdiams[i];
            N++;
        }
    }
    return sum/N;
}


float dev_std_by_char(float vdiams[], char vcols[], int used, char c){
    float media = media_by_char(vdiams, vcols, used, c);
    float sum = 0;
    int N = 0;
    for (int i = 0; i < used; i++){
        if (vcols[i] == c){
            sum += powf(vdiams[i]-media, 2.0);
            N++;
        }
    }

    return powf(sum/N, 0.5);
}


void sorting_spheres(float vdiams[], char vcols[], int used){
    for (int i = 0; i<used -1; i++){
        int k = pos_of_min(vdiams, vcols, i, used);
        std::swap(vdiams[i], vdiams[k]);
        std::swap(vcols[i], vcols[k]);
    }

}


int pos_of_min(float vdiams[], char vcols[], int i, int j){
    int k = 0;
    float d_min = vdiams[i];
    char c_min = vcols[i];
    for (i; i<j; i++){
        if (vdiams[i]<=d_min && vcols[i]<=c_min){
            k = i;
            d_min = vdiams[i];
            c_min = vcols[i];
        }
    }
    return k;
}