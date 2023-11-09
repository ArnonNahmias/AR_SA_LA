#include "Articulo.h"
#include "HashMap.h"
#include "Funciones.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i=0 ; i < argc; i++)
    {
        cout << "[ Argumento " << i << ": " <<argv[i] << " ]"<<endl;

        if (strcmp(argv[i], "-file") == 0){
            cout << "Nombre del Archivo ---> " << argv[i+1] << endl;
            procesarArchivoCSV(argv[i+1]);
            imprimirTodo();
        }
        if (strcmp(argv[i], "-cantTotalArt") == 0){
            cout << "\nCantidad de Total de Articulos (TODO EL STOCK) ---> " << cantTotalArt() << endl;
        }
        if (strcmp(argv[i], "-cantTotalArtDif") == 0){
            cout << "\nCantidad de Total de Articulos Diferentes ---> " << cantTotalArtDif() << endl;
        }
        if (strcmp(argv[i], "-min_stock") == 0){
            int minStock;
            stringstream(argv[i+1]) >> minStock;

            listadoMinStock(minStock);
        }
        if (strcmp(argv[i], "-min_stock_deposito") == 0){
            int minStock, deposito;
            stringstream(argv[i+1]) >> minStock;
            stringstream(argv[i+2]) >> deposito;
            listadoMinStockDeposito(minStock,deposito);
        }
        if (strcmp(argv[i], "-stock_art") == 0){
            stockArticulo(argv[i+1]);
        }
        if (strcmp(argv[i], "-stock_art_dep") == 0){
            int deposito;
            stringstream(argv[i+2]) >> deposito;
            stockArticuloDeposito(argv[i+1], deposito);
        }
        if (strcmp(argv[i], "-max_stock") == 0){
            int maxStock;
            stringstream(argv[i+1]) >> maxStock;

            listadoMaxStock(maxStock);
        }
    }

    return 0;
}
    /*
    HashMap<string, Articulo> inventario;
    Articulo art("Pintura","PINT-001","Pintura Metalica Aerosol");

    inventario.insertar("PINT-001-DEPOSITO01",art);


    inventario.insertar("PINT-002-DEPOSITO01",art2);
    inventario.insertar("pepito", art3);



    size_t cantidadDeArticulos = 3;
    Articulo* arregloDeArticulos = inventario.obtenerTodosLosArticulos(cantidadDeArticulos);



    // Verificamos que hemos obtenido algún artículo
    if (arregloDeArticulos) {
        for (size_t i = 0; i < cantidadDeArticulos; ++i) {
            arregloDeArticulos[i].imprimirArticuloEnFormatoTabla(); // Usamos la función imprimir de Articulo
        }

        // No olvides liberar la memoria del arreglo cuando hayas terminado
        delete[] arregloDeArticulos;
    }

//    std::cout << "El valor para la clave Pepito es: " << endl;
//    Articulo storedArticle = inventario.obtener("Pepito");
//
//    storedArticle.imprimir();

    /*
     *
     *
     *

    // Aquí iría la lógica para procesar los argumentos de línea de comandos y ejecutar las acciones correspondientes.
    // Por el momento, este es solo un esqueleto básico.

    // Crear un hashmap para almacenar el inventario.
    HashMap<std::string, Articulo> inventario;

    // Abrir el archivo CSV y leer el contenido.
    std::ifstream archivo("InventarioCorto.csv");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    // Procesar el archivo CSV y llenar el hashmap con los datos de los artículos.
    std::string linea;
    while (getline(archivo, linea)) {
        // Aquí iría la lógica para parsear la línea y crear un objeto Articulo.
        // Por ejemplo:
        // Articulo articulo = parsearLinea(linea);
        // anadirInventario(inventario, articulo);
    }

    archivo.close();

    // Procesamiento de los argumentos de la línea de comandos.
    // Por ejemplo:
    // if (argc > 1 && std::string(argv[1]) == "-total_art_dif") {
    //     mostrarTotalArticulosDiferentes(inventario);
    // }

    return 0;

}
*/
