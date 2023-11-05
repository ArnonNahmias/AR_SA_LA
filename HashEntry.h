//
// Created by dante on 4/11/2023.
//

#ifndef PROYECTO_HASHENTRY_H
#define PROYECTO_HASHENTRY_H


template <class K, class T>
class HashEntry {
private:
    K clave;
    T valor;

public:
    HashEntry(const K& key, const T& value) : clave(key), valor(value) {}

    const K& getClave() const {
        return clave;
    }

    const T& getValor() const {
        return valor;
    }

    void setValor(const T& value) {
        valor = value;
    }
};


#endif //PROYECTO_HASHENTRY_H
