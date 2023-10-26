#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"

#define NOMBRE_ARCHIVO "Inventario.csv"
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
     ifstream archivo(NOMBRE_ARCHIVO);
     string linea;
     char delimitador = ',' ;
     getline(archivo, linea);
     while (getline(archivo, linea)) {
     stringstream stream (linea);
     string Grupo, CodigoDeBarras, Articulo, Deposito1, Deposito2, Deposito3, Deposito4, Deposito5;
     getline(stream, Grupo, delimitador);
     getline(stream, CodigoDeBarras, delimitador);
     getline(stream, Articulo, delimitador);
     getline(stream, Deposito1, delimitador);
     getline(stream, Deposito2, delimitador);
     getline(stream, Deposito3, delimitador);
     getline(stream, Deposito4, delimitador);
     getline(stream, Deposito5, delimitador);

     cout<< "-------------------" <<endl;
     cout<< "Grupo: "<<Grupo<<endl;
     cout<< "CodigoDeBarras: " << CodigoDeBarras<<endl;
     cout<< "Articulo: "<< Articulo<<endl;
     cout<< "Deposito1: "<<Deposito1<<endl;
     cout<< "Deposito2: "<<Deposito2<<endl;
     cout<< "Deposito3: "<<Deposito3<<endl;
     cout<< "Deposito4: "<<Deposito4<<endl;
     cout<< "Deposito5: "<<Deposito5<<endl;
     }
     archivo.close();

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

