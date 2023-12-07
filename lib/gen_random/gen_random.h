//05.11.23 by Matteo Fava
//Contiene le dichiarazioni della libreria
//per generare numeri casuali

//Funzione che genera un un numero tra 0 e 1
double rand_n();

//Funzione per generare un numero random nell'intervallo:
//double min : min
//double max : max
double rand_uniform(double min, double max);

//Funzione per generare un numero a caso da una
//popolazione Gaussiana di media e dev. standard assegnata
//usando la trasformazione di Box-Muller
double rand_gaussian(double median, double dev_std);

//Funzione per settare il seed di cstdlib
void set_seed();