# Laboratorio 4:  array, ciclo for e funzioni

## Intro

- Funzioni: dove e come.
- Array: una buona prassi.
- Direttive a preprocessore: costanti.

## Esercizio 1

Scrivere un programma che, dichiarato un __array__ di 10 __int__

1. lo riempia integralmente con dati (interi) letti da tastiera.
2. finito il caricamento dei dati (10 interi letti da tastiera), stampi a video il contenuto dell'array.

Svolgere l'esercizio usando prima un ciclo __while__ precondizionale e un contatore, e poi usando un ciclo __for__.

## Esercizio 2

Modificare il programma al punto precedente in modo tale che l'utente possa terminare l'inserimento dei dati prima dell'inserimento dei 10 valori interi inserendo il valore sentinella 0. Notate che il valore sentinella non va inserito nell'array, perché non è un dato. Terminato l'inserimento il programma dovrà stampare a video il numero di dati caricati e tutti e soli i dati inseriti.

SUGGERIMENTO: il numero di dati che verrà inserito non è fissato a priori. Questo suggerisce l'uso di un ciclo  __while__ precondizionale.

## Esercizio 3

Definire una funzione di nome __leggiValido__ che:

1. prende in ingresso due valori __float__, che individuano gli estremi di un intervallo __[min,max]__
2. chiede all'utente di inserire un valore e controlla che il valore inserito sia nell'intervallo __[min,max]__, fino a che il valore inserito non è _valido_, ovvero nell'intervallo.
3. restituisce il primo valore _valido_ inserito dall'utente.

NOTA: si tratta di una modifica semplice della funzione definita nell'Esercizio 3 del Lab03 di settimana scorsa....

## Esercizio 4

Modificare il programma scritto per l'Esercizio 2 in modo tale che i valori inseriti siano voti, ovvero siano tutti nell'intervallo __[18,30]__. A tal fine, usare la funzione __leggiValido__ definita nell'esercizio precedente.

## Esercizio 5

Definire le funzioni:

- __float media(int v[], int ndati)__
- __float devstd(int v[], int ndati)__

che calcolino, rispettivamente, la media e la deviazione standard di una _n-upla_ __v__ contenente __ndati__ dati.

A tal fine potrebbe essere utile sapere che la libreria __cmath__ 
(__#include \<cmath\>__)
mette a disposizione le funzioni

__float pow(float a, float p)__
e
__float sqrt(float a)__

che calcolano, la prima la potenza _p_-esima del numero _a_ e la seconda la radice quadrata di _a_.
P.S.: __sqrt(a) = pow(a,0.5f)__.

## Esercizio 6

Definire una funzione __isOutlier__ che, preso in ingresso un valore intero __val__ e due valori __float__ __media__ e __standardDev__, restituisca

- __true__ se __|val-media|>3*standardDev__
-  __false__ altrimenti

P.S.: di che tipo è il valore restituito dalla funzione?
P.P.S.: __|a| = fabs(a)__ (__fabs__ definita in __cmath__).


## Esercizio 7

Scrivere una funzione

__void scambia(int v1, int v2)__

che scambi il contenuto delle variabili intere __v1__ e __v2__.

Scrivere quindi una funzione 

__void scambia(int v[], int n, int i, int j)__

che scambi le componenti di un vettore (di __n__ elementi) in posizione __i__ e __j__. La funzione dovrà controllare che entrambi gli indici siano all'interno del range __[0,1,..,n-1]__. In caso il controllo fosse negativo (almeno uno dei due indici fuori range) la funzione dovrà stampare a video il messaggio "Indici fuori range"  e non fare nulla.

Verificare il comportamento delle due funzioni.

NOTA: __void__: è la parola chiave del C++ per indicare un "non tipo". Le funzioni scambia, in effetti, non restituiscono nulla, operano solo lo scambio.


## Esercizio 8

Scrivere una funzione __int deleteEntrySwap(float v[], int size, int used,  int where)__ che, preso in ingresso un vettore di __float__ di dimensione __n__, contenente __used__ dati, elimini l'elemento in posizione __where__ sovrascrivendo il dato ivi contenuto con l'ultimo dato (valido) dell'array (ovvero in posizione __used-1__). La funzione dovrà restituire il nuovo numero di elementi validi dell'array (__used - 1__). ATTENZIONE: la funzione dovrà controllare che __where__ sia nel range di indici validi dell'array, ovvero __0....used-1__. In caso contrario la funzione dovrà  limitarsi a stampare il messaggio "Eliminazione non possibile: indice fuori range"  e restituire il valore __used__.


## Esercizio 9

Scrivere una funzione __int deleteEntryShift(float v[], int size, int used,  int where)__ che, preso in ingresso un vettore di __float__ di dimensione __n__, contenente __used__ dati, elimini l'elemento in posizione __where__ sovrascrivendo il dato ivi contenuto con il dato successivo e "shiftando" tutti gli elementi successivi a sinistra di una posizione. Come nell'esercizio precedente, la funzione dovrà restituire il nuovo numero di elementi validi dell'array (__used - 1__) e rilevare eventuali richieste di cancellazione di un dato non presente.