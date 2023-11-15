#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include <fstream>
#include <sstream>
#include"menuCartelera.h"
using namespace std;

string fopcsala(short opcs, short &price) {
	string tipo;
	switch (opcs) {
		case 1:
			tipo = "Normal";price = 10;
			break;
		case 2:
			tipo = "3D Envolvente";price = 20;
			break;
		case 3:
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
		case 1:
			tipo = "10:00am";
			break;
		case 2:
			tipo = "1:00pm";
			break;
		case 3:
			tipo = "7:00pm";
			break;
		default: {
			tipo = "Desconocido";
			break;
		}
	}
	return tipo;
}
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
	gotoxy(20, 16);  cout << "|           |          NORMAL         |            |          10:00am        |             |" ; 
	gotoxy(20, 17);  cout << "|           |           $10           |            |                         |             |" ; 
	gotoxy(20, 18);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 19);  cout << "|                                                                                          |" ; 
	gotoxy(20, 20);  cout << "|           +============#2===========+            +============#2===========+             |" ; 
	gotoxy(20, 21);  cout << "|           |                         |            |                         |             |" ; 
	gotoxy(20, 22);  cout << "|           |      3D ENVOLVENTE      |            |           1:00pm        |             |" ; 
	gotoxy(20, 23);  cout << "|           |           $20           |            |                         |             |" ; 
	gotoxy(20, 24);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 25);  cout << "|                                                                                          |" ; 
	gotoxy(20, 26);  cout << "|           +============#3===========+            +============#3===========+             |" ; 
	gotoxy(20, 27);  cout << "|           |                         |            |                         |             |" ; 
	gotoxy(20, 28);  cout << "|           |            VIP          |            |          7:00pm         |             |" ; 
	gotoxy(20, 29);  cout << "|           |            $40          |            |                         |             |" ; 
	gotoxy(20, 30);  cout << "|           +=========================+            +=========================+             |" ; 
	gotoxy(20, 31);  cout << "|                                                                                          |" ; 
	gotoxy(20, 32);  cout << "|                                                                                          |" ; 
	gotoxy(20, 33);  cout << "| +-------------------------------------------------------------------------------------+  |" ; 
	gotoxy(20, 34);  cout << "|__________________________________________________________________________________________|" ; 

}
string ele_sala(){
	string x_opcs;
<<<<<<< HEAD
	short opcs;
	
=======
	short opcs, price;
>>>>>>> 488032103672d18a4a73660041c861502b5d9ac5
	do{
		gotoxy(25, 36);cout << "Use '1' = Normal / '2' = 3D Envolvente / '3' = VIP " << endl;
		gotoxy(25, 37);cout << "                                                      " << endl;
		gotoxy(25, 38);cout << "Elija Su Tipo de Sala :  ";
		getline(cin, x_opcs);
		istringstream(x_opcs)>>opcs;

		if ( opcs < 1 || opcs > 3) { 
			gotoxy(25, 37);cout << "Ingrese una opcion valida (1-3)...              " << endl;
			gotoxy(25, 38);cout << "                                                          ";
			gotoxy(25, 40);getch();
		}
	}while(opcs < 1 || opcs > 3);	
	gotoxy(25, 38);cout << "                                                                " << endl;
	gotoxy(25, 39);cout << "Opcion de sala elegida es: " << fopcsala(opcs, price) <<"-"<<price<<" la und."<<endl;
	ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				system("CLS");
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<price<<endl;
			Grabacion.close();
			gotoxy(25, 40);getch();
	return fopcsala(opcs, price);
}

string ele_horario(){
	short opch; 
	string x_opch;
<<<<<<< HEAD
	
		do {
			system("CLS");
			menu_ambiente();
			cout << " \n Elija El Horario : ";
			cout << "\nUse: '1' = 10:00am / '2' = 1:00pm / '3' = 7:00pm \n" << endl;
			getline(cin, x_opch);
			
			istringstream(x_opch)>>opch;
						if (opch<1 || opch>3) { 
				cout << "\nIngrese una opcion valida (1-3)... " << endl;
				// flag = true;
				system("pause"); 	
=======
		do {
			gotoxy(25, 39);cout << "                                                                       ";
			gotoxy(25, 36);cout << "Use: '1' = 10:00am / '2' = 1:00pm / '3' = 7:00pm " << endl;
			gotoxy(25, 37);cout << "                                                              ";
			gotoxy(25, 38);cout << "Elija El Horario : "; getline(cin, x_opch);
			
			
			istringstream(x_opch)>>opch;
			
			if (opch<1 || opch>3) { 
				gotoxy(25, 37);cout << "Ingrese una opcion valida (1-3)... " << endl;
				gotoxy(25, 38);cout << "                                                          ";
				gotoxy(25, 39);cout << "                                                          ";
				gotoxy(25, 40);getch();	
>>>>>>> 488032103672d18a4a73660041c861502b5d9ac5
			}
		}while(opch<1 || opch>3); 
	gotoxy(25, 39);cout << "Opcion de horario es: " << fopchorario(opch) << endl;
	gotoxy(25, 40);getch();
	return fopchorario(opch);
	
}
