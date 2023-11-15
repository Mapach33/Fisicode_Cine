#pragma once
#include "funciones.h"
#include "consola.hpp"
//Clase madre
class Menu{
    public:
        Menu();
        void imprimirMarco(int posicionY);
        void imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado);
        int getOpcion();
    protected:
        HANDLE miconsola;
        int anchoConsola, altoConsola;
        int opcion, altoMarco, anchoMarco, colorMarco, colorOpcion, colorTexto;
        bool seleccionado;
};

Menu::Menu(){
    miconsola = GetStdHandle(STD_OUTPUT_HANDLE);
}

int Menu::getOpcion(){
    return opcion;
}

void Menu::imprimirMarco(int posicionY){
    int posicionX = (cine::getConsoleSize().x - anchoMarco)/2;

    SetConsoleTextAttribute(miconsola,colorMarco);    //probar 

    cine::gotoxy(posicionX, posicionY);
    cout << string (anchoMarco, char(220));

    cine::gotoxy(posicionX, (posicionY + altoMarco  - 1));
    cout << string (anchoMarco, char(223));

    for (int i = 0; i < (altoMarco - 2); i++) {
        cine::gotoxy(posicionX, i + (posicionY + 1));
        cout << char (186);
        cine::gotoxy(posicionX + (anchoMarco - 1), i + (posicionY + 1));
        cout << char (186);
    }SetConsoleTextAttribute(miconsola, 15);
}

void Menu::imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado){

    int largoOpcion{19}, altoOpcion{3}; // esto se puede cambioar

    colorOpcion = 120;
    if(seleccionado) {colorOpcion = colorMarco;}
    SetConsoleTextAttribute(miconsola,colorOpcion);

    cine::gotoxy (posicionX, posicionY + 1);
    cout << string (largoOpcion, '\xDB');
    cine::gotoxy(posicionX, posicionY);
    cout << char ('\xDA') << string (largoOpcion - 2,'\xDC') << char ('\xBF');
    cine::gotoxy(posicionX, (altoOpcion + posicionY - 1));
    cout << char ('\xC0') << string (largoOpcion - 2,'\xDF') << char ('\xD9');

    if (seleccionado) colorOpcion = colorTexto; else colorOpcion = 143;
    SetConsoleTextAttribute(miconsola, colorOpcion);
    cine::gotoxy (posicionX + ((largoOpcion - nombreOpcion.length()) / 2), posicionY + 1);
    cout << nombreOpcion;

    SetConsoleTextAttribute(miconsola, 15);
}

/***********************************************/
/*                                             */
/*             Clase Menu Principal            */
/*                                             */
/*                                             */
/***********************************************/

class MenuPrincipal : public Menu{
    public:
        MenuPrincipal();
        void imprimir();
};

MenuPrincipal::MenuPrincipal(){
    altoConsola = 40;
    anchoConsola = 150;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuPrincipal::imprimir(){
    system("COLOR 70");
    int ejeYmarco = 7;
    altoMarco = 25;
    anchoMarco = 55;
    system("cls");
    cine::gotoY(1);
    cine::printRawCenter(cine::logo_fisicode);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("Cartelera", (anchoConsola - 23)/2, 14, opcion==1);
        imprimirOpcion("Salir", (anchoConsola - 23)/2 , 18, opcion==2);
        switch (cine::getch()) {
    
            case key::w:
            case Up:
                if (opcion > 1) opcion--;
                break;
        
            case key::s:
            case Down:
                if (opcion < 2) opcion++;
                break;

            case Enter:
                continuar = false;
                break;
        }
    }
}
