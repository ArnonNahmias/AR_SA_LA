//
// Created by dante on 24/10/2023.
//

#include "Articulo.h"


void Articulo::imprimir() {
    cout << "> Grupo: " << grupo << endl;
    cout << "> Código de Barras: " << codigoDeBarra << endl;
    cout << "> Nombre: " << nombre << endl;
    cout << "> Stock Total: " << stockTotal << endl;
    cout << "|----------------------------|" << endl;
}

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


