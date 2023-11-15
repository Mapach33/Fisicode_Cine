#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"
#define color SetConsoleTextAttribute//define el setcontrol para llamarlo por "color"
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class MenuCartelera : public Menu{
    public:
        MenuCartelera();
        void imprimir();
};
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

// void mostrar_cartelera(){
	
// 	cine::Set_Console_Sizes(130,60,1);   
			
// 	system("cls");
// 	system("color 47");
	
	
// 	gotoxy(20, 3);  color(hConsole, 6);  cout << " __________________________________________________________________________________" ; color(hConsole, 0); cout<<"¦";	
// 	gotoxy(20, 4);  color(hConsole, 228);cout << "| +-------------------------------------------------------------------------------+|" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 5);  color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 6);  color(hConsole, 228);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 7);  color(hConsole, 116);cout << "|    _____   ______   ______   _______  _____    _      _____   ______    ______   |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 8);  color(hConsole, 116);cout << "|   |   __| |  __  | |  __  | |__   __||  ___|  | |    |  ___| |  __  |  |  __  |  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 9);  color(hConsole, 116);cout << "|   |  |    | |__| | | |__| |    | |   | |__    | |    | |__   | |__| |  | |__| |  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 10); color(hConsole, 116);cout << "|   |  |    |  __  | |  _   |    | |   |  __|   | |    |  __|  |  _   |  |  __  |  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 11); color(hConsole, 116);cout << "|   |  |__  | |  | | | | | |     | |   | |___   | |__  | |___  | | | |   | |  | |  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 12); color(hConsole, 116);cout << "|   |_____| |_|  |_| |_|  |_|    |_|   |_____|  |____| |_____| |_|  |_|  |_|  |_|  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 13); color(hConsole, 116);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 14); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 15); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 16); color(hConsole, 228);cout << "|       +========= ^-^ #1 ========+            +========= ^-^ #2 ========+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 17); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 18); color(hConsole, 228);cout << "|       |         Saw X           |            | Five Nights At Freddy's |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 19); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 20); color(hConsole, 228);cout << "|       |      B18 - Thriller     |            |       B14 - Terror      |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 21); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 22); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 23); color(hConsole, 228);cout << "|       +========= ^-^ #3 --------+            +========= ^-^ #4 ========+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 24); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 25); color(hConsole, 228);cout << "|       |      The Eras Tour      |            |  Sonidos de libertad    |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 26); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 27); color(hConsole, 228);cout << "|       |       A - Musical       |            |       B16 - Drama       |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 28); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 29); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 30); color(hConsole, 228);cout << "|       +========= ^-^ #5 ========+            +========= ^-^ #6 ========+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 31); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 32); color(hConsole, 228);cout << "|       | El Exorcista: Creyentes |            |        Sin Aire         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 33); color(hConsole, 228);cout << "|       |                         |            |                         |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 34); color(hConsole, 228);cout << "|       |       B18 - Terror      |            |      B14 - Thriller     |         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 35); color(hConsole, 228);cout << "|       +=========================+            +=========================+         |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 36); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 37); color(hConsole, 228);cout << "|                                                                                  |" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 38); color(hConsole, 228);cout << "|+--------------------------------------------------------------------------------+|" ; color(hConsole, 0); cout<<"¦";
// 	gotoxy(20, 39); color(hConsole, 228);cout << "|__________________________________________________________________________________|" ; color(hConsole, 0); cout<<"¦";
		
// }

void elegir_pelicula() {
    
	short elegir, i = 0;
	string x_elegir;
    string peliculas[] = {"Saw X", "Five Nights At Freddy's", "The Eras Tour", "Sonidos de libertad", "El Exorcista: Creyentes", "Sin Aire"};
	string duracion[] =  {"2hrs 0min", "1hrs 50min", "2hrs 45min", "2hrs 10min", "2hrs 0min", "1hrs 30min"};
	string director[] =  {"Kevin Greutert", "Emma Tammi", "Sam Wrench", "Alejandro Gómez Monteverde", "David Gordon Green", "Maximilian Erlenwein"};
	string sinopsis[] =  {"Un asesino busca venganza", "Un guardia teme por su vida", "Sumergete en la experiencia cinematografica de este concierto",
						 "Un agente se embarca en la mision de salvar a una niña del trafico de menores", "La película de terror más aterradora de la historia volvio a las pantallas",
						 "May yace en lo profundo bajo el mar, atrapada por escombros e incapaz de moverse"};

	MenuCartelera menuCartelera; 
	elegir = menuCartelera.getOpcion();
	system("cls");
	gotoxy(25, 44+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	gotoxy(55, 45+i);color(hConsole, 79); cout << peliculas[elegir-1]<< endl;
	gotoxy(25, 46+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	gotoxy(25, 47+i);color(hConsole, 79); cout << "Duracion: " << duracion[elegir-1] << endl;
	gotoxy(25, 48+i);color(hConsole, 79); cout << "Director: " << director[elegir-1] << endl;
	gotoxy(25, 49+i);color(hConsole, 79); cout << "Sinopsis: " << sinopsis[elegir-1] << endl;   
	gotoxy(25, 50+i);color(hConsole, 79); cout << "-----------------------------------------------------------------------------";
	cout << endl;	
	
	ofstream Grabacion("boleta.txt", ios::out);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<peliculas[elegir-1]<<endl;
			
			Grabacion.close();

    cout << "\n\nAhora elija su sala de preferencia..."; getch();
	color(hConsole, 15);
}

MenuCartelera::MenuCartelera(){
    altoConsola = 60;
    anchoConsola = 130;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuCartelera::imprimir(){
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
        imprimirOpcion("Saw X", (anchoConsola - 53)/2, 14, opcion==1);
        imprimirOpcion("Five Nights At Freddy's", (anchoConsola + 13)/2 , 14, opcion==2);
		imprimirOpcion("The Eras Tour", (anchoConsola - 53)/2, 24, opcion==3);
		imprimirOpcion("Sonidos de libertad", (anchoConsola + 13)/2, 24, opcion==4);
		imprimirOpcion("El Exorcista: Creyentes", (anchoConsola - 53)/2, 34, opcion==5);
		imprimirOpcion("Sin Aire ", (anchoConsola + 13)/2, 34, opcion==6);
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