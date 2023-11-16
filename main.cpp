#include "menu/menuCartelera.h"
#include "menu/menuAmbiente.hpp"
#include "menu/menuDulceriaSimplificado.h"
#include "tools/funciones.h"
#include "tools/menuss.h"
#include "menu/salaCine.h"


int main(){
    srand(time(NULL));
    MenuPrincipal menuPrincipal;

    if(menuPrincipal.getOpcion() == 1){
            elegir_pelicula();
            ele_sala();
            ele_horario();
            //MenuAsientos menuAsientos;
            elegir_combo();       
    }
    return 0;
}