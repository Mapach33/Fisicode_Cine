#pragma once
#include <stdio.h>  
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string>
#include <fstream>
#include "funciones.h"


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
		cout<<"\n\t�QUE DESEA COMPRARNOS?-->";
			
}

// funcion principal

int fdulceria(){
 	
 	char opcdulceria = ' ';
 	
 	do{
	
 		dulceria();
 		cin>>opcdulceria;
 
 		switch(opcdulceria){
			case '1':{
				system("cls");
				canchita();
				fcanchita();
				system("pause");
				break;
			}
			
			case '2':{
				system("cls");
				bebidas();
				fbebidas();
				system("pause");
				break;
			}
			
			case '3':{
				system("cls");
				extras();
				fextras();
				system("pause");
				break;
			}
			
			case '4':{
				system("cls");
				combos();
				fcombos();
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

//especificaciones de void
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
		cout<<"\n\t�QUE DESEA COMPRARNOS?-->"<<endl;
		
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
		cout<<"\n\t�QUE DESEA COMPRARNOS?-->"<<endl;
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
		cout<<"\n\t�QUE DESEA COMPRARNOS?-->"<<endl;
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
		cout<<"\n\t�QUE DESEA COMPRARNOS?-->"<<endl;
	}
//especificaciones de funciones
	int fcanchita(){
 	string nomcanchita[] = {"C. dulce mediana","C. dulce grande","C. salada mediana","C. salada grande","C. mixta mediana","C. mixta grande"};
	float pciocanchita[] = {17,20,15,18.5,19,24};
	int cnt_canchita[6];
 	int opccanchita ;
 	float pcanchita;
 	do{
	
 		canchita();
 		cin>>opccanchita;
 
 		switch(opccanchita){
			case 1 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 2 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				
			
				system("pause");
				break;
			}
			
			case 3 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 4 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
		
			case 5 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 6 :{
				system("cls");
				int cntcanchita;
				int opcsn = 0;
				pcanchita = pciocanchita[opccanchita-1];
				do{	
					cout<<"Eligio "<<nomcanchita[opccanchita-1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcanchita;
					cnt_canchita[opccanchita-1] = cntcanchita;
					if(cntcanchita < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcanchita < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcanchita*cntcanchita<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 0 :{
				system("cls");
				system("pause");
				break;
			}
			default:{
				cout<<"Seleccionar una opcion valida "<<endl;
				break;
			}		
		}
	
		
	} while(opccanchita != 0);
	
 	return (0);
}

int fbebidas(){
 	string nombebidas[] = {"inka cola mediana","inka cola grande","coca cola mediana","coca cola grande","agua natural sin gas","agua natural con gas"};
	float pciobebida[] = {5,7,5,7,3.5,4};
	int cnt_bebidas[6];
 	int opcbebida;
 	int pbebida;
 	do{
	
 		bebidas();
 		cin>>opcbebida;
 
 		switch(opcbebida){
			case 1 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida; 
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 2 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida; 
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
				
			
				system("pause");
				break;
			}
			
			case 3 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida;
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 4 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida; 
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
		
			case 5 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida; 
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 6 :{
				system("cls");
				int cntbebida;
				int opcsn = 0;
				pbebida = pciobebida[opcbebida-1];
				do{	
					cout<<"Eligio "<<nombebidas[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntbebida;
					cnt_bebidas[opcbebida-1] = cntbebida; 
					if(cntbebida < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntbebida < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pbebida*cntbebida<<endl;
					system("pause");
					break;
				}
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
	
		
	} while(opcbebida != '0');
	
 	return (0);
}

int fcombos(){
 	string nomcombos[] = {"combo 1","combo 2","combo 3","combo 4","combo 5","combo 6"};
	float pciocombos[] = {26,28,32,33.5,35,33};
	int cnt_combo[6];
 	int opccombos ;
 	int pcombos;
 	do{
	
 		combos();
 		cin>>opccombos;
 
 		switch(opccombos){
			case 1 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 2 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 3 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 4 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 5 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 6 :{
				system("cls");
				int cntcombos;
				int opcsn = 0;
				pcombos = pciocombos[opccombos -1];
				do{	
					cout<<"Eligio "<<nomcombos[opccombos -1]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntcombos;
					cnt_combo[opccombos -1] = cntcombos;
					if(cntcombos < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntcombos < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pcombos*cntcombos<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 0 :{
				system("cls");
				system("pause");
				break;
			}
			
			default:{
				cout<<"Seleccionar una opcion valida "<<endl;
				break;
			}		
		}
	
		
	} while(opccombos != 0);
	
 	return (0);
}

int fextras(){
 	string nomextras[] = {"hot dog","keke de chocolate","choripan","keke marmoleado","keke de vainilla","juguete de promocion"};
	float pcioextras[] = {12,5,10,6.5,5,15};
	int cnt_extras[6];
 	int opcextras;
 	int pextras;
 	do{
	
 		extras();
 		cin>>opcextras;
 
 		switch(opcextras){
			case 1 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
				system("pause");
				
				break;
			}
			
			case 2 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
				
			
				system("pause");
				break;
			}
			
			case 3 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 4 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
		
			case 5 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case 6 :{
				system("cls");
				int cntextras;
				int opcsn = 0;
				pextras = pcioextras[opcextras - 1];
				do{	
					cout<<"Eligio "<<nomextras[0]<<endl;		
					cout<<" ¿Cantidad de su pedido? ";
					cin>>cntextras;
					cnt_extras[opcextras - 1 ] = cntextras;
					if(cntextras < 0){
						cout<<"Cantidad de pedido invalida"<<endl;
						system("pause");
						system("cls");
					}
				}while(cntextras < 0);
				do{
					cout<<" ¿Desea agregar algo mas a su pedido? "<<endl;
					cout<<"[0]SI:                          [1]NO:"<<endl;
					cin>>opcsn;
					if(opcsn < 0 or opcsn>1){
						cout<<"Opcion invalida"<<endl;
						system("cls");
					}
				}while(opcsn < 0 or opcsn>1);
				
				if(opcsn == 0){
						
				} 
				if(opcsn == 1){
					cout<<"Su boleta es: "<<"S/. "<<pextras*cntextras<<endl;
					system("pause");
					break;
				}
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
	
		
	} while(opcextras != '0');
	
 	return (0);
}
