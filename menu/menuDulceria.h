#pragma once
#include "../tools/funciones.h"
#include "../tools/Menuss.h"
#include "menuAmbiente.hpp"

class MenuDulceria : public Menu{
    public:
        MenuDulceria();
        void imprimir();
        void imprimirDescripcion();
        void imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado);
        void imprimirMarco(int ejeX, int ejeY);
    protected:
        int ejeXDes, ejeYDes;
        vector<string> descripcion;
};

void elegir_combo() {
    string cantidad;
    string combo[] = {"Cancha Grande + 2 Gaseosas Grandes","2 Canchas Medianas + 3 Gaseosas Medianas","Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas",
         "2 Canchas Grandes + 5 Gaseosas Medianas","2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog", "Canchas Medianas + 4 Gaseosas Grandes + 4 Hot Dog"};
	short precio[] =  {26,28,32,33,35,45};

	MenuDulceria menuDulceria; 

	short elegir = menuDulceria.getOpcion();
	ShowConsoleCursor(true);
	SetConsoleTextAttribute(hConsole, 9);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                         -----------------------------------------------------------------"; cout<<endl;
			cout << "                                         Combo    : "<<combo[elegir-1]<< endl;
			cout << "                                         Precio   : "<< precio[elegir-1] << endl; 
			cout << "                                         Solo se permite comprar de 1 a 3 combos"; cout<<endl;
			short xcantidad;
			do{
				cout << "                                         Cantidad : ";         
				getline(cin, cantidad); 
				istringstream(cantidad)>>xcantidad ; 
				if(xcantidad < 1 || xcantidad > 3){
					cout << "                                         Cantidad no valida, intente de nuevo...    ";getch();
					cout << "                                                       ";
				}
			}while(xcantidad < 1 || xcantidad > 3);
		  	cout << "                                         ---------------------------------------------------------------"; cout <<endl;
			cout << "                                         Agradecemos su Compra..."; getch();
            cout << endl;

	ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<combo[elegir-1]<<endl;//Tipo
			Grabacion<<xcantidad <<endl;//Cantidad
			Grabacion<<precio[elegir-1]<<endl;//Precio U
			Grabacion<<xcantidad * precio[elegir-1]<<endl;//Precio T
			Grabacion.close();

    gotoxy(42, 45);cout << "                                         Imprimiendo Boleta..."; getch();
	SetConsoleTextAttribute(hConsole, 15);
}

void MenuDulceria::imprimirDescripcion(){
    //Limpia el espacio de la descripcion
    for(int i=0;i<altoMarco-2; i++){
        gotoxy(ejeXDes+1, ejeYDes+1+i);
        cout<<string(anchoMarco - 2,' ');
    }
    vector<string> description;
    string parsed_word, line = "";
     bool first_word = true;
    // Procesar la descripcion y dividirla en lineas de maximo 19 caracteres
    istringstream string_stream(descripcion[opcion - 1]);


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

void MenuDulceria::imprimirMarco(int ejeX, int ejeY){
   gotoxy(ejeX, ejeY);
   SetConsoleTextAttribute(miconsola,colorMarco);    //probar 

    gotoxy(ejeX, ejeY);
    cout << string (anchoMarco, char(220));

    gotoxy(ejeX, (ejeY + altoMarco  - 1));
    cout << string (anchoMarco, char(223));

    for (int i = 0; i < (altoMarco - 2); i++) {
        gotoxy(ejeX, i + (ejeY + 1));
        cout << char (186);
        gotoxy(ejeX + (anchoMarco - 1), i + (ejeY + 1));
        cout << char (186);
    }SetConsoleTextAttribute(miconsola, 15);
}


void MenuDulceria::imprimir(){
    system("cls ");
    string cartelera = 
    R"( _____                    _                 
/  __ \                  | |                
| /  \/  ___   _ __ ___  | |__    ___   ___ 
| |     / _ \ | '_ ` _ \ | '_ \  / _ \ / __|
| \__/\| (_) || | | | | || |_) || (_) |\__ \
 \____/ \___/ |_| |_| |_||_.__/  \___/ |___/ )";
    altoMarco = 25;
    anchoMarco = 45;
    SetConsoleTextAttribute(miconsola, 11);
    printRawCenter(cartelera);
    SetConsoleTextAttribute(miconsola, 15);
    int ejeXMarco = (anchoConsola)/4 - anchoMarco/2;
    imprimirMarco(ejeXMarco,7);
    ejeXDes = ejeXMarco + anchoMarco + (anchoConsola)/2 - anchoMarco;
    ejeYDes = 7;
    imprimirMarco(ejeXDes, ejeYDes);
    bool continuar=true;
    
    while(continuar){
        imprimirOpcion("C.1 S/.26", ejeXMarco + 5 , 11, opcion==1);
        imprimirOpcion("C.2 S/.28", ejeXMarco + 22, 11, opcion==2);
		imprimirOpcion("C.3 S/.32", ejeXMarco + 5, 18, opcion==3);
		imprimirOpcion("C.4 S/.33", ejeXMarco + 22, 18, opcion==4);
		imprimirOpcion("C.5 S/.35", ejeXMarco + 5, 25, opcion==5);
		imprimirOpcion("C.6 S/.45", ejeXMarco + 22, 25, opcion==6);
        imprimirDescripcion();
        switch (getTecla()) {
    
			case key::w:
            case Up:
                if (opcion > 2) opcion-=2;
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

void MenuDulceria::imprimirOpcion(string nombreOpcion,int posicionX, int posicionY,bool seleccionado){

    int largoOpcion{15}, altoOpcion{3}; // esto se puede cambiar

    colorOpcion = 8;

    //Cambia el color de la opcion seleccionada
    if(seleccionado) {colorOpcion = colorMarco;}

    SetConsoleTextAttribute(miconsola,colorOpcion);

    gotoxy (posicionX, posicionY + 1);
    cout << string (largoOpcion, '\xDB');
    gotoxy(posicionX, posicionY);
    cout << char ('\xDA') << string (largoOpcion - 2,'\xDC') << char ('\xBF');
    gotoxy(posicionX, (altoOpcion + posicionY - 1));
    cout << char ('\xC0') << string (largoOpcion - 2,'\xDF') << char ('\xD9');

    //Cambia el color de la opcion seleccionada
    if (seleccionado) colorOpcion = colorTexto; else colorOpcion = 143;

    SetConsoleTextAttribute(miconsola, colorOpcion);
    gotoxy (posicionX + ((largoOpcion - nombreOpcion.length()) / 2), posicionY + 1);
    cout << nombreOpcion;

    SetConsoleTextAttribute(miconsola, 15);
}

MenuDulceria::MenuDulceria(){
    descripcion = {"Cancha Grande + 2 Gaseosas Grandes","2 Canchas Medianas + 3 Gaseosas Medianas","Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas",
         "2 Canchas Grandes + 5 Gaseosas Medianas","2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog", "Canchas Medianas + 4 Gaseosas Grandes + 4 Hot Dog"};
    altoConsola = 40;
    anchoConsola = 140;
    Set_Console_Sizes(anchoConsola, altoConsola, false);
    colorTexto = 144;
    colorMarco = 9;
    opcion = 1;
    imprimir();
}