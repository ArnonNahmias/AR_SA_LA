// HashMap.h
#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h"
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

template<typename K, typename V>
class HashMap {
private:
    vector<list<HashEntry<K, V>>> tabla;
    size_t capacidad;
    size_t tamano;

    size_t hashFunc(const K& clave) const {
        // Asumiendo una funcion hash genérica para K.
        return hash<K>()(clave) % capacidad;
    }

public:
    HashMap(size_t capacidad = 1000) : capacidad(capacidad), tamano(0) {
        tabla.resize(capacidad);
    }

    void insertar(const K& clave, const V& valor) {
        size_t indice = hashFunc(clave);
        auto& lista = tabla[indice];
        auto it = find_if(lista.begin(), lista.end(), [&clave](const HashEntry<K, V>& entry) {
            return entry.getClave() == clave;
        });
        if (it != lista.end()) {
            it->setValor(valor);
        } else {
            lista.emplace_back(clave, valor);
            ++tamano;
        }
    }

    bool contieneClave(const K& clave) const {
        size_t indice = hashFunc(clave);
        const auto& lista = tabla[indice];
        return any_of(lista.begin(), lista.end(), [&clave](const HashEntry<K, V>& entry) {
            return entry.getClave() == clave;
        });
    }

    V obtener(const K& clave) const {
        size_t indice = hashFunc(clave);
        const auto& lista = tabla[indice];
        auto it = find_if(lista.begin(), lista.end(), [&clave](const HashEntry<K, V>& entry) {
            return entry.getClave() == clave;
        });
        if (it != lista.end()) {
            return it->getValor();
        } else {
            throw runtime_error("Clave no encontrada");
        }
    }

    void eliminar(const K& clave) {
        size_t indice = hashFunc(clave);
        auto& lista = tabla[indice];
        auto it = find_if(lista.begin(), lista.end(), [&clave](const HashEntry<K, V>& entry) {
            return entry.getClave() == clave;
        });
        if (it != lista.end()) {
            lista.erase(it);
            --tamano;
        }
    }

    size_t obtenerTamano() const {
        return tamano;
    }

    Articulo* obtenerTodosLosArticulos(int& count) const {
        count = tamano; // Establecemos el conteo de articulos.
        if (count == 0) return nullptr; // Si no hay articulos, retornamos nullptr.

        Articulo* arreglo = new Articulo[count]; // Creamos un arreglo dinámico.--
        size_t idx = 0; // indice para el arreglo.

        // Recorremos la tabla hash.
        for (const auto& lista : tabla) {
            for (const HashEntry<K, V>& entrada : lista) {
                // Asumiendo que V es Articulo, copiamos el artículo en el arreglo.
                arreglo[idx++] = entrada.getValor();
            }
        }

        return arreglo; // Retornamos el puntero al arreglo.
    }
};

#endif // HASHMAP_H
