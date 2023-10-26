//
// Created by dante on 24/10/2023.
// se mucho

#ifndef PROYECTO_ARTICULO_H
#define PROYECTO_ARTICULO_H

#include <string>
using namespace std;

class Articulo {
private:
    string grupo;
    int stockTotal;
    string nombre;
    string codigoDeBarra;
public:
    Articulo(string grupo, int stockTotal, string nombre, string codigoDeBarra) {
        this->grupo = grupo;
        this->stockTotal = stockTotal;
        this->nombre = nombre;
        this->codigoDeBarra = codigoDeBarra;
    }
    // Getters
    string getGrupo() const;

    int getStockTotal() const;

    string getNombre() const;

    string getCodigoDeBarra() const;

    // Setters
    void setGrupo(string grupo);

    void setStockTotal(int stockTotal);

    void setNombre(string nombre);

    void setCodigoDeBarra(string codigoDeBarra);
};


#endif //PROYECTO_ARTICULO_H
