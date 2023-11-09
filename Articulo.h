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
    int cantDepositosFinales = 0; // Cantidad de Depositos
public:
    /**
   * @brief Constructor por defecto.
   *
   * Inicializa un artículo con valores predeterminados.
   */
    Articulo() : grupo(""), codigoDeBarras(""), nombre("") {}

    /**
     * @brief Constructor que inicializa un artículo con grupo, código de barras y nombre.
     * @param grupo Grupo o categoría del artículo.
     * @param codigoDeBarras Código único del artículo.
     * @param nombre Nombre descriptivo del artículo.
     */
    Articulo(const string &grupo, const string &codigoDeBarras, const string &nombre) :
            grupo(grupo), codigoDeBarras(codigoDeBarras), nombre(nombre) {}

    /**
     * @brief Agrega un nuevo depósito a la lista de depósitos del artículo.
     * @param deposito Cantidad de artículos en el nuevo depósito.
     */
    void agregarDeposito(const int &deposito) {
        depositos.push_back(deposito);
        cantDepositosFinales++;
    }

    /**
     * @brief Método para obtener el stock total del artículo.
     * @return El stock total como un entero.
     */
    int getStockTotal() const {
        int total = 0;
        for (int cantidad : depositos) {
            total += cantidad;
        }
        return total;
    }

    /**
     * @brief Imprime la información del artículo en consola.
     */
    void imprimir() {
        int cantDepositos = depositos.size();
        cout << "|---------------------------------------|" << endl;

        cout << "> Grupo: " << getGrupo() << endl;
        cout << "> Codigo de Barras: " << getCodigoDeBarras()<< endl;
        cout << "> Nombre: " << getNombre() << endl;
        for (int i = 0; i < cantDepositos; i++) {
            cout << "> Deposito " << i + 1 << ": " << depositos[i] << endl;
        }
        cout << "> Stock Total: " << getStockTotal() << endl;

        cout << "|---------------------------------------|" << endl;
    }

    /**
     * @brief Método para obtener el stock de un artículo en un depósito específico por índice.
     * @param indice Índice del depósito a consultar.
     * @return Cantidad de stock en el depósito indicado.
     * @throw std::out_of_range si el índice está fuera de rango.
     */
    int obtenerStockDeposito(int indice) const {
        if (indice >= 0 && indice < depositos.size()) {
            return depositos[indice];
        } else {
            cerr << "ERROR: Índice fuera de rango." << endl;
            return 0; // O lanzar una excepción std::out_of_range.
        }
    }

    // Getters y setters con comentarios simplificados para Doxygen.
    const string& getNombre() const { return nombre; }
    const string& getCodigoDeBarras() const { return codigoDeBarras; }
    const string &getGrupo() const { return grupo; }
    const int &getCantDepositosFinales() const { return cantDepositosFinales; }
    void setGrupo(const string &grupo) { this->grupo = grupo; }
    void setCodigoDeBarras(const string &codigoDeBarras) { this->codigoDeBarras = codigoDeBarras; }
    void setNombre(const string &nombre) { this->nombre = nombre; }
    const vector<int> &getDepositos() const { return depositos; }
    void setDepositos(const vector<int> &depositos) { this->depositos = depositos; }
};


#endif //PROYECTO_ARTICULO_H
