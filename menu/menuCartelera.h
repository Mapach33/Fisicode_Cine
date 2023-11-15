#pragma once
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

void elegir_pelicula() {
    
	short elegir, i = 0;
	
    string peliculas[] = {"Saw X", "Five Nights At Freddy's", "The Eras Tour", "Sonidos de libertad", "El Exorcista: Creyentes", "Sin Aire"};
	string duracion[] =  {"2hrs 0min", "1hrs 50min", "2hrs 45min", "2hrs 10min", "2hrs 0min", "1hrs 30min"};
	string director[] =  {"Kevin Greutert", "Emma Tammi", "Sam Wrench", "Alejandro Gomez Monteverde", "David Gordon Green", "Maximilian Erlenwein"};
	string sinopsis[] =  {"Un asesino busca venganza", "Un guardia teme por su vida", "Sumergete en la experiencia cinematografica de este concierto",
						 "Un agente se embarca en la mision de salvar a una niña del trafico de menores", "La pelicula de terror mas aterradora de la historia volvio a las pantallas",
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