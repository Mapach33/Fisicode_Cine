/**************************************************/
/*                                                */
/*    @autores:                                   */ 
/*    - Cuenca Echevarria, Andre Alexander        */
/*    - Giron Altamirano, Miguel Alejandro        */
/*    - Padilla Arellano, Alejandro Manuel        */
/*                                                */
/*     https://github.com/Mapach33/Fisicode_Cine  */ 
/*                                                */  
/**************************************************/

#include "menu/menuCartelera.h"
#include "menu/menuAmbiente.hpp"
#include "menu/menuDulceria.h"
#include "menu/menuBoleta.h"
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
            MenuAsientos menuAsientos;
            elegir_combo(); 
            imprimirBoleta();      
    }
    return 0;
}