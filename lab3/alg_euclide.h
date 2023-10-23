/*Implementazione dell'algoritmo di euclide
Determina l'MCD avendo due interi a,b>0
restituisce un int*/
int alg_euclide(int, int);

int alg_euclide(int a, int b){
    int r;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }

    return a;
}