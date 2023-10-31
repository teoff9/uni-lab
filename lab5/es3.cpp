//31.10.2023 by Matteo Fava

#include <fstream>
#include <iostream>
using namespace std;

int main(){
    
    ifstream data;
    int c = 0;
    float tmp;

    data.open("dati/data.dat");
    if (data.fail()){
        cout << "Failed to read file." << endl;
        return -1;
    }

    data >> tmp;
    while (!data.eof()){
        c++;
        data >> tmp;
    }
    
    data.close();

    cout << c << endl;

    return 0;
}
