#include <iostream>
#include <string>
#include <unordered_map> // Para usar std::unordered_map

class HashMap {
private:
    std::unordered_map<std::string, int> hashMap;

public:
    HashMap() {}

    int get(const std::string &clave) {
        // Intenta encontrar la clave en el mapa
        auto it = hashMap.find(clave);
        if (it != hashMap.end()) {
            // Si la clave está presente, devuelve el valor asociado
            return it->second;
        } else {
            // Si la clave no está presente, devuelve un valor predeterminado
            return -1; // O cualquier otro valor que desees usar para indicar que la clave no fue encontrada
        }
    }

    void put(const std::string &clave, int valor) {
        // Inserta o actualiza la clave con el valor proporcionado
        hashMap[clave] = valor;
    }

    void remove(const std::string &clave) {
        // Intenta eliminar la clave del mapa
        auto it = hashMap.find(clave);
        if (it != hashMap.end()) {
            // Si la clave está presente, elimínala del mapa
            hashMap.erase(it);
        }
        // Si la clave no está presente, no hace nada
    }

    bool esVacio() {
        // Verifica si el mapa está vacío
        return hashMap.empty();
    }
};

int main() {
    HashMap mapa;
    mapa.put("clave1", 10);
    mapa.put("clave2", 20);

    std::cout << "Valor asociado a clave1: " << mapa.get("clave1") << std::endl;
    std::cout << "Valor asociado a clave2: " << mapa.get("clave2") << std::endl;

    mapa.remove("clave1");

    std::cout << "Después de eliminar clave1, es vacío: " << (mapa.esVacio() ? "Sí" : "No") << std::endl;

    return 0;
}
