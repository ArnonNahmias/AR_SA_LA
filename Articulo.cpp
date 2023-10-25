//
// Created by dante on 24/10/2023.
//

#include "Articulo.h"

// Getters
string Articulo::getGrupo() const {
    return grupo;
}

int Articulo::getStockTotal() const {
    return stockTotal;
}

string Articulo::getNombre() const {
    return nombre;
}

string Articulo::getCodigoDeBarra() const {
    return codigoDeBarra;
}

// Setters
void Articulo::setGrupo(string grupo) {
    this->grupo = grupo;
}

void Articulo::setStockTotal(int stockTotal) {
    this->stockTotal = stockTotal;
}

void Articulo::setNombre(string nombre) {
    this->nombre = nombre;
}

void Articulo::setCodigoDeBarra(string codigoDeBarra) {
    this->codigoDeBarra = codigoDeBarra;
}

