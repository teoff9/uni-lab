//24.10.23 by Matteo Fava

//Libreria di statistica


//media di una n-upla con n = n_data
//ritorna la media 
float media(int data[], int n_data);

//dev. std. di n-upla con n = n_data
// ritorna la dev standard
float devstd(int data[], int n_data);

//restituisce se un val e' |val-media| > 3stdDev
bool is_outlier(int val, float media, float std_dev);

//restituisce la mediana di un insieme ordinato
float mediana(float data[], int used);