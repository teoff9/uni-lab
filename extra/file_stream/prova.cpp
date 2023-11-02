//02/11/2023 by Matteo Fava

#include <fstream>

#include <iostream>
using namespace std;

int main(){
    ifstream set1;
    ofstream set2;
    int tmp;

    set1.open("data/set2.");
    if (set1.fail()){
        cout << "Failed to open file!" << endl;
        return -1;
    }

    set2.open("data/set1.dat");
    while (set1 >> tmp){
       cout << tmp+1 << endl;
       set2 << tmp+1 << endl;
    }

    set1.close();
    set2.close();

    return 0;
}