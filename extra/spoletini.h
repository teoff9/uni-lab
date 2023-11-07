//02.11.2023 by Matteo Fava
// Library containing some functions implementing the "Ciclo Spoletini"
// in different situations
// DO NOT USE IN INFO I

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

//Return the file contents in an int vector
vector<int> int_file_to_v(string path){
    vector<int> v;
    int tmp;
    ifstream data;
    
    data.open(path);
    if (data.fail()){
        cout << "Failed to read file." << endl;
    } else{
        while (data >> tmp){
            v.push_back(tmp);
        }
        return v;
    }
}