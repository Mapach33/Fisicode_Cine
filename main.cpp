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
    float boleta_precio_total = 0;
    do{
        contador = cine::menuPrincipal();
        switch (contador)
        {
            case 1:{
                mostrar_cartelera(p);
                elegir_pelicula(p);
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