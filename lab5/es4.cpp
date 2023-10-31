//31.10.2023 by Matteo Fava

#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream data;
    ofstream output;
    float tmp;

    data.open("dati/data.dat");
    if (data.fail()){
        cout << "Failed to read file." << endl;
        return -1;
    }

    output.open("dati/output.dat");

    data >> tmp;
    while (!data.eof()){
        output << tmp << "\n";
        data >> tmp;
    }
    output.close();

    return 0;
}