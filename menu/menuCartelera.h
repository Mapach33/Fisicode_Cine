#pragma once
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"
#define color SetConsoleTextAttribute//define el setcontrol para llamarlo por "color"
using namespace std;
class MenuCartelera : public Menu{
    public:
        MenuCartelera();
        void imprimir();
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void elegir_pelicula() {
    
	short elegir;
	
    string peliculas[] = {"Saw X", "Five Nights At Freddy's", "The Eras Tour", "Sonidos de libertad", "El Exorcista: Creyentes", "Sin Aire"};
	string duracion[] =  {"2hrs 0min", "1hrs 50min", "2hrs 45min", "2hrs 10min", "2hrs 0min", "1hrs 30min"};
	string director[] =  {"Kevin Greutert", "Emma Tammi", "Sam Wrench", "Alejandro Gomez Monteverde", "David Gordon Green", "Maximilian Erlenwein"};
	string sinopsis[] =  {"Un asesino busca venganza", "Un guardia teme por su vida", "Sumergete en la experiencia cinematografica de este concierto",
						 "Un agente se embarca en la mision de salvar a una chica del trafico de menores", "La pelicula de terror mas aterradora de la historia volvio a las pantallas",
						 "May yace en lo profundo bajo el mar, atrapada por escombros e incapaz de moverse"};

	
	MenuCartelera menuCartelera; 
	elegir = menuCartelera.getOpcion();
	ofstream Grabacion("boleta.txt", ios::out);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<peliculas[elegir-1]<<endl;
			
			Grabacion.close();
    SetConsoleTextAttribute(hConsole, 112);
	cout << "\n\n\n\n\n\n\n\n\n\n-----------------------------------------------------------------------------"<<endl;
	cout << peliculas[elegir-1]<< endl;
	cout << "-----------------------------------------------------------------------------"<<endl;
	cout << "Duracion: " << duracion[elegir-1] << endl;
	cout << "Director: " << director[elegir-1] << endl;
	cout << "Sinopsis: " << sinopsis[elegir-1] << endl;   
	cout << "-----------------------------------------------------------------------------"<<endl;
	cout << endl;	
	cout << "Ahora elija su sala de preferencia..."; getch();
	

    
	color(hConsole, 15);
}

MenuCartelera::MenuCartelera(){
    altoConsola = 50;
    anchoConsola = 110;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 112;
    colorMarco = 115;
    opcion = 1;
    imprimir();
}

void MenuCartelera::imprimir(){
    system("cls && COLOR 70");
    string cartelera = 
    R"(  _____           _       _                
 / ____|         | |     | |               
| |     __ _ _ __| |_ ___| | ___ _ __ __ _ 
| |    / _` | '__| __/ _ \ |/ _ \ '__/ _` |
| |___| (_| | |  | ||  __/ |  __/ | | (_| |
 \_____\__,_|_|   \__\___|_|\___|_|  \__,_|)";
	int ejeYmarco = 7;
    altoMarco = 27;
    anchoMarco = 64;
    cine::gotoY(1);
    cine::printRawCenter(cartelera);
    imprimirMarco(ejeYmarco);
    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("Saw X", (anchoConsola - 53)/2, 11, opcion==1);
        imprimirOpcion("Five Nights At Freddy's", (anchoConsola + 9)/2 , 11, opcion==2);
		imprimirOpcion("The Eras Tour", (anchoConsola - 53)/2, 18, opcion==3);
		imprimirOpcion("Sonidos de libertad", (anchoConsola + 9)/2, 18, opcion==4);
		imprimirOpcion("El Exorcista: Creyentes", (anchoConsola - 53)/2, 25, opcion==5);
		imprimirOpcion("Sin Aire ", (anchoConsola + 9)/2, 25, opcion==6);
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