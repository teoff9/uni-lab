//07.11.23 by Matteo Fava

//struct di un punto
struct pointR2 {
    double x;
    double y;
};

//array di punti
struct array_pointsR2 {
    int size;
    int used;
    pointR2* raw;
};

//funzione che carica da un file formattato:
// x y
//un array di punti nel piano
array_pointsR2 load_pointsR2_from_file(char nome_file[], int& err_code);

