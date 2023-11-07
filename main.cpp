

#include "Funciones.h"

using namespace std;

int main(int argc, char **argv)
{
    for (int i=0 ; i < argc; i++)
    {
        cout << "[ Argumento " << i << ": " <<argv[i] << "]"<<endl;

        if (strcmp(argv[i], "-file") == 0){
            cout << "Nombre del Archivo ---> " << argv[i+1] << endl;
            procesarArchivoCSV(argv[i+1]);
        }
        if (strcmp(argv[i], "-cantArt") == 0){
            cout << "\nCantidad de Articulos ---> " << cantArt << endl;
        }
    }

    return 0;
}





