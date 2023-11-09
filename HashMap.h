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
        return hash<K>()(clave) % capacidad;
    }

public:
    /**
     * @brief Constructor de HashMap que inicializa la capacidad de la tabla hash.
     * @param capacidad La capacidad inicial de la tabla hash (por defecto 1000).
     */
    HashMap(size_t capacidad = 1000) : capacidad(capacidad), tamano(0) {
        tabla.resize(capacidad);
    }

    /**
     * @brief Inserta un par clave-valor en la tabla hash.
     * @param clave La clave del elemento a insertar.
     * @param valor El valor del elemento a insertar.
     */
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
    /**
     * @brief Verifica si una clave está presente en la tabla hash.
     * @param clave La clave que se quiere verificar.
     * @return true si la clave está presente, false en caso contrario.
     */
    bool contieneClave(const K& clave) const {
        size_t indice = hashFunc(clave);
        const auto& lista = tabla[indice];
        return any_of(lista.begin(), lista.end(), [&clave](const HashEntry<K, V>& entry) {
            return entry.getClave() == clave;
        });
    }

    /**
     * @brief Obtiene el valor asociado con una clave específica.
     * @param clave La clave cuyo valor se desea obtener.
     * @return El valor asociado con la clave proporcionada.
     * @throw runtime_error si la clave no se encuentra en la tabla hash.
     */
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
    /**
     * @brief Elimina el par clave-valor asociado con una clave específica.
     * @param clave La clave del elemento a eliminar.
     */
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
    /**
     * @brief Obtiene el número de elementos actualmente en la tabla hash.
     * @return El tamaño actual de la tabla hash.
     */
    size_t getTamano() const {
        return tamano;
    }

    /**
     * @brief Obtiene todos los artículos en la tabla hash y los almacena en un arreglo.
     * @param count Referencia a un entero donde se almacena el número de artículos.
     * @return Puntero a un arreglo dinámico que contiene todos los artículos.
     */
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
