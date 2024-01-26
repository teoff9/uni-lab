//26.01.24 by Matteo Fava
//File contenente le definizioni delle funzioni usate durante l'esame pratico

#include "lib.h"
#include <iostream>
#include <fstream>
using namespace std;

//funzione per stampare a video il giocatore
void print_giocatore(giocatore gioc){
    cout << "Cod = " << gioc.cod << " | is_pro = " << gioc.is_pro << " | tot_punti = " << gioc.tot_punt << " | nmani = " << gioc.nmani << endl;
}

//funzione per stampare a video la mano
void print_mano(mano m){
    cout << "Cod = " << m.cod << " | Punti = " << m.punti << endl;
}

//funzione per caricare in array_giocatore da file
array_giocatore load_giocatori(char file_name[], int &err_code){
    array_giocatore v;
    ifstream inp;
    int cod;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load giocatori" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> cod){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new giocatore[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> cod) {
        v.raw[v.used].cod = cod;
        if (cod <= 1000) v.raw[v.used].is_pro = true;
        else v.raw[v.used].is_pro = false;
        v.raw[v.used].tot_punt = 0;
        v.raw[v.used].nmani = 0;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione per caricare in array_mano da file
array_mano load_mani(char file_name[], int &err_code){
    array_mano v;
    ifstream inp;
    int cod, punti;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load mani" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> cod && inp >> punti){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new mano[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> cod && inp >> punti) {
        v.raw[v.used].cod = cod;
        v.raw[v.used].punti = punti;
        v.used ++;
    }
    inp.close();

    return v;
}

//funzione per contare i professionisti in un array di giocatori
int count_pro(array_giocatore iscritti){
    int n = 0;
    for (int i = 0; i<iscritti.used; i++){
        if (iscritti.raw[i].is_pro) n++;
    }
    return n;
}

//funzione che stampa a video le specifiche dei primi n e ultimi n giocatori
void print_iscritti_sample(array_giocatore iscritti, int n, bool full){
    cout << "Primi " << n << " iscritti\n";
    for (int i = 0; i<n; i++){
        if (!full){
            cout << "Cod = " << iscritti.raw[i].cod;
            if (iscritti.raw[i].is_pro) cout << " pro\n";
            else cout << " ama\n";
        } else print_giocatore(iscritti.raw[i]);
        
    }
    cout << "Ultimi " << n << " iscritti\n";
    for (int i = iscritti.used-n; i<iscritti.used; i++){
        if (!full){
            cout << "Cod = " << iscritti.raw[i].cod;
            if (iscritti.raw[i].is_pro) cout << " pro\n";
            else cout << " ama\n";
        } else print_giocatore(iscritti.raw[i]);
    }
}

//funzione che stampa a video le specifiche dei primi e ultimi n punteggi
void print_mani_sample(array_mano mani, int n){
    cout << "Prime " << n << " mani\n";
    for (int i = 0; i<n; i++){
        print_mano(mani.raw[i]);
    }
    cout << "Ultime " << n << " mani\n";
    for (int i = mani.used-n; i<mani.used; i++){
        print_mano(mani.raw[i]);
    }
}

//funzione che aggiorna i campi dei giocatori
void aggiorna_giocatori(array_giocatore iscritti, array_mano punti){
    for (int i = 0; i< punti.used; i++){
        for (int j = 0; j<iscritti.used; j++){
            if (iscritti.raw[j].cod == punti.raw[i].cod){
                iscritti.raw[j].tot_punt += punti.raw[i].punti;
                iscritti.raw[j].nmani ++;
            }
        }
    }
}

//funzione accessoria per il sort dell'array di giocatori
//che performa il merge di due sottovettori contigui
void merge_giocatori(giocatore data[], int i, int m, int f){
    int j, k, z;
    giocatore* tmp;
    tmp = new giocatore[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].tot_punt >= data[k].tot_punt) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}

//funzione che sorta l'array di giocatori in ordine decrescente (dal punteggio piu' alto al piu' piccolo)
//l'array di giocatori usando il merge sort
void merge_sort_giocatori(giocatore data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_giocatori(data, init, m);
        merge_sort_giocatori(data, m+1, final);
        merge_giocatori(data, init, m, final);
    }
}

//funzione che aggiorna la classifica nazionale di ogni giocatore che ha partecipato al torneo
//il punteggio viene aggiornato se se solo se nmani == 5
void aggiorna_classifica(array_giocatore iscritti, array_mano classifica){
    for (int i = 0; i<classifica.used; i++){
        for (int j = 0; j<iscritti.used; j++){
            if (iscritti.raw[j].cod == classifica.raw[i].cod && iscritti.raw[j].nmani == 5){
                classifica.raw[i].punti += iscritti.raw[j].tot_punt;
            }
        }
    }
}

//funzione accessoria per il sort dell'array di mani
//che performa il merge di due sottovettori contigui
void merge_mano(mano data[], int i, int m, int f){
    int j, k, z;
    mano* tmp;
    tmp = new mano[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].punti >= data[k].punti) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}

//funzione che sorta l'array di mani in ordine decrescente (dal punteggio piu' alto al piu' piccolo)
//l'array di giocatori usando il merge sort
void merge_sort_mani(mano data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_mani(data, init, m);
        merge_sort_mani(data, m+1, final);
        merge_mano(data, init, m, final);
    }
}

//funzione per stampare a file il giocatore
void out_giocatore(giocatore gioc, ofstream& out){
    out << "Cod = " << gioc.cod << " | is_pro = " << gioc.is_pro << " | tot_punti = " << gioc.tot_punt << " | nmani = " << gioc.nmani << endl;
}

//funzione per stampare a file la mano
void out_mano(mano m, ofstream& out){
    out << "Cod = " << m.cod << " | Punti = " << m.punti << endl;
}

//funzione che stampa a file le specifiche dei primi n e ultimi n giocatori
void out_iscritti_sample(array_giocatore iscritti, int n, bool full, ofstream& out){
    out << "Primi " << n << " iscritti\n";
    for (int i = 0; i<n; i++){
        if (!full){
            out << "Cod = " << iscritti.raw[i].cod;
            if (iscritti.raw[i].is_pro) out << " pro\n";
            else out << " ama\n";
        } else out_giocatore(iscritti.raw[i], out);
        
    }
    out << "Ultimi " << n << " iscritti\n";
    for (int i = iscritti.used-n; i<iscritti.used; i++){
        if (!full){
            out << "Cod = " << iscritti.raw[i].cod;
            if (iscritti.raw[i].is_pro) out << " pro\n";
            else out << " ama\n";
        } else out_giocatore(iscritti.raw[i], out);
    }
}

//funzione che stampa a file le specifiche dei primi e ultimi n punteggfi
void out_mani_sample(array_mano mani, int n, ofstream& out){
    out << "Prime " << n << " mani\n";
    for (int i = 0; i<n; i++){
        out_mano(mani.raw[i], out);
    }
    out << "Ultime " << n << " mani\n";
    for (int i = mani.used-n; i<mani.used; i++){
        out_mano(mani.raw[i], out);
    }
}