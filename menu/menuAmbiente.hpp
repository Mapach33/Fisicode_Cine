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
			SetConsoleTextAttribute(hConsole, 9);
					gotoxy(42, 39);cout << "---------------------------------------------------------------"<<endl;
					gotoxy(42, 40);cout << "                     Seleccion de Sala"<< endl;
					gotoxy(42, 41);cout << "---------------------------------------------------------------"<<endl;
					gotoxy(42, 42);cout << "          Tipo de Sala     : " << fopcsala(opcs, price) << endl;
					gotoxy(42, 43);cout << "          Precio Unitario  : " << price << endl;
					gotoxy(42, 44);cout << "----------------------------------------------------------------"<<endl;
					gotoxy(42, 45);cout << endl;	
					gotoxy(42, 46);	cout << "Ahora elija su horario..."; getch();
			return fopcsala(opcs, price);
}

string ele_horario(){
	short opch; 
	string x_opch;
	
	MenuHorario MenuHorario; 
	opch = MenuHorario.getOpcion();
	ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				system("CLS");
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<fopchorario(opch)<<endl;
			Grabacion.close();
			SetConsoleTextAttribute(hConsole, 9);
				gotoxy(42, 39);	cout << "---------------------------------------------------------------"<<endl;
				gotoxy(42, 40);	cout << "                    Seleccion de Horario"<< endl;
				gotoxy(42, 41);	cout << "---------------------------------------------------------------"<<endl;
				gotoxy(42, 42);	cout << "       Horario Elegida     : " << fopchorario(opch) << endl;
				gotoxy(42, 43);	cout << "----------------------------------------------------------------"<<endl;
				gotoxy(42, 44);	cout << endl;	
				gotoxy(42, 45);	cout << "Ahora elija su asiento..."; getch();
				SetConsoleTextAttribute(hConsole, 15);
			
	return fopchorario(opch);
}
/*Constructor*/
	MenuSala::MenuSala(){
    altoConsola = 60;
    anchoConsola = 150;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 144;
    colorMarco = 9;
    opcion = 1;
    imprimir();
}

void MenuSala::imprimir(){
			system("cls");
			int ejeYmarco = 7;
			string logo_menusala = 
    R"( _____       _       
/  ___|     | |      
\ `--.  __ _| | __ _ 
 `--. \/ _` | |/ _` |
/\__/ / (_| | | (_| |
\____/ \__,_|_|\__,_| )";
			altoMarco = 30;
			anchoMarco = 55;
			system("cls");
			cine::printRawCenter(logo_menusala);
			imprimirMarco(ejeYmarco);
			bool continuar=true;
    
    while(continuar){
        imprimirOpcion("Normal S/.10", (anchoConsola - 23)/2, 14, opcion==1);
        imprimirOpcion("2D Prime S/.15", (anchoConsola - 23)/2 , 18, opcion==2);
		imprimirOpcion("3D Envolvente S/.20", (anchoConsola - 23)/2 , 22, opcion==3);
		imprimirOpcion("Extreme S/.40", (anchoConsola - 23)/2, 26, opcion==4);
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
    colorTexto = 144;
    colorMarco = 9;
    opcion = 1;
    imprimir();
}

void MenuHorario::imprimir(){
    string logo_menuhorario = 
    R"( _   _                      _       
| | | |                    (_)      
| |_| | ___  _ __ __ _ _ __ _  ___  
|  _  |/ _ \| '__/ _` | '__| |/ _ \ 
| | | | (_) | | | (_| | |  | | (_) |
\_| |_/\___/|_|  \__,_|_|  |_|\___/ )";
	int ejeYmarco = 7;
    altoMarco = 30;
    anchoMarco = 55;
    system("cls");
    
    cine::printRawCenter(logo_menuhorario);
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