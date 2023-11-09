// HashEntry.h
#ifndef PROYECTO_HASHENTRY_H
#define PROYECTO_HASHENTRY_H

template <class K, class V>
class HashEntry {
private:
    K clave;
    V valor;

public:
    HashEntry(const K& key, const V& value) : clave(key), valor(value) {}

    const K& getClave() const {
        return clave;
    }

    const V& getValor() const {
        return valor;
    }

    void setValor(const V& value) {
        valor = value;
    }
};

#endif //PROYECTO_HASHENTRY_H
