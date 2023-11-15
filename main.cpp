#include "menu/menuCartelera.h"
#include "menu/menuAmbiente.hpp"
#include "menu/menuDulceriaSimplificado.h"
#include "tools/funciones.h"
#include "tools/menuss.h"
#include "menu/salaCine.h"

int main(){
    

    MenuPrincipal menuPrincipal;

    if(menuPrincipal.getOpcion() == 1){
                
                // mostrar_cartelera();
                elegir_pelicula();
                menu_ambiente();
                ele_sala();
                ele_horario();
                MenuAsientos menuAsientos; cin.get();
                
                Combos();
                ElegirCombos();
                
    }
    return 0;
}