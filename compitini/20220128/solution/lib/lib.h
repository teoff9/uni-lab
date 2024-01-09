//09.01.23 by Matteo Fava
//File contenente le dichiarazioni delle funzioni usate nel compitino

#include <fstream>
using namespace std;

//struct netpacket
struct netpacket{
int time;// timestamp del pacchetto
double db; // qualita' del pacchetto
char data; // carattere del messaggio
};

//struct array net packets
struct array_packets{
    int size;
    int used;
    netpacket* raw;
};

//stampa a video un pacchetto
void print_packet(netpacket pk);

//funzione che stampa a video i primi int n e gli ultimi n
//elementi di un array di netpackets
void print_sample(array_packets data, int n);

//carica un array di netpacket(s) da un file
array_packets load_data(char file_name[], int &err_code);

//conta i pacchetti che abbiano db maggiore di int db
int count_by_db(array_packets data, int db);

//funzione che rimuova un elemento (by swap) da un array_packets
void delete_packet(array_packets &data, int where);

//funzione che rimuove i corrotti (file che abbiano db < int db)
//stampa sul file data/corrotti.out le descrizioni dei pacchetti corrotti
void remove_corrotti(array_packets &data, int db, ofstream &corrotti);

//funzione che fa il merge di due sottovettori contigui di netpackets
void merge_netpackets(netpacket data[], int i, int m, int f);

//funzione che esegue il merge sort in base al timestamp di un vettore di netpackets
void merge_sort_packets_by_timestamp(netpacket data[], int init, int final);

//funzione che stampa su risultati.dat i primi int n e gli ultimi n
//elementi di un array di netpackets
void dump_sample(array_packets data, int n, ofstream &risultati);

//funzione che stampa su risultati.dat i dati richiesti
void dump_num_corretti(array_packets data, ofstream &risultati);

//funzione per stampare a video il messaggio
void print_message(array_packets data);

//funzione per stampare su filestream il messaggio
void dump_message(array_packets data, ofstream &messaggio);