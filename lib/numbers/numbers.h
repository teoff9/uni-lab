//21.11.23 by Matteo Fava
// Dichiarazioni delle funzioni

//crivello di eratostene, applicato a v
//quando l'indice e' primo
//bool v[] : vettore di max+1 values
//int max : used e' max + 1
//restituisce n_primi per side effect
void crivello_eratostene(bool v[], int max, int* n);

//restituisce true se int n e' primo e positivo, else false
bool is_prime(int n);

//restituisce true se n e' un perfect square, else false
bool is_perfect_square(int n);