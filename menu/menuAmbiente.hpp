#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include"menuCartelera.h"
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
	gotoxy(20, 1);   cout << " __________________________________________________________________________________________ " ; 	
	gotoxy(20, 2);   cout << "| +--------------------------------------------------------------------------------------+ |" ; 
	gotoxy(20, 3);   cout << "| ¦                                                                                      ¦ |" ; 
	gotoxy(20, 4);   cout << "|_¦______________________________________________________________________________________¦_|" ; 
	gotoxy(20, 5);   cout << "|   ______   ___   ___   ______    _______   ______   _____     __   _________   ______    |" ; 
	gotoxy(20, 6);   cout << "|  |  __  | |   |_|   | |  __  |  |__   __| |  ____| |  _  |   |  | |___   ___| |  ____|   |" ; 
	gotoxy(20, 7);   cout << "|  | |__| | | ||   |  | | |__|  |    | |    |  |___  |  ||  |  |  |     | |     |  |___    |" ; 
	gotoxy(20, 8);   cout << "|  |  __  | | | |_| | | |  __  |     | |    |  ____| |  | |  | |  |     | |     |  ____|   |" ; 
	gotoxy(20, 9);   cout << "|  | |  | | | |     | | | |__|  |  __| |__  |  |___  |  |  |  ||  |     | |     |  |___    |" ; 
	gotoxy(20, 10);  cout << "|  |_|  |_| |_|     |_| |______|  |_______| |______| |__|   |_____|     |_|     |______|   |" ; 
	gotoxy(20, 11);  cout << "|__________________________________________________________________________________________|" ; 
	gotoxy(20, 12);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 13);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 14);  cout << "| ¦         +============#1===========+            +============#2===========+          ¦  |" ; 
	gotoxy(20, 15);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 16);  cout << "| ¦         |          NORMAL         |            |          10:00am        |          ¦  |" ; 
	gotoxy(20, 17);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 18);  cout << "| ¦         +=========================+            +=========================+          ¦  |" ; 
	gotoxy(20, 19);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 20);  cout << "| ¦         +============#2===========+            +============#4===========+          ¦  |" ; 
	gotoxy(20, 21);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 22);  cout << "| ¦         |      3D ENVOLVENTE      |            |           1:00pm        |          ¦  |" ; 
	gotoxy(20, 23);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 24);  cout << "| ¦         +=========================+            +=========================+          ¦  |" ; 
	gotoxy(20, 25);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 26);  cout << "| ¦         +============#5===========+            +============#6===========+          ¦  |" ; 
	gotoxy(20, 27);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 28);  cout << "| ¦         |            VIP          |            |          7:00pm         |          ¦  |" ; 
	gotoxy(20, 29);  cout << "| ¦         |                         |            |                         |          ¦  |" ; 
	gotoxy(20, 30);  cout << "| ¦         +=========================+            +=========================+          ¦  |" ; 
	gotoxy(20, 31);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 32);  cout << "| ¦                                                                                     ¦  |" ; 
	gotoxy(20, 33);  cout << "| +-------------------------------------------------------------------------------------+  |" ; 
	gotoxy(20, 34);  cout << "|__________________________________________________________________________________________|" ; 

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
	Sleep(3000);
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
	Sleep(3000);
	return fopchorario(opch);
	
}
