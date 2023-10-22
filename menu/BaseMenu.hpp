//MENU PRINCIPAL (?
#pragma once // <- Esto sirve para que no haya errores por incluir dos veces una misma lib
#include "../funciones.h"
namespace cine {
    int menuPrincipal(){

        cine::clear();
        short contador = 1;
        int centroX = getConsoleSize().x/2-9;
        gotoxy(centroX-5,3);
        cine::imprimirMarco(21,9);

        while (1) {
            cine::setCursorVisible(false);
            gotoxy(centroX,5);print ("  Menu:  \n");
            gotoX(centroX);print    ("Cartelera\n");
            gotoX(centroX);print    (" Dulceria\n"); 
            gotoX(centroX);print    ("  Salir  \n");

            gotoxy(centroX-2,5+contador);print(char(175));
            gotoxy(centroX+11,5+contador);print(char(174));
            cine::gotoxy(0,16);
            cine::printRawCenter(cine::logo_fisicode);

            switch (cine::getch()) {
                case cine::key::Up : // Tecla flecha arriba
                    if (contador > 1) {
                        gotoxy(centroX-2,5+contador);print("  ");
                        gotoxy(centroX+11,5+contador);print("  ");
                        contador--;
                    }
                    break;
                case cine::key::Down :  // Tecla flecha abajo
                    if (contador < 3) {
                        gotoxy(centroX-2,5+contador);print("  ");
                        gotoxy(centroX+11,5+contador);print("  ");
                        contador++;
                    }
                    break;
                case cine::key::Enter : // Tecla Enter
                    return contador;
                    break;
            }
        }
    }  
}// namespaces cine