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
string pelicula, duracion, director, sinopsis, costo_pelicula ;
void Lee(ifstream &lee){
		system("CLS");
		getline(lee,pelicula);
		while(!lee.eof()){
			getline(lee,duracion);
			getline(lee,director);
			getline(lee,sinopsis);
            getline(lee,costo_pelicula);
			 system("CLS");
            cout << "Boleta" << endl;
            cout << "--------------------------" << endl;
            cout << "Pelicula: " << pelicula << endl;
            cout << "Sala: " << "falta rellenar" << endl;
            cout << "Horario: " << "falta rellenar" << endl;
            cout << "Asientos: " << endl;
            cout << "--------------------------" << endl;
            cout << "Subtotal: " << endl;
            cout << "IGV: " << endl;
            cout << "Total: " << endl;
            cout << "--------------------------" << endl;
            cout << "Combos: " << endl;
            cout << "--------------------------" << endl;
            cout << "Total a pagar: " << endl;
            cout << "--------------------------" << endl;
            cout << "Gracias por su compra" << endl;
            cout << "--------------------------" << endl;
            system("pause");
			getline(lee,pelicula);
		}
		system("pause");

}

void imprimirBoleta(short opcion){
    switch (opcion)
    {
        case 1:{
            ifstream Leer("boleta.txt", ios::in);
			if(Leer.fail()){
				cout<<"Error en el archivo..."<<endl;
				Sleep(2000);
				exit(1);
			}
			Lee(Leer);
			Leer.close();
			
			break;
                   
        }
            
       
        
        case 2:
           
            break;
    }
   
}