#pragma once
#include "funciones.h"


/*****************************************************/
/*                                                   */
/*             Clase Madre para todos los menu       */
/*                                                   */
/*                                                   */
/*****************************************************/

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

//Imprime un marco
void Menu::imprimirMarco(int posicionY){
    int posicionX = (anchoConsola - anchoMarco)/2;

    SetConsoleTextAttribute(miconsola,colorMarco);    //probar 

    gotoxy(posicionX, posicionY);
    cout << string (anchoMarco, char(220));

    gotoxy(posicionX, (posicionY + altoMarco  - 1));
    cout << string (anchoMarco, char(223));

    for (int i = 0; i < (altoMarco - 2); i++) {
        gotoxy(posicionX, i + (posicionY + 1));
        cout << char (186);
        gotoxy(posicionX + (anchoMarco - 1), i + (posicionY + 1));
        cout << char (186);
    }SetConsoleTextAttribute(miconsola, 15);
}

void Menu::imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado){

    int largoOpcion{19}, altoOpcion{3}; // esto se puede cambiar

    colorOpcion = 8;

    //Cambia el color de la opcion seleccionada
    if(seleccionado) {colorOpcion = colorMarco;}

    SetConsoleTextAttribute(miconsola,colorOpcion);

    gotoxy (posicionX, posicionY + 1);
    cout << string (largoOpcion, '\xDB');
    gotoxy(posicionX, posicionY);
    cout << char ('\xDA') << string (largoOpcion - 2,'\xDC') << char ('\xBF');
    gotoxy(posicionX, (altoOpcion + posicionY - 1));
    cout << char ('\xC0') << string (largoOpcion - 2,'\xDF') << char ('\xD9');

    //Cambia el color de la opcion seleccionada
    if (seleccionado) colorOpcion = colorTexto; else colorOpcion = 143;

    SetConsoleTextAttribute(miconsola, colorOpcion);
    gotoxy (posicionX + ((largoOpcion - nombreOpcion.length()) / 2), posicionY + 1);
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
    Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 144;
    colorMarco = 9;
    opcion = 1;
    imprimir();
}

void MenuPrincipal::imprimir(){
    int ejeYmarco = 7;
    altoMarco = 25;
    anchoMarco = 55;
    system("cls");
    gotoY(1);
    printRawCenter(logo_fisicode);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    ////// 
    while(continuar){
        imprimirOpcion("Cartelera", (anchoConsola - 23)/2, 14, opcion==1);
        imprimirOpcion("Salir", (anchoConsola - 23)/2 , 18, opcion==2);
        switch (getTecla()) {
    
            case tecla::w:
            case Up:
                if (opcion > 1) opcion--;
                break;
        
            case tecla::s:
            case Down:
                if (opcion < 2) opcion++;
                break;
            case Enter:
                continuar = false;
                break;
        }
    }
}
