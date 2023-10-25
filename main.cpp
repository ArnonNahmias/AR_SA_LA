#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
using namespace std;
int cantTitulos=0;
int cantCeldas=0;
void chopCSV(string filename, int lines);

void exploreCSV(string filename){  //"aca esta lo gordo"
    int colsOfInterest[] = {0, 1,  2, 3, 4, 5, 6, 7};  //puede variar
    int nColumns=sizeof(colsOfInterest) / sizeof(colsOfInterest[0]); // Es lo mismo que cantTitulos
    int cant = 0;

    fstream fin; //para poder manejar el archivo

    fin.open("./" +filename, ios::in); //abrimos el archivo

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
            cout << row[0, 1] << " ";
            cantCeldas++;
        }
    }

}

void exploreHeaders(string fileName){ //para encontrar los titulos
    fstream fin; //lee el archivo
    fin.open("./" + fileName, ios::in); //ruta y nombre del archivo

    string primeraLinea, titulo;
    getline(fin, primeraLinea); // Se toma la primer linea del archivo y se almacenta en 'primeraLinea'
    stringstream s(primeraLinea);  //flujo de string
    while (getline(s, titulo, ',')) //el flujo almacena en la variable titulo la palabra siempre que encuentre una ,
    {
        cout<< titulo << endl;
        cantTitulos++;
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
        }
        if (strcmp(argv[i], "-cantArt") == 0){
            cout << "\n\n>> Cantidad de Art. Dif.: " << (cantCeldas/cantTitulos)-1 << endl;
        }
    }
    return 0;
}

