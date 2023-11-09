#ifndef PROYECTO_FUNCIONES_H
#define PROYECTO_FUNCIONES_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Articulo.h"
#include "HashMap.h"

using namespace std;

/**
 * Cantidad total de artículos.
 */
int cantArt = 0;

/**
 * Hashmap que almacena el inventario de artículos, utilizando el nombre del artículo como clave.
 */
HashMap<string, Articulo> inventario;

/**
 * Cuenta el número de columnas en el archivo CSV.
 * @param nombreArchivo El nombre del archivo CSV a procesar.
 * @return El número de columnas en la primera línea del archivo.
 */
int contarColumnas(const string &nombreArchivo);

/**
 * Procesa un archivo CSV y almacena la información en el inventario.
 * @param nombreArchivo El nombre del archivo CSV a procesar.
 */
void procesarArchivoCSV(const string &nombreArchivo);

/**
 * Imprime la información de todos los artículos en el inventario.
 */
void imprimirTodo();

/**
 * Imprime la cantidad total de artículos en el inventario.
 * @return La cantidad total de artículos.
 */
void cantTotalArt();

/**
 * Imprime cantidad total de artículos diferentes en el inventario.
 * @return La cantidad total de artículos diferentes.
 */
void cantTotalArtDif();

/**
 * Imprime un listado de los artículos con un stock total menor o igual al mínimo especificado.
 * @param minStock El stock mínimo para filtrar los artículos.
 */
void listadoMinStock(int minStock);

/**
 * Imprime un listado de los artículos con un stock en un depósito específico menor o igual al mínimo especificado.
 * @param minStock El stock mínimo para filtrar los artículos.
 * @param deposito El índice del depósito para verificar el stock.
 */
void listadoMinStockDeposito(int minStock, int deposito);

/**
 * Imprime el stock total de un artículo específico.
 * @param nombreArticulo El nombre del artículo.
 */
void stockArticulo(string nombreArticulo);

/**
 * Imprime el stock de un artículo específico en un depósito dado.
 * @param nombreArticulo El nombre del artículo.
 * @param deposito El índice del depósito.
 */
void stockArticuloDeposito(string nombreArticulo, int deposito);

/**
 * Imprime un listado de los artículos con un stock total mayor o igual al máximo especificado.
 * @param maxStock El stock máximo para filtrar los artículos.
 */
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
        cantArt = cantArt + 1;
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

void CantTotalArt(){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    int cantTotal = 0;

    for (size_t i = 0; i < cantArt; ++i) {
        cantTotal = cantTotal + arregloDeArticulos[i].getStockTotal(); // Usamos la función imprimir de Articulo
    }
    delete[] arregloDeArticulos;

    cout << "\n---------------------------------------------------------------" << endl;
    cout << "CANTIDAD TOTAL DE ARTICULOS: " << cantTotal << endl;
    cout << "---------------------------------------------------------------\n" << endl;


}

void cantTotalArtDif(){
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "CANTIDAD TOTAL DE ARTICULOS DIFERENTES: " << inventario.getTamano() << endl;
    cout << "---------------------------------------------------------------\n" << endl;
}

void listadoMinStock(int minStock){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    if (minStock < 0){
        cerr << "\nERROR: Valor NO Aceptado, Ingresar Valores Positivos.\n" << endl;
        exit(1);
    }
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "LISTADO ARTICULOS CON STOCK MENOR O IGUAL A: " << minStock << " " << endl;
    cout << "---------------------------------------------------------------" << endl;
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
    if (minStock < 0){
        cerr << "\nERROR: Valor NO Aceptado, Ingresar Valores Positivos.\n" << endl;
        exit(1);//
    }if (deposito < 0 || deposito >= arregloDeArticulos[2].getCantDepositosFinales()){
        cerr << "\nERROR: Valor NO Aceptado, Deposito no existente.\n" << endl;
        exit(1);//
    }
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "LISTADO ARTICULOS CON STOCK MENOR O IGUAL A " << minStock << " EN EL DEPOSITO " << deposito + 1 << " : " << endl;
    cout << "---------------------------------------------------------------\n" << endl;

    for (size_t i = 0; i < cantArt; ++i) {

        if ( arregloDeArticulos[i].obtenerStockDeposito(deposito) <= minStock){
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
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "STOCK DEL ARTICULO " << nombreArticulo << " :" << artEncontrado.getStockTotal() << endl;
    cout << "---------------------------------------------------------------\n" << endl;
}

void stockArticuloDeposito(string nombreArticulo, int deposito){
    for (char &c : nombreArticulo) {
        c = toupper(c);
    }
    deposito = deposito - 1;
    Articulo artEncontrado;
    artEncontrado = inventario.obtener(nombreArticulo);
    if (deposito < 0 || deposito >= artEncontrado.getCantDepositosFinales()){
        cerr << "\nERROR: Valor NO Aceptado, Deposito no existente.\n" << endl;
        exit(1);//
    }
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "STOCK DEL ARTICULO " << nombreArticulo << " EN EL DEPOSITO " << deposito+1 << " : " << artEncontrado.obtenerStockDeposito(deposito) << endl;
    cout << "---------------------------------------------------------------\n" << endl;
}

void listadoMaxStock(int maxStock){
    Articulo* arregloDeArticulos;
    arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantArt);
    if (maxStock < 0){
        cerr << "\nERROR: Valor NO Aceptado, Ingresar Valores Positivos.\n" << endl;
        exit(1);
    }
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "LISTADO DE ARTICULOS CON STOCK MAYOR O IGUAL A " << maxStock << " :" << endl;
    cout << "---------------------------------------------------------------\n" << endl;

    for (size_t i = 0; i < cantArt; ++i) {
        if ( arregloDeArticulos[i].getStockTotal() >= maxStock){
            arregloDeArticulos[i].imprimir();
        }
    }
    delete[] arregloDeArticulos;
}

#endif //PROYECTO_FUNCIONES_H
