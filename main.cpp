#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
using namespace std;

void chopCSV(string filename, int lines);

void exploreCSV(string filename);

void exploreHeaders(string fileName){
    fstream fin;
    fin.open("./" + fileName, ios::in);

    string headers, header;
    getline(fin, header);
    stringstream s(headers);
    while (getline(s, header, ','))
    {
        cout<< header << endl;
    }
}

int main(int argc, char **argv)
{
    cout << "Cantidad de argumentos: " << argc << endl;
    for (int i=0 ; i < argc; i++)
    {
        cout << "Argumento " << i << ": " <<argv[i] << endl;

        if (strcmp(argv[i], ".file") ==0){
            cout << "Nombre del archivo: " << argv[i+1] << endl;
            exploreHeaders(argv[i+1]);
            break;
        }
    }
    return 0;
}

