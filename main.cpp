#include <iostream>
#include <windows.h>
#include "menu/menuPrincipal.hpp"
#include "menu/menuCartelera.h"
#include "menu/menuAmbiente.hpp"
#include "menu/menuDulceria.h"
#include "tools/funciones.h"

int main(){
   
    do{
       
        switch (cine::menuPrincipal())
        {
            case 1:{
                mostrar_cartelera();
                elegir_pelicula();
                menu_ambiente();
                ele_sala();
                ele_horario();
                dulceria();
                fdulceria();
                break;       
            }
            case 2:{
                
                break;
            }
            case 3:{
                    
                break;
            }
        }
    }while(cine::menuPrincipal() !=3 );
    return 0;
}