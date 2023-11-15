#pragma once
#include"menuCartelera.h"
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"

class MenuSala : public Menu{
    public:
        MenuSala();
        void imprimir();
};
class MenuHorario : public Menu{
    public:
        MenuHorario();
        void imprimir();
};

string fopcsala(short opcs, short &price) {
	string tipo;
	switch (opcs) {
		case 1:
			tipo = "Normal";price = 10;
			break;
		case 2:
			tipo = "2D Prime";price = 15;
			break;
		case 3:
			tipo = "3D Envolvente";price = 20;
			break;
		case 4:
			tipo = "Extreme";price = 40;
			break;
		default: {
			tipo = "Desconocido";price = 0;
			break;
		}
	}
	return tipo;
}
string fopchorario(short opch) {
	string tipo;
	switch (opch) {
		case 1:
			tipo = "12:00";
			break;
		case 2:
			tipo = "15:00";
			break;
		case 3:
			tipo = "18:00";
			break;
		case 4:
			tipo = "21:00";
			break;
		default: {
			tipo = "Desconocido";
			break;
		}
	}
	return tipo;
}

string ele_sala(){
	string x_opcs;
	short opcs, price;
	
	MenuSala MenuSala; 
	opcs = MenuSala.getOpcion();
	ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				system("CLS");
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<fopcsala(opcs, price)<<endl;
			Grabacion<<price<<endl;
			Grabacion.close();
					SetConsoleTextAttribute(hConsole, 112);
					cout << "\n\n\n\n\n\n\n\n\n\n-----------------------------------------------------------------------------"<<endl;
					cout << "                        Seleccion de Sala"<< endl;
					cout << "-----------------------------------------------------------------------------"<<endl;
					cout << "Tipo de Sala     : " << fopcsala(opcs, price) << endl;
					cout << "Precio Unitario  : " << price << endl;
					cout << "-----------------------------------------------------------------------------"<<endl;
					cout << endl;	
					cout << "Ahora elija su horario..."; getch();
			return fopcsala(opcs, price);
}

string ele_horario(){
	short opch; 
	string x_opch;
	
	MenuHorario MenuHorario; 
	opch = MenuHorario.getOpcion();
	system("cls");

	gotoxy(25, 39);cout << "Opcion de horario es: " << fopchorario(opch) << endl;
	gotoxy(25, 40);getch();
	
	ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				system("CLS");
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<fopchorario(opch)<<endl;
			Grabacion.close();
			gotoxy(25, 40);getch();
	return fopchorario(opch);
}
/*Constructor*/
	MenuSala::MenuSala(){
    altoConsola = 60;
    anchoConsola = 150;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuSala::imprimir(){
			system("COLOR 70 && cls");
			int ejeYmarco = 7;
			altoMarco = 30;
			anchoMarco = 55;
			system("cls");
			altoMarco = 50;
			anchoMarco = 100;
			cine::gotoY(1);
			cine::printRawCenter(cine::logo_fisicode);
			imprimirMarco(ejeYmarco);
			bool continuar=true;
    
    while(continuar){
        imprimirOpcion("Normal", (anchoConsola - 23)/2, 14, opcion==1);
        imprimirOpcion("2D Prime ", (anchoConsola - 23)/2 , 18, opcion==2);
		imprimirOpcion("3D Envolvente", (anchoConsola - 23)/2 , 22, opcion==3);
		imprimirOpcion("Extreme", (anchoConsola - 23)/2, 26, opcion==4);
        switch (cine::getch()) {
    
            case key::w:
            case Up:
                if (opcion > 1) opcion--;
                break;
        
            case key::s:
            case Down:
                if (opcion < 4) opcion++;
                break;

            case Enter:
                continuar = false;
                break;
        }
    }
}

	MenuHorario::MenuHorario(){
    altoConsola = 60;
    anchoConsola = 150;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuHorario::imprimir(){
    system("COLOR 70");
    int ejeYmarco = 7;
    altoMarco = 30;
    anchoMarco = 55;
    system("cls");
    cine::gotoY(1);
    cine::printRawCenter(cine::logo_fisicode);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    ////// 
    while(continuar){
        imprimirOpcion("12:00", (anchoConsola - 23)/2, 14, opcion==1);
        imprimirOpcion("15:00", (anchoConsola - 23)/2 , 18, opcion==2);
		imprimirOpcion("18:00", (anchoConsola - 23)/2 , 22, opcion==3);
		imprimirOpcion("21:00", (anchoConsola - 23)/2, 26, opcion==4);
        switch (cine::getch()) {
    
            case key::w:
            case Up:
                if (opcion > 1) opcion--;
                break;
        
            case key::s:
            case Down:
                if (opcion < 4) opcion++;
                break;

            case Enter:
                continuar = false;
                break;
        }
    }
}