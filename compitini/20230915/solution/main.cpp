//14.01.23 by Matteo Fava
//File contenente il main del compitino

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    array_bersaglio bersagli;
    array_colpo colpi;
    int err_b, err_c, distrutti = 0, a_segno = 0;

    //carica bersagli
    bersagli = load_bersagli("data/bersagli.dat", err_b);
    if (err_b != 0) return -1;

    //stampa a i dati richiesti
    cout << "Caricati " << bersagli.used << " bersagli, di cui " << count_distrutti(bersagli) << " distrutti e " << bersagli.used - count_distrutti(bersagli) << " non distrutti\n";
    stamp_b(bersagli);

    //carica colpi
    colpi = load_colpi("data/alzo_angolo.dat", err_c);
    if (err_c != 0) return -1;
    //stampa i dati richiesti
    cout << "Sparati " << colpi.used << " colpi.\n";
    print_sample_colpi(colpi);

    //aggiorna bersagli
    aggiorna_bersagli(bersagli, colpi, distrutti, a_segno);
    cout << "Distrutti " << distrutti << " bersagli\n";
    cout << "A segno " << a_segno << " colpi\n";
    cout << "\nBuona notte e vaff..!\n";


    //elimina bersagli
    delete []bersagli.raw;
    delete []colpi.raw;
    bersagli.raw == NULL;
    colpi.raw == NULL;

    return 0;
}