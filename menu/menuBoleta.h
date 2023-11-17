#pragma once  
#include "../tools/funciones.h"
#include <string>

using namespace std;
struct boleta{
    string pelicula, sala, p_unit, hora,asiento, t_combo, pu_combo, c_combo, pt_combo;
}b1;

void Lee(ifstream &lee){
    Set_Console_Sizes(77,25,1);
		system("CLS");
		getline(lee,b1.pelicula);
        getline(lee,b1.sala);
        getline(lee,b1.p_unit);
        getline(lee,b1.hora);
        getline(lee,b1.asiento);
        getline(lee,b1.t_combo);
        getline(lee,b1.c_combo);
        getline(lee,b1.pu_combo);
        getline(lee,b1.pt_combo);

        system("CLS");
        cout << "                 Boleta" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Pelicula           : " << b1.pelicula << endl;
        cout << "Sala               : " << b1.sala<< endl;
        cout << "Horario            : " << b1.hora<< endl;
        cout << "Asiento            : " << b1.asiento <<endl;
        cout << "Precio del Asiento : " << b1.p_unit<<endl;
        cout << "------------------------------------------" << endl;
        cout << "Combos             : " << b1.t_combo<< endl;
        cout << "Cantidad de Combos : " << b1.c_combo<<endl;
        cout << "Precio Unitario    : " << b1.pu_combo<<endl;
        cout << "Precio T. Combo    : " << b1.pt_combo<<endl;
        cout << "------------------------------------------" << endl;
        cout << "Precio Total       : " <<stoi(b1.p_unit) + stoi(b1.pt_combo) <<endl;
        cout << "IGV (18%)          : "<<(stoi(b1.p_unit) + stoi(b1.pt_combo))*0.18<<endl;
        cout << "Total a Pagar      : "<<(stoi(b1.p_unit) + stoi(b1.pt_combo))*1.18<<endl;
        cout << "------------------------------------------" << endl;
        cout << "           Gracias por su compra" << endl;
        cout << "------------------------------------------" << endl;
        system("pause");

}

void imprimirBoleta(){
    ifstream Leer("boleta.txt", ios::in);
    if(Leer.fail()){
        cout<<"Error en el archivo..."<<endl;
        Sleep(2000);
        exit(1);
    }
    Lee(Leer);
    Leer.close();
	   
}