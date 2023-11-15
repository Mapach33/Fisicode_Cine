#pragma once
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"
#include "menuAmbiente.hpp"


class MenuDulceria : public Menu{
    public:
        MenuDulceria();
        void imprimir();
};

void elegir_combo() {
    
	short elegir, i = 0;
	
    string combo[] = {"Cancha Grande + 2 Gaseosas Grandes","2 Canchas Medianas + 3 Gaseosas Medianas","Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas",
         "2 Canchas Grandes + 5 Gaseosas Medianas","2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog", "Canchas Medianas + 4 Gaseosas Grandes + 4 Hot Dog"};
	string precio[] =  {"26","28","32","33","35","45"};

	MenuDulceria menuDulceria; 
	elegir = menuDulceria.getOpcion();
	system("cls");
	gotoxy(25, 44+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	gotoxy(55, 45+i);color(hConsole, 79); cout << combo[elegir-1]<< endl;
	gotoxy(25, 46+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	gotoxy(25, 47+i);color(hConsole, 79); cout << "Precio: " << precio[elegir-1] << endl; 
	gotoxy(25, 48+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	cout << endl;	
	
	ofstream Grabacion("boleta.txt", ios::app);
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

    cout << "\n\nAhora elija su sala de preferencia..."; getch();
	color(hConsole, 15);
}

MenuDulceria::MenuDulceria(){
    altoConsola = 60;
    anchoConsola = 130;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuDulceria::imprimir(){
    system("COLOR 70");
    int ejeYmarco = 7;
    altoMarco = 50;
    anchoMarco = 100;
    system("cls");
    cine::gotoY(1);
    cine::printRawCenter(cine::logo_fisicode);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("COMBO 1", (anchoConsola - 53)/2, 14, opcion==1);
        imprimirOpcion("COMBO 2", (anchoConsola + 13)/2 , 14, opcion==2);
		imprimirOpcion("COMBO 3", (anchoConsola - 53)/2, 24, opcion==3);
		imprimirOpcion("COMBO 4", (anchoConsola + 13)/2, 24, opcion==4);
		imprimirOpcion("COMBO 5", (anchoConsola - 53)/2, 34, opcion==5);
		imprimirOpcion("COMBO 6", (anchoConsola + 13)/2, 34, opcion==6);
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