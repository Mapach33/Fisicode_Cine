#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#define color SetConsoleTextAttribute//definde el setcontrol para llamarlo por "color"
using namespace std;


char elegir;
string peliculas[] = {"Saw X", "Five Nights At Freddy's", "The Eras Tour","Sonidos de libertad","El Exorcista: Creyentes", "Sin Aire"};
string duracion[] = {"2hrs 0min","1hrs 50min","2hrs 45min","2hrs 10min","2hrs 0min","1hrs 30min"};
string director[] = {"Kevin Greutert","Emma Tammi","Sam Wrench","Alejandro Gómez Monteverde","David Gordon Green","Maximilian Erlenwein"};
string sinopsis[] = {"Un asesino busca venganza",
                    "Un guardia teme por su vida",
                    "Sumergete en la experiencia cinematografica de este concierto",
					"Un agente se embarca en la mision de salvar a una niña del trafico de menores", 
                    "La película de terror más aterradora de la historia volvio a las pantallas",
					"May yace en lo profundo bajo el mar, atrapada por escombros e incapaz de moverse"};

int i=0;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}



void mostrar_cartelera(){
	cine::Set_Console_Sizes(130,60,1);   
	
		
	system("cls");
	system("color 47");
	setlocale(LC_ALL, "Spanish");
	

	
	gotoxy(20, 3);  color(hConsole, 6);  cout << " __________________________________________________________________________________" ; color(hConsole, 0); cout<<"¦";	
	gotoxy(20, 4);  color(hConsole, 228);cout << "| +-------------------------------------------------------------------------------+|" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 5);  color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 6);  color(hConsole, 228);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 7);  color(hConsole, 116);cout << "|    _____   ______   ______   _______  _____    _      _____   ______    ______   |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 8);  color(hConsole, 116);cout << "|   |   __| |  __  | |  __  | |__   __||  ___|  | |    |  ___| |  __  |  |  __  |  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 9);  color(hConsole, 116);cout << "|   |  |    | |__| | | |__| |    | |   | |__    | |    | |__   | |__| |  | |__| |  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 10); color(hConsole, 116);cout << "|   |  |    |  __  | |  _   |    | |   |  __|   | |    |  __|  |  _   |  |  __  |  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 11); color(hConsole, 116);cout << "|   |  |__  | |  | | | | | |     | |   | |___   | |__  | |___  | | | |   | |  | |  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 12); color(hConsole, 116);cout << "|   |_____| |_|  |_| |_|  |_|    |_|   |_____|  |____| |_____| |_|  |_|  |_|  |_|  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 13); color(hConsole, 116);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 14); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 15); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 16); color(hConsole, 228);cout << "|       +========= ^-^ #1 ========+            +========= ^-^ #2 ========+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 17); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 18); color(hConsole, 228);cout << "|       |         Saw X           |            | Five Nights At Freddy's |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 19); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 20); color(hConsole, 228);cout << "|       |      B18 - Thriller     |            |       B14 - Terror      |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 21); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 22); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 23); color(hConsole, 228);cout << "|       +========= ^-^ #3 --------+            +========= ^-^ #4 ========+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 24); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 25); color(hConsole, 228);cout << "|       |      The Eras Tour      |            |  Sonidos de libertad    |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 26); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 27); color(hConsole, 228);cout << "|       |       A - Musical       |            |       B16 - Drama       |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 28); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 29); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 30); color(hConsole, 228);cout << "|       +========= ^-^ #5 ========+            +========= ^-^ #6 ========+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 31); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 32); color(hConsole, 228);cout << "|       | El Exorcista: Creyentes |            |        Sin Aire         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 33); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 34); color(hConsole, 228);cout << "|       |       B18 - Terror      |            |      B14 - Thriller     |         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 35); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 36); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 37); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 38); color(hConsole, 228);cout << "|+--------------------------------------------------------------------------------+|" ; color(hConsole, 0); cout<<"¦";
	gotoxy(20, 39); color(hConsole, 228);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
	
	
	
}

void elegir_pelicula() {
    short p;
	char elegir;
	string imprimir_pelicula, imprimir_duracion, imprimir_director, imprimir_sinopsis;
    do{
        gotoxy(25, 42+i);color(hConsole, 79); cout << "Por favor eliga una pelicula : "; cin >> elegir;
		cout<<endl;
		i++;
        if(elegir != '1' && elegir != '2' && elegir != '3' && elegir != '4' && elegir != '5' && elegir != '6'){
        gotoxy(25, 42);color(hConsole, 79); cout << "Ingrese una opcion valida..." << endl;
        }       
    } while (elegir != '1' && elegir != '2' && elegir != '3' && elegir != '4' && elegir != '5' && elegir != '6');

    
	switch (elegir) {
		case '1': p = 1; break;
		case '2': p = 2; break;
		case '3': p = 3; break;
		case '4': p = 4; break;
		case '5': p = 5; break;
		case '6': p = 6; break;
	}

	
	gotoxy(25, 44+i);color(hConsole, 79);cout << "-----------------------------------------------------------------------------";
	gotoxy(55, 45+i);color(hConsole, 79);cout << peliculas[p-1]<< endl;
	gotoxy(25, 46+i);color(hConsole, 79);cout << "-----------------------------------------------------------------------------";
	gotoxy(25, 47+i);color(hConsole, 79);cout << "Duracion: " << duracion[p-1] << endl;
	gotoxy(25, 48+i);color(hConsole, 79);cout << "Director: " << director[p-1] << endl;
	gotoxy(25, 49+i);color(hConsole, 79);cout << "Sinopsis: " << sinopsis[p-1] << endl;   
	gotoxy(25, 50+i);color(hConsole, 79);cout << "-----------------------------------------------------------------------------";
	cout << endl;	
	
	ofstream Grabacion("boleta.txt", ios::out);
			if(Grabacion.fail()){
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<peliculas[p-1]<<endl;
			Grabacion<<duracion[p-1]<<endl;
			Grabacion<<director[p-1]<<endl;
			Grabacion<<sinopsis[p-1]<<endl;
			Grabacion.close();

    cout << "\n\nAhora elija su sala de preferencia..."; getch();
	
	
}

