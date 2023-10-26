//Esto es para ir probando las funciones nada mas
#include <iostream>
#include <windows.h>
#include "menu/menuPrincipal.hpp"
#include "menu/menu_cartelera.h"
#include "menu/header_ambiente.hpp"
//#include <stdio.h>
#include "funciones.h"
int main(){
   int p;
    switch ( cine::menuPrincipal())
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
}
//en vscode para compilar -> g++ Prueba.cpp -o prueba
