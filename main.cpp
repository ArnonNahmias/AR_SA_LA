#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
using namespace std;

void chopCSV(string filename, int lines);
int cantArg=0;
void exploreCSV(string filename){
    //int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int colsOfInterest[] = {0, 1,  2, 3, 4, 5, 6, 7};  //puede variar
    int nColumns=sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    int cant = 0;
    fstream fin;

    fin.open("./" +filename, ios::in);

    vector <string> row;
    string line, word;
    int confirmed=0;
    int total=0;

    while( getline(fin, line)){
        total++;
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            if (word.size() > 0){
                word = word.substr(0, word.size());
            }else{
                word = "NA";
            }
            row.push_back(word); //igual a insertarUltimo
        }
        for (int i = 0; i < nColumns; i++)
        {
            cant++;
        }
    }
    cout << "\n>> Cantidad de Art. Dif.: " << cant/cantArg << endl;
}

void exploreHeaders(string fileName){
    fstream fin;
    fin.open("./" + fileName, ios::in);

    string headers, header;
    getline(fin, headers);
    stringstream s(headers);
    while (getline(s, header, ','))
    {
        cout<< header << endl;
        cantArg++;
    }
}

int main(int argc, char **argv)
{
    cout << "Cantidad de argumentos: " << argc << endl;
    for (int i=0 ; i < argc; i++)
    {
        cout << "Argumento " << i << ": " <<argv[i] << endl;

        if (strcmp(argv[i], "-file") == 0){
            cout << "Nombre del archivo: " << argv[i+1] << endl;
            exploreHeaders(argv[i+1]);
            exploreCSV(argv[i+1]);
            break;
        }
    }
    return 0;
}

