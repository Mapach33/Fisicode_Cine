//Esto es para ir probando las funciones nada mas
#include <iostream>
#include <windows.h>
#include "menu/menuPrincipal.hpp"
#include "menu/menuCartelera.h"
#include "menu/menuAmbiente.hpp"
#include "menu/menuDulceria.h"
#include "tools/funciones.h"

int main(){
    int p;
    short contador;
    do{
        contador = cine::menuPrincipal();
        switch (contador)
        {
            case 1:{
                cartelera(p);
                mostrar_info_peliculas(p);
                menu_ambiente();
                ele_sala();
                ele_horario();
                
                break;       
            }
            case 2:{
                dulceria();
                fdulceria();
                break;
            }
            case 3:{
                    
                break;
            }
        }
    }while(contador != 3 );
    return 0;
}