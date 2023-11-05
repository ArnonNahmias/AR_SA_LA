#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
#include "Articulo.h"
#include <unordered_map>

#define NOMBRE_ARCHIVO "Inventario.csv"
using namespace std;

unordered_map<string, Articulo> inventario; //
int cantArt = 0;

int contarColumnas(const string &nombreArchivo);

void procesarArchivoCSV(const string &nombreArchivo);

void anadirInventario(Articulo);

Articulo buscarArticulo(string);

int main(int argc, char **argv)
{
    for (int i=0 ; i < argc; i++)
    {
        cout << "Argumento " << i << ": " <<argv[i] << endl;

        if (strcmp(argv[i], "-file") == 0){
            cout << "Nombre del Archivo ---> " << argv[i+1] << endl;
            procesarArchivoCSV(argv[i+1]);
        }
        if (strcmp(argv[i], "-cantArt") == 0){
            cout << "\nCantidad de Articulos ---> " << cantArt << endl;
        }

    }

    return 0;
}

int contarColumnas(const string &nombreArchivo){
// Abre el archivo CSV en modo de lectura
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    string primeraLinea;
    getline(archivo, primeraLinea);  // Leer la primera línea

    // Utiliza un stringstream para separar los campos de la primera línea
    istringstream ss(primeraLinea);
    string campo;
    int contadorColumnas = 0;

    // Cuenta los campos de la primera línea
    while (getline(ss, campo, ',')) {
        contadorColumnas++;
    }

    // Cierra el archivo
    archivo.close();

    return contadorColumnas;
}

void procesarArchivoCSV(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    char delimitador = ',';
    getline(archivo, linea); // Leer la primera línea

    int cantDepositos=0;
    cantDepositos = contarColumnas(nombreArchivo) - 3;

    while (getline(archivo, linea)) {
        stringstream stream(linea);
        string Grupo, CodigoDeBarras, Nombre;
        vector<string> depositos;

        getline(stream, Grupo, delimitador);
        getline(stream, CodigoDeBarras, delimitador);
        getline(stream, Nombre, delimitador);

        Articulo nuevoArticulo(Grupo, CodigoDeBarras, Nombre);
        cantArt = cantArt +1;
        // Leer los valores de los depósitos y agregarlos al objeto Articulo
        string deposito;

        for (int i=0; i < cantDepositos; i++) {
            getline(stream, deposito, delimitador);
            nuevoArticulo.agregarDeposito(deposito);
        }
        // Imprimir el objeto Articulo
        nuevoArticulo.imprimir();
    }

    archivo.close();
}

void anadirInventario(Articulo articulo){
}

Articulo buscarArticulo(string nombre){
}
