#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include"menu_cartelera.h"
using namespace std;


string fopcsala(char opcs) {
	string tipo;
	switch (opcs) {
		case '1':
			tipo = "Normal";
			break;
		case '2':
			tipo = "3D Envolvente";
			break;
		case '3':
			tipo = "VIP";
			break;
		default: {
			tipo = "Desconocido";
			break;
		}
	}
	return tipo;
}
string fopchorario(char opch) {
	string tipo;
	switch (opch) {
		case '1':
			tipo = "10:00am";
			break;
		case '2':
			tipo = "1:00pm";
			break;
		case '3':
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

		system("cls");
		system("color 47");
		gotoxy(32, 3); cout << "                    BIENVENIDO A FISICODERS";
		gotoxy(32, 5); cout << "+ ----------------------------------------------------------- +";
		gotoxy(32, 7); cout << "                     SELECCIONE SU AMBIENTE ";
		gotoxy(32, 11); cout << "+ ---------------------------- +---------------------------- +";
		gotoxy(32, 12); cout << "|         TIPO DE SALA         |           HORARIO           |";
		gotoxy(32, 13); cout << "+ ---------------------------- +---------------------------- +";
		gotoxy(32, 14); cout << "| ---------------------------- | ----------------------------|";
		gotoxy(32, 15); cout << "| 1)  NORMAL                   |1)  10:00am                  |";
		gotoxy(32, 16); cout << "| ---------------------------- | ----------------------------|";
		gotoxy(32, 17); cout << "| 2)  3D ENVOLVENTE            |2)  1:00pm                   |";
		gotoxy(32, 18); cout << "| ---------------------------- | ----------------------------|";
		gotoxy(32, 19); cout << "| 3)  VIP                      |3)  7:00pm                   |";
		gotoxy(32, 20); cout << "| ---------------------------- | ----------------------------|";
		gotoxy(32, 21); cout << "+ ---------------------------- +---------------------------- +";	
}
string ele_sala(){
	
	char opcs = '0'; 
	do{
		system("CLS");
		menu_ambiente();
		cout << " \n Elija Su Tipo de Sala : ";
		cout << "\nUse '1' = Normal / '2' = 3D Envolvente / '3' = VIP \n" << endl;
		cin >> opcs; 
		if (opcs != '1' && opcs != '2' && opcs != '3') { 
			cout << "\nError al seleccionar una opcion \n";
			cout << "\nRecuerde que solo se aceptan los valores '1', '2' y '3' \n" << endl;
			system("pause");
		}
	}while(opcs != '1' && opcs != '2' && opcs != '3');	
	cout << "Opcion de sala elegida es: " << fopcsala(opcs) << endl;
	system("PAUSE");
	return fopcsala(opcs);
}
string ele_horario(){
	
	char opch = '0'; 
		do {
			system("CLS");
			menu_ambiente();
			cout << " \n Elija El Horario : ";
			cout << "\nUse: '1' = 10:00am / '2' = 1:00pm / '3' = 7:00pm \n" << endl;
			cin >> opch;
			if (opch != '1' && opch != '2' && opch != '3') { 
				cout << "\nError al seleccionar una opcion \n";
				cout << "\nRecuerde que solo se aceptan los valores '1', '2' y '3' \n" << endl;
				system("pause"); 	
			}
		}while(opch != '1' && opch != '2' && opch != '3'); 
	cout << "Opcion de horario es: " << fopchorario(opch) << endl;
	return fopchorario(opch);
}
