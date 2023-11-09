#include "Funciones.h"
#include <ctime>
int main(int argc, char *argv[])
{
    clock_t begin;
    cout << "Comenzando a medir Tiempo...\n" << endl;
    begin = clock();

    bool opcionEncontrada = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-file") == 0) {
            cout << "\n Nombre del Archivo: " << argv[i + 1] << endl;
            procesarArchivoCSV(argv[i + 1]);
        } else if (strcmp(argv[i], "-cantTotalArt") == 0) {
            CantTotalArt();
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-cantTotalArtDif") == 0) {
            cantTotalArtDif();
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-min_stock") == 0) {
            int minStock;
            stringstream(argv[i + 1]) >> minStock;
            listadoMinStock(minStock);
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-min_stock_deposito") == 0) {
            int minStock, deposito;
            stringstream(argv[i + 1]) >> minStock;
            stringstream(argv[i + 2]) >> deposito;
            listadoMinStockDeposito(minStock, deposito);
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-stock_art") == 0) {
            stockArticulo(argv[i + 1]);
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-stock_art_dep") == 0) {
            int deposito;
            stringstream(argv[i + 2]) >> deposito;
            stockArticuloDeposito(argv[i + 1], deposito);
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-max_stock") == 0) {
            int maxStock;
            stringstream(argv[i + 1]) >> maxStock;
            listadoMaxStock(maxStock);
            opcionEncontrada = true;
        }
    }

    if (!opcionEncontrada) {
        cout << "ARGUMENTO NO VALIDO" << endl;
    }
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    cout << " * Tiempo de Ejecucion * " << endl;
    cout << elapsed_secs << endl;

    return 0;
}
