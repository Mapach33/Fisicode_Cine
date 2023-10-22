//Esto es para ir probando las funciones nada mas
#include <iostream>
#include <windows.h>
#include "menu/BaseMenu.hpp"
#include "menu/menu_cartelera.h"
#include "menu/header_ambiente.hpp"

#define ancho 1200 // max 1920
#define altura 700 // max 1080

#include "funciones.h"
int main(){
    cine::setConsoleSizeCenter(ancho, altura); // <- usen esta funcion es GODXD
    int p;
    short contador = cine::menuPrincipal();
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
                
                break;
            }
            case 3:{

                break;
            }
        }
        return 0;
}