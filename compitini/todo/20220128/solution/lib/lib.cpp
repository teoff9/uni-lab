//09.01.23 by Matteo Fava
//File contenente le definizioni delle funzioni usate nel compitino

#include "lib.h"
#include <iostream>
#include <fstream>
using namespace std;

//struct netpacket
//struct netpacket{
//int time;// timestamp del pacchetto
//double db; // qualita' del pacchetto
//char data; // carattere del messaggio


//stampa a video un pacchetto
void print_packet(netpacket pk){
    cout << "Time: " << pk.time << " | Quality: " << pk.db << " | Data: " << pk.data << endl;
}

//carica un array di netpacket(s) da un file
array_packets load_data(char file_name[], int &err_code){
    array_packets v;
    ifstream inp;
    int time;
    double db;
    char data;

    v.size = 0;
    v.used = 0;
    v.raw = NULL;
    err_code = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load punti" << endl;
        err_code = -1;
        return v;
    }

    //conta i punti
    while (inp >> time && inp >> db && inp >> data){
        v.size ++;
    }

    //alloca dinamicamente il vettore
    v.raw = new netpacket[v.size];

    //controlla di aver creat l'array
    if (v.raw == NULL) {
        err_code = -2;
        v.size = 0;
        return v;
    }

    //azzera inp
    inp.clear();
    inp.seekg(0, ios::beg);

    while (inp >> time && inp >> db && inp >> data) {
        v.raw[v.used].time = time;
        v.raw[v.used].db = db;
        v.raw[v.used].data = data;
        v.used ++;
    }
    inp.close();

    return v;
}

//conta i pacchetti che abbiano db maggiore di int db
int count_by_db(array_packets data, int db){
    int n = 0;
    for (int i = 0; i<data.used; i++){
        if (data.raw[i].db >= db) n++;
    }
    return n;
}

//funzione che rimuova un elemento (by swap) da un array_packets
void delete_packet(array_packets &data, int where){
    if (where>= 0 && where<= data.used-1){
        netpacket tmp = data.raw[where];
        data.raw[where] = data.raw[data.used-1];
        data.raw[data.used-1] = tmp;
        data.used -= 1;
    } else {
        cout << "Eliminazione non possibile: indice fuori range" << endl;
    }
}

//funzione che rimuove i corrotti (file che abbiano db < int db)
//stampa sul file data/corrotti.out le descrizioni dei pacchetti corrotti
void remove_corrotti(array_packets &data, int db, ofstream &corrotti){
    //rimuovi corrotti stampandoli allo stesso tempo su corrotti.out
    for (int i = 0; i<data.used; i++){
        if (data.raw[i].db < db){
            corrotti << "Time: " << data.raw[i].time << " | Quality: " << data.raw[i].db << " | Data: " << data.raw[i].data << endl;
            delete_packet(data, i);
            i--;
        }
    }
}

//funzione che fa il merge di due sottovettori contigui di netpackets
void merge_netpackets(netpacket data[], int i, int m, int f){
    int j, k, z;
    netpacket* tmp = NULL; 
    tmp = new netpacket[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    //inizia a copiare gli elementi ordinandoli
    while (j <= m && k <= f){
        if (data[j].time <= data[k].time) {
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
    //pulisci tmp
    delete []tmp;
    tmp = NULL;
}

//funzione che esegue il merge sort in base al timestamp di un vettore di netpackets
void merge_sort_packets_by_timestamp(netpacket data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_packets_by_timestamp(data, init, m);
        merge_sort_packets_by_timestamp(data, m+1, final);
        merge_netpackets(data, init, m, final);
    }
}

//funzione che stampa a video i primi int n e gli ultimi n
//elementi di un array di netpackets
void print_sample(array_packets data, int n){
    cout << "Primi " << n << " pacchetti:\n";
    for (int i = 0; i<n; i++){
        print_packet(data.raw[i]);
    }
    cout << "\nUltimi " << n << " pacchetti:\n";
    for (int i = data.used-n; i<data.used; i++){
        print_packet(data.raw[i]);
    }
    cout << "\n";
}

//funzione che stampa su risultati.dat i primi int n e gli ultimi n
//elementi di un array di netpackets
void dump_sample(array_packets data, int n, ofstream &risultati){
    risultati << "Primi " << n << " pacchetti:\n";
    for (int i = 0; i<n; i++){
        risultati << "Time: " << data.raw[i].time << " | Quality: " << data.raw[i].db << " | Data: " << data.raw[i].data << endl;
    }
    risultati << "\nUltimi " << n << " pacchetti:\n";
    for (int i = data.used-n; i<data.used; i++){
        risultati << "Time: " << data.raw[i].time << " | Quality: " << data.raw[i].db << " | Data: " << data.raw[i].data << endl;
    }
    risultati << "\n";
}

//funzione che stampa su risultati.dat i dati richiesti
void dump_num_corretti(array_packets data, ofstream &risultati){
    risultati << "Caricati " << data.used << " data.\n";
    risultati << count_by_db(data, 90) << " pacchetti hanno una qualita' >= 90.\n";
    risultati << data.used - count_by_db(data, 90) << " pacchetti hanno una qualita' <= 90.\n\n";
}

//funzione per stampare a video il messaggio
void print_message(array_packets data){
    cout << "Messaggio:\n";
    for (int i = 0; i<data.used; i++){
        if (data.raw[i].data == '#') cout << " ";
        else if (data.raw[i].data == '?') cout << "\n";
        else cout << data.raw[i].data;
    }
    cout << "\n\n";
}

//funzione per stampare su filestream il messaggio
void dump_message(array_packets data, ofstream &messaggio){
    for (int i = 0; i<data.used; i++){
        if (data.raw[i].data == '#') messaggio << " ";
        else if (data.raw[i].data == '?') messaggio << "\n";
        else messaggio << data.raw[i].data;
    }
    messaggio << "\n\n";
}
