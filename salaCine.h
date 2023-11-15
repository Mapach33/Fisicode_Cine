#include "tools/funciones.h"
#include "tools/consola.hpp"
#include "tools/Menuss.h"

class MenuAsientos : public Menu {
    public:
        MenuAsientos();
        void imprimir();
        void imprimirAsientos();
        string getAsiento();
    protected:
        vector<vector<int>> asientos;
        int fila, columna;
        int asiento;
};

