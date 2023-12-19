//24.10.23 by Matteo Fava

//Libreria di statistica


//media di un array di int con used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
float media_int(int data[], int used);

//media di un array di float con used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
float media_float(float data[], int used);

//dev. std. di array di double con double used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
double media_double(double data[], int used);

//dev. std. di array di int con int used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
float devstd_int(int data[], int used);

//dev. std. di array di float con int used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
float devstd_float(float data[], int used);

//dev. std. di array di double con int used come numero di dati usati
//data: array di dati
//used: numero di dati usati nell'array
double devstd_double(double data[], int used);

//restituisce se un val e' |val-media| > 3stdDev
//val: float del valore 
//media: media del campione di dati
//std_dev: deviazione standard di dati
bool is_outlier_float(float val, float media, float std_dev);

//restituisce la mediana di un insieme ordinato di float
//data: array di float
//used: int che indica il num di elementi usati
float mediana_float(float data[], int used);