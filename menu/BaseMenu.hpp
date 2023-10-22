//MENU PRINCIPAL (?
#pragma once // <- Esto sirve para que no haya errores por incluir dos veces una misma lib
#include "../funciones.h"
namespace cine {
    int menuPrincipal(){
        cine::clear();
        cine::setConsoleSizeCenter(1000, 700);
        short opcion = 1;
        int centroX = getConsoleSize().x/2-9;
        short ejeYmenu = 12;
        cine::imprimirMarco(21,9,{centroX-5,ejeYmenu-2});
        cine::gotoxy(0,2);
        cine::printRawCenter(cine::logo_fisicode);


        while (1) {
            cine::setCursorVisible(false);
            gotoxy(centroX,ejeYmenu);print ("  Menu:  \n");
            gotoX(centroX);print    ("Cartelera\n");
            gotoX(centroX);print    (" Dulceria\n"); 
            gotoX(centroX);print    ("  Salir  \n");

            gotoxy(centroX-2,ejeYmenu+opcion);print(char(175));
            gotoxy(centroX+11,ejeYmenu+opcion);print(char(174));

            switch (cine::getch()) {
                case cine::key::Up : // Tecla flecha arriba
                    if (opcion > 1) {
                        gotoxy(centroX-2,ejeYmenu+opcion);print("  ");
                        gotoxy(centroX+11,ejeYmenu+opcion);print("  ");
                        opcion--;
                    }
                    break;
                case cine::key::Down :  // Tecla flecha abajo
                    if (opcion < 3) {
                        gotoxy(centroX-2,ejeYmenu+opcion);print("  ");
                        gotoxy(centroX+11,ejeYmenu+opcion);print("  ");
                        opcion++;
                    }
                    break;
                case cine::key::Enter : // Tecla Enter
                    return opcion;
                    break;
            }
        }
    }  
}// namespaces cine