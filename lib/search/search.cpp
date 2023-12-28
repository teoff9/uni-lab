//14.12.23 by Matteo Fava
//Definizioni degli algoritmi di ricerca

int binary_search_int(int data[], int i, int f, int key){
    int j = (i+f)/2;
    if (data[j] == key) {
        return j;
    } else if (i >= f) {
        return -1;
    } else if (data[j] > key) {
        return binary_search_int(data, i, j-1, key);
    } else if (data[j] < key) {
        return binary_search_int(data, j+1, f, key);
    }

    return j;
}


int binary_search_float(float data[], int i, int f, int key){
    int j = (i+f)/2;
    if (data[j] == key) {
        return j;
    } else if (i >= f) {
        return -1;
    } else if (data[j] > key) {
        return binary_search_float(data, i, j-1, key);
    } else if (data[j] < key) {
        return binary_search_float(data, j+1, f, key);
    }

    return j;
}


int binary_search_double(double data[], int i, int f, int key){
    int j = (i+f)/2;
    if (data[j] == key) {
        return j;
    } else if (i >= f) {
        return -1;
    } else if (data[j] > key) {
        return binary_search_double(data, i, j-1, key);
    } else if (data[j] < key) {
        return binary_search_double(data, j+1, f, key);
    }

    return j;
}