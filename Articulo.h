#ifndef PROYECTO_ARTICULO_H
#define PROYECTO_ARTICULO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

// Clase que representa un artículo en el inventario.
class Articulo {
private:
    string grupo; // Grupo o categoría del artículo.
    string codigoDeBarras; // Código único del artículo.
    string nombre; // Nombre descriptivo del artículo.
    vector<int> depositos; // Lista de depósitos donde se encuentra el artículo.

public:
    // Constructor por defecto.
    Articulo() : grupo(""), codigoDeBarras(""), nombre("") {}

    // Constructor que inicializa un artículo con grupo, código de barras y nombre.
    Articulo(const string &grupo, const string &codigoDeBarras, const string &nombre) :
            grupo(grupo), codigoDeBarras(codigoDeBarras), nombre(nombre) {}

    // Agrega un nuevo depósito a la lista de depósitos del artículo.
    void agregarDeposito(const int &deposito) {
        depositos.push_back(deposito);
    }

    // Método para obtener el stock total del artículo.
    int getStockTotal() const {
        int total = 0;
        for (int cantidad : depositos) {
            total += cantidad;
        }
        return total;
    }

    // Imprime la información del artículo en consola.
    void imprimir() {
        int cantDepositos = depositos.size();
        cout << "|---------------------------------------|" << endl;

        cout << "> Grupo: " << getGrupo() << endl;
        cout << "> Codigo de Barras: " << getCodigoDeBarras()<< endl;
        cout << "> Nombre: " << getNombre() << endl;
        for (int i = 0; i < cantDepositos; i++) {
            cout << "> Deposito " << i + 1 << ": " << depositos[i] << endl;
        }
        cout << "> Stock Total: " << getStockTotal() << endl; // Usar el método obtenerStockTotal

        cout << "|---------------------------------------|" << endl;
    }

    // Método para obtener el stock de un artículo en un depósito específico por índice.
    int obtenerStockDeposito(int indice) const {
        if (indice >= 0 && indice < depositos.size()) {
            return depositos[indice];
        } else {
            cerr << "ERROR: Índice fuera de rango." << endl;
            return 0; // Retornar 0 o lanzar una excepción según la lógica de tu aplicación.
        }
    }


    // Obtiene el nombre del artículo.
    const string& getNombre() const {
        return nombre;
    }

    // Obtiene el código de barras del artículo.
    const string& getCodigoDeBarras() const {
        return codigoDeBarras;
    }

    // Obtiene el grupo del artículo.
    const string &getGrupo() const {
        return grupo;
    }

    // Establece el grupo del artículo.
    void setGrupo(const string &grupo) {
        this->grupo = grupo;
    }

    // Establece el código de barras del artículo.
    void setCodigoDeBarras(const string &codigoDeBarras) {
        this->codigoDeBarras = codigoDeBarras;
    }

    // Establece el nombre del artículo.
    void setNombre(const string &nombre) {
        this->nombre = nombre;
    }

    // Obtiene la lista de depósitos donde se encuentra el artículo.
    const vector<int> &getDepositos() const {
        return depositos;
    }

    // Establece la lista de depósitos donde se encuentra el artículo.
    void setDepositos(const vector<int> &depositos) {
        this->depositos = depositos;
    }
};

#endif //PROYECTO_ARTICULO_H
