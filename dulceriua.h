#include <stdio.h>  
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#define color SetConsoleTextAttribute

using namespace std;

//iniciamos el viaje - FICINEMA
//DECLARACION DE FUNCIONES 
void dulceria(){
		
	system("CLS");
		
		cout<<"\n\t DULCERIA FISICODERS ";
		cout<<endl;
		cout<<"\n1.- CANCHITA ";
		cout<<"\n2.- BEBIDAS ";
		cout<<"\n3.- EXTRAS ";
		cout<<"\n4.- COMBOS ";
	
		cout<<"\n\n0.- Salir ";
		cout<<endl;
		cout<<"\n\t¿QUE DESEA COMPRARNOS?-->";
			
}

void canchita();

void bebidas();

void extras();
	
void combos();
	
void gotoxy(int x,int y){  
	  	 HANDLE hcon;  
	      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	      COORD dwPos;  
	      dwPos.X = x;  
	      dwPos.Y= y;  
	      SetConsoleCursorPosition(hcon,dwPos);  
}

void canchitadulcemediana();
int elecioncanchita();

int main(){
 	
 	char opcdulceria = ' ';
 	
 	do{
	
 		dulceria();
 		cin>>opcdulceria;
 
 		switch(opcdulceria){
			case '1':{
				system("cls");
				canchita();
				system("pause");
				break;
			}
			
			case '2':{
				system("cls");
				bebidas();
				system("pause");
				break;
			}
			
			case '3':{
				system("cls");
				extras();
				system("pause");
				break;
			}
			
			case '4':{
				system("cls");
				combos();
				system("pause");
				break;
			}
			
			case '0':{
				system("cls");
				system("pause");
				break;
			}
			default:{
				cout<<"Seleccionar una opcion valida "<<endl;
				break;
			}		
		}
	
		
	} while(opcdulceria != '0');
	
 	return (0);
}

//especificacion
void canchita(){
		system("CLS");
		
		cout<<"\n\t CANCHITA ";
		cout<<endl;
		cout<<"\n1.- CANCHITA DULCE MEDIANA ";
		cout<<"\n2.- CANCHITA DULCE GRANDE ";
		cout<<"\n3.- CANCHITA SALADA MEDIANA";
		cout<<"\n4.- CANCHITA SALADA GRANDE";
		cout<<"\n5.- CANCHITA MIXTA MEDIANA";
		cout<<"\n6.- CANCHITA MIXTA GRANDE";
	
		cout<<"\n\n0.- Salir ";
		cout<<endl;
		cout<<"\n\t¿QUE DESEA COMPRARNOS?-->"<<endl;
		
}

	void bebidas(){
		system("CLS");
		
		cout<<"\n\t BEBIDAS ";
		cout<<endl;
		cout<<"\n1.- INKA COLA MEDIANA ";
		cout<<"\n2.- INKA COLA GRANDE ";
		cout<<"\n3.- COCA COLA MEDIANA";
		cout<<"\n4.- COCA COLA GRANDE";
		cout<<"\n5.- AGUA NATURAL SIN GAS";
		cout<<"\n6.- AGUA NATURAL CON GAS";
	
		cout<<"\n\n0.- Salir ";
		cout<<endl;
		cout<<"\n\t¿QUE DESEA COMPRARNOS?-->"<<endl;
	}

	void extras(){
		system("CLS");
		
		cout<<"\n\t EXTRAS ";
		cout<<endl;
		cout<<"\n1.- HOT DOG ";
		cout<<"\n2.- KEKE CHOCOLATE ";
		cout<<"\n3.- CHORIPAN ";
		cout<<"\n4.- FRUGOS ";
		cout<<"\n5.- KEKE VAINILLA";
		cout<<"\n6.- JUGUETE DE PROMOCION";
	
		cout<<"\n\n0.- Salir ";
		cout<<endl;
		cout<<"\n\t¿QUE DESEA COMPRARNOS?-->"<<endl;
	}
	
	void combos(){
		system("CLS");
		
		cout<<"\n\t COMBOS ";
		cout<<endl;
		cout<<"\n1.- CANCHA GRANDE + 2 GASEOSAS GRANDES ";
		cout<<"\n2.- 2 CANCHAS MEDINAS + 3 GASEOSAS MEDIANAS ";
		cout<<"\n3.- CANCHA GRANDE + 2 HOT DOG + 2 GASEOSAS MEDIANAS";
		cout<<"\n4.- 2 CANCHAS GRANDES + 5 GASEOSAS MEDIANAS ";
		cout<<"\n5.- 2 CANCHAS GRANDES + 3 GASEOSAS GRANDES + 3 HOT DOG";
		cout<<"\n6.- 4 CANCHAS MEDIANAS + 4 GASEOSAS GRANDES + 4 HOT DOG";
	
		cout<<"\n\n0.- Salir ";
		cout<<endl;
		cout<<"\n\t¿QUE DESEA COMPRARNOS?-->"<<endl;
	}
	
