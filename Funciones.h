#ifndef PROYECTO_FUNCIONES_H
#define PROYECTO_FUNCIONES_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include "Articulo.h"
#include "HashMap.h"

using namespace std;

int cantArt = 0;
HashMap<string, Articulo> inventario;

int contarColumnas(const string &nombreArchivo);

void procesarArchivoCSV(const string &nombreArchivo);

void imprimirTodo();

void stockTotal();

int cantTotalArt();

int cantTotalArtDif();

void listadoMinStock(int minStock);

void listadoMinStockDeposito(int minStock, int deposito);

void stockArticulo(string nombreArticulo);

void stockArticuloDeposito(string nombreArticulo, int deposito);

void listadoMaxStock(int maxStock);

void procesarArchivoCSV(const string &nombreArchivo) {

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    char delimitador = ',';
    getline(archivo, linea); // Leer la primera línea

    int cantDepositos = 0;
    cantDepositos = contarColumnas(nombreArchivo) - 3; // Restamos 3 a la cantidad de cabezeras, que es la cant de depositos.
    string ultimoGrupoValido;

    while (getline(archivo, linea)) {
        stringstream stream(linea);
        string grupo, codigoDeBarras, nombre;


        getline(stream, grupo, delimitador);
        if (grupo.empty()) {
            grupo = ultimoGrupoValido; // Asignar al grupo actual el último grupo válido si está vacío
        } else {
            ultimoGrupoValido = grupo; // Actualizar el último grupo válido
        }
        getline(stream, codigoDeBarras, delimitador);
        getline(stream, nombre, delimitador);

        Articulo nuevoArticulo(grupo, codigoDeBarras, nombre);

        // Leer los valores de los depósitos y agregarlos al stock total
        string depositoStr;
        int depositoInt;

        for (int i = 0; i < cantDepositos; i++) {
            getline(stream, depositoStr, delimitador);
            // Verificar si depositoStr está vacío y asignar 0 a depositoInt en ese caso
            if (depositoStr.empty()) {
                depositoInt = 0;
            } else {
                // Si depositoStr no está vacío, convertir el string a int
                stringstream(depositoStr) >> depositoInt;
            }
            nuevoArticulo.agregarDeposito(depositoInt);
        }

        inventario.insertar(nombre, nuevoArticulo);
    }

    archivo.close();
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

void imprimirTodo(){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);

    for (size_t i = 0; i < cantArt; ++i) {
        arregloDeArticulos[i].imprimir(); // Usamos la función imprimir de Articulo
    }
    delete[] arregloDeArticulos;
}

int cantTotalArt(){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    int cantTotal = 0;

    for (size_t i = 0; i < cantArt; ++i) {
        cantTotal = cantTotal + arregloDeArticulos[i].getStockTotal(); // Usamos la función imprimir de Articulo
    }
    delete[] arregloDeArticulos;

    return cantTotal;
}

int cantTotalArtDif(){
    return cantArt; //todo revisar donde se cambia esta cantidad.
}

void listadoMinStock(int minStock){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    if (minStock < 0){ //todo Cambiarlo el try catch.
        cerr << "ERROR: Valor NO Aceptado, Ingresar Valores Positivos. " << endl;
        exit(1);// Retornar 0 o lanzar una excepción según la lógica de tu aplicación.
    }
    cout << " Listado de Articulos con cantidad menor o igual a " << minStock << " :" << endl;
    for (size_t i = 0; i < cantArt; ++i) {
        if ( arregloDeArticulos[i].getStockTotal() <= minStock){
            arregloDeArticulos[i].imprimir();
        }
    }
    delete[] arregloDeArticulos;
}

void listadoMinStockDeposito(int minStock, int deposito){
    Articulo* arregloDeArticulos;
    deposito = deposito -1;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    if (minStock < 0){ //todo Cambiarlo el try catch.
        cerr << "ERROR: Valor NO Aceptado, Ingresar Valores Positivos. " << endl;
        exit(1);// Retornar 0 o lanzar una excepción según la lógica de tu aplicación.
    }
    cout << " Listado de Articulos con cantidad menor o igual a " << minStock << " en el deposito " << deposito << " : " << endl;
    for (size_t i = 0; i < cantArt; ++i) {
        if ( arregloDeArticulos[i].obtenerStockDeposito(deposito) >= minStock){
            arregloDeArticulos[i].imprimir();
        }
    }
    delete[] arregloDeArticulos;
}

void stockArticulo(string nombreArticulo){
    for (char &c : nombreArticulo) {
        c = toupper(c);
    }
    Articulo artEncontrado;
    artEncontrado = inventario.obtener(nombreArticulo);
    cout << "Stock del Articulo: " << nombreArticulo << " -----> " << artEncontrado.getStockTotal() << endl;
}

void stockArticuloDeposito(string nombreArticulo, int deposito){
    for (char &c : nombreArticulo) {
        c = toupper(c);
    }
    deposito = deposito - 1;
    Articulo artEncontrado;
    artEncontrado = inventario.obtener(nombreArticulo);
    cout << "Stock del Articulo " << nombreArticulo << " en el deposito " << deposito+1 << " -----> " << artEncontrado.obtenerStockDeposito(deposito) << endl;
}

void listadoMaxStock(int maxStock){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    if (maxStock < 0){ //todo Cambiarlo el try catch.
        cerr << "ERROR: Valor NO Aceptado, Ingresar Valores Positivos. " << endl;
        exit(1);// Retornar 0 o lanzar una excepción según la lógica de tu aplicación.
    }
    cout << " Listado de Articulos con cantidad mayor o igual a " << maxStock << " :" << endl;
    for (size_t i = 0; i < cantArt; ++i) {
        if ( arregloDeArticulos[i].getStockTotal() >= maxStock){
            arregloDeArticulos[i].imprimir();
        }
    }
    delete[] arregloDeArticulos;
}




#endif //PROYECTO_FUNCIONES_H
