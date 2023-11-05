//
// Created by dante on 24/10/2023.
//

#ifndef PROYECTO_ARTICULO_H
#define PROYECTO_ARTICULO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Articulo {
private:
    string grupo;
    string codigoDeBarras;
    string nombre;
    vector<string> depositos;
public:
    Articulo() {}
    Articulo(const string &grupo, const string &codigoDeBarras, const string &nombre) :
            grupo(grupo), codigoDeBarras(codigoDeBarras), nombre(nombre) {}

    void agregarDeposito(const std::string &deposito) {
        depositos.push_back(deposito);
    }

    void imprimir() {
        int cantDepositos = depositos.size();
        cout << "> Grupo: " << grupo << endl;
        cout << "> Codigo de Barras: " << codigoDeBarras << endl;
        cout << "> Nombre: " << nombre << endl;
        for (int i = 0; i < cantDepositos; i++) {
            cout << "> Deposito " << i+1 << ": " << depositos[i] << endl;
        }
        cout << "|---------------------------------------|" << endl;
    }

    const string &getNombre() const {
        return nombre;
    }



};


#endif //PROYECTO_ARTICULO_H
