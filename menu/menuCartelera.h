#pragma once
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"

class MenuCartelera : public Menu{
    public:
        MenuCartelera();
        void imprimir();
        void imprimirDescripcion();
        void imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado);
        void imprimirMarco(int ejeX, int ejeY);
    protected:
        int ejeXDes, ejeYDes;
        vector<string> sinopsis;
};


void elegir_pelicula() {
    
	short elegir;
    vector<string> peliculas = {"Saw X", "Susy", "The Eras Tour", "The Marvels", "El Exorcista", "Trolls 3"};

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
	SetConsoleTextAttribute(hConsole, 15);
}



void MenuCartelera::imprimirMarco(int ejeX, int ejeY){
   gotoxy(ejeX, ejeY);
   SetConsoleTextAttribute(miconsola,colorMarco);    //probar 

    cine::gotoxy(ejeX, ejeY);
    cout << string (anchoMarco, char(220));

    cine::gotoxy(ejeX, (ejeY + altoMarco  - 1));
    cout << string (anchoMarco, char(223));

    for (int i = 0; i < (altoMarco - 2); i++) {
        cine::gotoxy(ejeX, i + (ejeY + 1));
        cout << char (186);
        cine::gotoxy(ejeX + (anchoMarco - 1), i + (ejeY + 1));
        cout << char (186);
    }SetConsoleTextAttribute(miconsola, 15);
}


void MenuCartelera::imprimir(){
    system("cls");
    string cartelera = 
    R"(  _____           _       _                
 / ____|         | |     | |               
| |     __ _ _ __| |_ ___| | ___ _ __ __ _ 
| |    / _` | '__| __/ _ \ |/ _ \ '__/ _` |
| |___| (_| | |  | ||  __/ |  __/ | | (_| |
 \_____\__,_|_|   \__\___|_|\___|_|  \__,_|)";
    altoMarco = 25;
    anchoMarco = 45;
    cine::printRawCenter(cartelera);
    int ejeXMarco = (anchoConsola)/4 - anchoMarco/2;
    imprimirMarco(ejeXMarco,7);
    ejeXDes = ejeXMarco + anchoMarco + (anchoConsola)/2 - anchoMarco;
    ejeYDes = 7;
    imprimirMarco(ejeXDes, ejeYDes);

    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("Saw X",ejeXMarco + 5 , 11, opcion==1);
        imprimirOpcion("Susy", ejeXMarco + 22, 11, opcion==2);
		imprimirOpcion("The Eras Tour", ejeXMarco + 5, 18, opcion==3);
		imprimirOpcion("The Marvels", ejeXMarco + 22, 18, opcion==4);
		imprimirOpcion("El Exorcista", ejeXMarco + 5, 25, opcion==5);
		imprimirOpcion("Trolls 3 ", ejeXMarco + 22, 25, opcion==6);
        imprimirDescripcion();
        switch (cine::getch()) {
    
			case key::w:
            case Up:
                if (opcion > 2 ) opcion-=2;
                break;
			
			case key::d:
			case Right:
                if (opcion < 6) opcion++;
                break;

            case::key::s:
            case Down:
                if (opcion < 5) opcion+=2;
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

void MenuCartelera::imprimirDescripcion(){
    //Limpia el espacio de la descripcion
    for(int i=0;i<altoMarco-2; i++){
        gotoxy(ejeXDes+1, ejeYDes+1+i);
        cout<<string(anchoMarco - 2,' ');
    }
    vector<string> description;
    string parsed_word, line = "";
     bool first_word = true;
    // Procesar la descripcion y dividirla en lineas de maximo 19 caracteres
    istringstream string_stream(sinopsis[opcion - 1]);

    while (getline(string_stream, parsed_word, ' ')) {
        if ((line.length() + parsed_word.length() + 1) <= anchoMarco-4) {
            if (first_word != true) 
                line += " " + parsed_word; 
            else {
                line += parsed_word; 
                first_word = false;
            }
        } else {
            description.push_back(line); 
            line = ""; 
            line += parsed_word;
        }
    }
    description.push_back(line);
    int description_size = description.size();
    for (int i = 0; i < description_size; i++) {
        int center_format = ((anchoMarco-2 - description[i].length()) / 2);
        gotoxy(ejeXDes + 1, 12 + i);
        cout << string (center_format, ' ') << description[i];
    }
}

void MenuCartelera::imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado){

    int largoOpcion{15}, altoOpcion{3}; // esto se puede cambiar

    colorOpcion = 8;

    //Cambia el color de la opcion seleccionada
    if(seleccionado) {colorOpcion = colorMarco;}

    SetConsoleTextAttribute(miconsola,colorOpcion);

    cine::gotoxy (posicionX, posicionY + 1);
    cout << string (largoOpcion, '\xDB');
    cine::gotoxy(posicionX, posicionY);
    cout << char ('\xDA') << string (largoOpcion - 2,'\xDC') << char ('\xBF');
    cine::gotoxy(posicionX, (altoOpcion + posicionY - 1));
    cout << char ('\xC0') << string (largoOpcion - 2,'\xDF') << char ('\xD9');

    //Cambia el color de la opcion seleccionada
    if (seleccionado) colorOpcion = colorTexto; else colorOpcion = 143;

    SetConsoleTextAttribute(miconsola, colorOpcion);
    cine::gotoxy (posicionX + ((largoOpcion - nombreOpcion.length()) / 2), posicionY + 1);
    cout << nombreOpcion;

    SetConsoleTextAttribute(miconsola, 15);
}

MenuCartelera::MenuCartelera(){
                     sinopsis =  {"John Kramer (Tobin Bell) esta de vuelta. La entrega mas perturbadora de la franquicia de SAW explora el capitulo nunca antes contado del juego mas personal de Jigsaw. Toma lugar entre los eventos ocurridos de SAW I (El juego del miedo) y SAW II (El juego del miedo 2), un enfermo y desesperado John viaja a Mexico por un arriesgado y experimental procedimiento medico con la esperanza de encontrar milagrosamente una cura para su cancer  solo para descubrir que toda la operacion es una estafa.", 
                                "La historia de una nina, que crece llena de suenos, con padres que no comprendian que su picardia escondia inteligencia, la madre sonaba con un hija monja y el padre si comprendia sus suenos, trabajo de muy joven en un colegio inicial y luego rapidamente entro en el mundo de la television primero como recepcionista y posteriormente logra ingresar al mundo de la comedia, es ahi donde se inicia nuestra divertida historia de la Madre de la Patria.",
						        "El fenomeno cultural continua en la pantalla grande! Sumergete en esta experiencia cinematografica de este concierto unico en la vida. Podras disfrutarlo con una vista impresionante de la gira historica desde la pantalla grande.  Se recomienda usar la vestimenta de Taylor Swift Eras y tus friendship bracelets!", 
                                "Carol Danvers, alias Capitana Marvel, ha recuperado su identidad de los tiranicos Kree y se ha vengado de la Inteligencia Suprema. Pero las consecuencias imprevistas hacen que Carol cargue con el peso de un universo desestabilizado. Cuando sus deberes la envian a un agujero de gusano anomalo vinculado a un revolucionario Kree, sus poderes se enredan con los de la superfan oriunda de la ciudad de Jersey, Kamala Khan, alias Ms. Marvel, y la sobrina distanciada de Carol, la ahora astronauta de S.A.",
						        "Hace exactamente 50 anos, la pelicula de terror mas aterradora de la historia llego a las pantallas, impactando a la audiencia de todo el mundo. Este ano, en octubre, comienza un nuevo capitulo. De Blumhouse y el director David Gordon Green, quienes rompieron el statu quo con la resurreccion de la franquicia de Halloween, llega \"El Exorcista: Creyentes\". Desde la muerte de su esposa embarazada en un terremoto en Haiti hace 12 anos, Victor Fielding (ganador del Tony y nominado a los Premios de la Academia®, Leslie Odom Jr.",
                                "En esta nueva entrega de la exitosa franquicia, Poppy y Ramon ya son oficialmente una pareja, y a medida que se van conociendo surge el pasado oscuro de Ramon:  fue parte de la legendaria banda de pop, BroZone! Ahora nuestros protagonistas se embarcaran en una aventura para rescatar a los hermanos de Ramon y salvar la musica pop."};
    altoConsola = 40;
    anchoConsola = 140;
    cine::Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 144;
    colorMarco = 9;
    opcion = 1;
    imprimir();
}

    

