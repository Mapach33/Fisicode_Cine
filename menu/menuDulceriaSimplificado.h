#pragma once
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"
#include "menuAmbiente.hpp"

using namespace std;


class MenuDulceria : public Menu{
    public:
        MenuDulceria();
        void imprimir();
};

void elegir_combo() {
    int cantidad;
    string combo[] = {"Cancha Grande + 2 Gaseosas Grandes","2 Canchas Medianas + 3 Gaseosas Medianas","Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas",
         "2 Canchas Grandes + 5 Gaseosas Medianas","2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog", "Canchas Medianas + 4 Gaseosas Grandes + 4 Hot Dog"};
	string precio[] =  {"26","28","32","33","35","45"};

	MenuDulceria menuDulceria; 

	short elegir = menuDulceria.getOpcion();
	cine::ShowConsoleCursor(true);
	SetConsoleTextAttribute(hConsole, 112);
			gotoxy(42, 39);cout << "-----------------------------------------------------------------------------";
			gotoxy(42, 40);cout << "Combo    :"<<combo[elegir-1]<< endl;
			gotoxy(42, 41);cout << "Precio   :"<< precio[elegir-1] << endl; 
			gotoxy(42, 42);cout << "-----------------------------------------------------------------------------";
			do{
				gotoxy(42, 43);cout << "Cantidad : "; 
				gotoxy(53, 43);cin >> cantidad;
				if(cantidad < 1 || cantidad > 10){
					gotoxy(42, 43);cout << "Cantidad no valida, intente de nuevo...               ";getch();
					gotoxy(42, 43);cout << "                                                       ";
				}
			}while(cantidad < 1 || cantidad > 10);
		  	
			gotoxy(42, 44);cout << "Agradecemos su Compra..."; getch();

	ofstream Grabacion("boleta.txt", ios::out);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<combo[elegir-1]<<endl;//Tipo
			Grabacion<<precio[elegir-1]<<endl;//Cantidad
			Grabacion<<combo[elegir-1]<<endl;//Precio U
			Grabacion<<combo[elegir-1]<<endl;//Precio T
			Grabacion.close();

    gotoxy(42, 45);cout << "Imprimiendo Boleta..."; getch();
	color(hConsole, 15);
}

MenuDulceria::MenuDulceria(){
    altoConsola = 60;
    anchoConsola = 150;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuDulceria::imprimir(){
    system("COLOR 70");
    int ejeYmarco = 7;
    altoMarco = 30;
    anchoMarco = 55;
    system("cls");
    cine::gotoY(1);
    cine::printRawCenter(cine::logo_fisicode);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("COMBO 1", (anchoConsola - 45)/2, 10, opcion==1);
        imprimirOpcion("COMBO 2", (anchoConsola + 8 )/2, 10, opcion==2);
		imprimirOpcion("COMBO 3", (anchoConsola - 45)/2, 20, opcion==3);
		imprimirOpcion("COMBO 4", (anchoConsola + 8 )/2, 20, opcion==4);
		imprimirOpcion("COMBO 5", (anchoConsola - 45)/2, 30, opcion==5);
		imprimirOpcion("COMBO 6", (anchoConsola + 8 )/2, 30, opcion==6);
        switch (cine::getch()) {
    
			case key::w:
            case Up:
                if (opcion > 1) opcion-=2;
                break;
			case key::d:
			case Right:
                if (opcion < 6) opcion++;
                break;

            case::key::s:
            case Down:
                if (opcion < 6) opcion+=2;
                break;
    		case key::a:
            case Left:
                if (opcion > 1) opcion--;
                break;
              

            case Enter:
                continuar = false;
                break;
        }
    }
}