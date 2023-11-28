//28.11.23 by Matteo Fava

#include <iostream>
#include <fstream>
using namespace std;

struct sfera {
    float diam;
    char color;
};

//load the array of spheres loading the file
//char file_name[] and returning for side effect used.
sfera* load_spheres(char file_name[], int& used);

int main(){
    sfera* data = NULL;
    int used;

    data = load_spheres("data/sfere.dat", used);

    cout << "Used : " << used << endl;
    for (int i = 0; i<3; i++){
        cout << data[i].diam << " " << data[i].color << endl;
    }
    for (int i = used-3; i<used; i++){
        cout << data[i].diam << " " << data[i].color << endl;
    }

    return 0;
}

sfera* load_spheres(char file_name[], int& used){
    sfera* v;
    ifstream inp;
    float d;
    char c;
    used = 0;

    inp.open(file_name);
    if (inp.fail()){
        cout << "Failed to load spheres" << endl;
        used = -1;
        return NULL;
    }

    while (inp >> d && inp >> c){
        used ++;
    }

    inp.close();

    v = new sfera[used];
    inp.open(file_name);

    for (int i = 0; i< used; i++){
        inp >> v[i].diam;
        inp >> v[i].color;
    }

    return v;
}