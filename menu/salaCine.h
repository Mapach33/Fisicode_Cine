#pragma once
#include "../tools/funciones.h"
#include "../tools/consola.hpp"
#include "../tools/Menuss.h"

class MenuAsientos : public Menu {
    public:
        MenuAsientos();
        void imprimir();
        void imprimirCine();
        void imprimirUnAsiento(int fila, int columna,bool libre);
        string getAsiento();
    protected:
        vector<vector<int>> asientos;
        int maxFilas, maxColumnas;
        string fila, columna;
};

MenuAsientos::MenuAsientos(){
    
    maxFilas = 6;
    maxColumnas = 10;
    altoConsola = 45;
    asientos.resize(maxFilas, vector<int>(maxColumnas,0));
    anchoConsola = 165;
    cine::Set_Console_Sizes(anchoConsola,altoConsola,false);
    //imprimir();
}

void MenuAsientos::imprimir(){
    system("cls");
    gotoxy(anchoConsola/2 - 8,2);
    cout << "P A N T A L L A";
    imprimirCine();
    gotoxy(anchoConsola/2-19,25);
    do{
        cout << "Ingrese la fila: ";
        getline(cin,fila);
    }while(fila.size() != 1 || fila[0] < 65 || fila[0] > 65+maxFilas);
}

void MenuAsientos::imprimirCine(){
    cine::gotoxy(50,4);
    for(int i=0;i<maxColumnas;i++){
        for(int j=0;j<maxFilas;j++){
            imprimirUnAsiento(50+(i*6),4+(j*3),rand()%2);
        }
    }
    for(int i=0;i<maxFilas;i++){
        gotoxy(50-3,5+(i*3));
        cout<<char(65+i);
    }
    for(int i =0;i<maxColumnas;i++){
        gotoxy(52+(i*6),22);
        cout<<i+1;
    }
}

//Imprime solo un asiento
void MenuAsientos::imprimirUnAsiento(int ejeX,int ejeY ,bool libre){
    cine::gotoxy(ejeX, ejeY);
    
    if(libre){
        cout << char(218)<<char(196)<<char(196)<<char(196)<<char(191);
        cine::gotoxy(ejeX, ejeY+1);
        cout<<char(179)<<"   ";
        cout<<char(179); cine::gotoxy(ejeX, ejeY+2);
        cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
    }else{
        SetConsoleTextAttribute(miconsola, 12);
        cout << char(218)<<char(196)<<char(196)<<char(196)<<char(191);
        cine::gotoxy(ejeX, ejeY+1);
        cout<<char(179)<<" X ";
        cout<<char(179); cine::gotoxy(ejeX, ejeY+2);
        cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
        SetConsoleTextAttribute(miconsola, 15);
    }
}