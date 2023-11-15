#pragma once
#include <stdio.h>  
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../tools/funciones.h"

using namespace std;

void Combos(){
		
	system("CLS");
		
		cout<<"\n\t COMBOS ";
		cout<<endl;
		cout<<"\n1.- Cancha Grande + 2 Gaseosas Grandes ";
		cout<<"\n2.- 2 Canchas Medianas + 3 Gaseosas Medianas ";
		cout<<"\n3.- Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas";
		cout<<"\n4.- 2 Canchas Grandes + 5 Gaseosas Medianas ";
		cout<<"\n5.- 2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog";
		
		cout<<"\n\n6.- No deseo comprar nada ";
		cout<<endl;
		cout<<"\n\tElija una opcion----->"<<endl;
			
}

void ElegirCombos(){
    string nomcombos[] = {"Cancha Grande + 2 Gaseosas Grandes","2 Canchas Medianas + 3 Gaseosas Medianas","Cancha Mediana + 2 Hot Dog + 2 Gaseosas Medianas",
                            "2 Canchas Grandes + 5 Gaseosas Medianas","2 Canchas Grandes + 3 Gaseosas GRANDES + 3 Hot Dog"};
	float pciocombos[] = {26,28,32,33.5,35};
	
 	string x_opccombos;
    short opccombos;
 	short cntcombos;
    float precio;
    do{
        getline(cin, x_opccombos);
		istringstream(x_opccombos) >> opccombos;
		
		cout << endl;
				
        if(opccombos > 6 || opccombos < 1){
			cout << "Ingrese una opcion valida (1-6)...            " << endl;
			cout << endl;
			cout << "                                     " << endl;
        }       
    } while (opccombos > 6 || opccombos < 1);

    cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;

	cout<<" ¿Cantidad de su pedido? "; cin>>cntcombos;

    system("pause");
    precio = pciocombos [opccombos -1] * cntcombos;

    ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<nomcombos [opccombos-1]<<endl;
			Grabacion<<precio<<endl;
			Grabacion.close();
}