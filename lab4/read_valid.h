//24.10.23 by Matteo Fava

/*funzione dati due estremi inclusi
chiede all'autore un valore che deve
incluso nell'intervallo.*/
float read_value(float min, float max){
    float val;
    do{
        cin >> val;
    } while(val!=0 && (val<min || val>max));
    cout << "Letto il valore " <<  val << endl;
    return val;

    return val;
}