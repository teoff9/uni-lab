//28.11.23 by Matteo Fava

//dichiarazione di sfera
struct sfera;

//load the array of spheres loading the file
//char file_name[] and returning for side effect used.
sfera* load_spheres(char file_name[], int& used);