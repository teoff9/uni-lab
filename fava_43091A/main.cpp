//26.01.24 by Matteo Fava
//File contenente il main dell'esame pratico

#include "lib/lib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //variabili
    ofstream ris;


    //apri ofstream
    ris.open("data/risultati.out");



    //elimina array allocati dinamicamente

    //chiudi ofstram
    ris.close();

    return 0;
}