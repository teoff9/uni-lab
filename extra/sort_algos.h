//library containing sorting algorithms

//Index of the minimum value of a sliced array, i= initial index, j= final index
int pos_of_min(float data[], int i, int j){
    int k;
    float min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}


//Selection sort: identify the index of the min, the swaps it with
//the first element of the array. Procede this way swapping each time with 
//the i+1 element
void selection_sort(float data[], int n_data){
    for (int i = 0; i < n_data -1; i++){
        int k = pos_of_min(data, i, n_data-1);
        int tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }

}