#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include <fstream>
#include <sstream>
#include"menuCartelera.h"
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"
using namespace std;

class MenuAmbiente : public Menu{
    public:
        MenuAmbiente();
        void imprimir();
};

string fopcsala(short opcs, short &price) {
	string tipo;
	switch (opcs) {
		case 1:
			tipo = "Normal";price = 10;
			break;
		case 3:
			tipo = "3D Envolvente";price = 20;
			break;
		case 6:
			tipo = "VIP";price = 40;
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
		case 2:
			tipo = "10:00";
			break;
		case 4:
			tipo = "13:00";
			break;
		case 6:
			tipo = "19:00";
			break;
		default: {
			tipo = "Desconocido";
			break;
		}
	}
	return tipo;
}
/*
void menu_ambiente() {
	system("cls");
	system("color 47");
	gotoxy(20, 1);   cout << " __________________________________________________________________________________________ " ; 	
	gotoxy(20, 2);   cout << "| +--------------------------------------------------------------------------------------+ |" ; 
	gotoxy(20, 3);   cout << "|                                                                                          |" ; 
	gotoxy(20, 4);   cout << "|__________________________________________________________________________________________|" ; 
	gotoxy(20, 5);   cout << "|   ______   ___   ___   ______    _______   ______   _____     __   _________   ______    |" ; 
	gotoxy(20, 6);   cout << "|  |  __  | |   |_|   | |  __  |  |__   __| |  ____| |  _  |   |  | |___   ___| |  ____|   |" ; 
	gotoxy(20, 7);   cout << "|  | |__| | | ||   |  | | |__|  |    | |    |  |___  |  ||  |  |  |     | |     |  |___    |" ; 
	gotoxy(20, 8);   cout << "|  |  __  | | | |_| | | |  __  |     | |    |  ____| |  | |  | |  |     | |     |  ____|   |" ; 
	gotoxy(20, 9);   cout << "|  | |  | | | |     | | | |__|  |  __| |__  |  |___  |  |  |  ||  |     | |     |  |___    |" ; 
	gotoxy(20, 10);  cout << "|  |_|  |_| |_|     |_| |______|  |_______| |______| |__|   |_____|     |_|     |______|   |" ; 
	gotoxy(20, 11);  cout << "|__________________________________________________________________________________________|" ; 
	gotoxy(20, 12);  cout << "|                                                                                          |" ; 
	gotoxy(20, 13);  cout << "|                  TIPO DE SALA                               HORARIO                      |" ; 
	gotoxy(20, 14);  cout << "|           +============#1===========+            +============#1===========+             |" ; 
	gotoxy(20, 15);  cout << "|           |                         |            |                         |             |" ; 
	gotoxy(20, 16);  cout << "|           |          NORMAL         |            |          10:00          |             |" ; 
	gotoxy(20, 17);  cout << "|           |           $10           |            |                         |             |" ; 
	gotoxy(20, 18);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 19);  cout << "|                                                                                          |" ; 
	gotoxy(20, 20);  cout << "|           +============#2===========+            +============#2===========+             |" ; 
	gotoxy(20, 21);  cout << "|           |                         |            |                         |             |" ; 
	gotoxy(20, 22);  cout << "|           |      3D ENVOLVENTE      |            |          13:00          |             |" ; 
	gotoxy(20, 23);  cout << "|           |           $20           |            |                         |             |" ; 
	gotoxy(20, 24);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 25);  cout << "|                                                                                          |" ; 
	gotoxy(20, 26);  cout << "|           +============#3===========+            +============#3===========+             |" ; 
	gotoxy(20, 27);  cout << "|           |                         |            |                         |             |" ; 
	gotoxy(20, 28);  cout << "|           |           VIP           |            |           19:00         |             |" ; 
	gotoxy(20, 29);  cout << "|           |           $40           |            |                         |             |" ; 
	gotoxy(20, 30);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 31);  cout << "|                                                                                          |" ; 
	gotoxy(20, 32);  cout << "|                                                                                          |" ; 
	gotoxy(20, 33);  cout << "| +-------------------------------------------------------------------------------------+  |" ; 
	gotoxy(20, 34);  cout << "|__________________________________________________________________________________________|" ; 

}*/
string ele_sala(){
	string x_opcs;
	short opcs, price;
	
	MenuAmbiente menuAmbiente; 
	opcs = menuAmbiente.getOpcion();
	system("cls");
	gotoxy(25, 38);cout << "                                                                " << endl;
	gotoxy(25, 39);cout << "Opcion de sala elegida es: " << fopcsala(opcs, price) <<"-"<<price<<" la und."<<endl;
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
			gotoxy(25, 40);getch();
			return fopcsala(opcs, price);
}

string ele_horario(){
	short opch; 
	string x_opch;
	
	MenuAmbiente menuAmbiente; 
	opch = menuAmbiente.getOpcion();
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
/*COnstru*/
	MenuAmbiente::MenuAmbiente(){
    altoConsola = 60;
    anchoConsola = 130;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuAmbiente::imprimir(){
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
		/*imprimirOpcion("que queiro escribir", (x, y, desgino la opción);*/
        imprimirOpcion("NORMAL", (anchoConsola - 53)/2, 14, opcion==1);
        imprimirOpcion("10:00", (anchoConsola + 13)/2 , 14, opcion==2);
		imprimirOpcion("3D ENVOLVENTE", (anchoConsola - 53)/2, 24, opcion==3);
		imprimirOpcion("13:00", (anchoConsola + 13)/2, 24, opcion==4);
		imprimirOpcion("VIP", (anchoConsola - 53)/2, 34, opcion==5);
		imprimirOpcion("19:00", (anchoConsola + 13)/2, 34, opcion==6);
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