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
    protected:
        vector<vector<int>> asientos;
        int maxFilas, maxColumnas;
        string fila, columna;
};

//Constructor
MenuAsientos::MenuAsientos(){
    maxFilas = 6;
    maxColumnas = 10;
    asientos.resize(maxFilas, vector<int>(maxColumnas,0));
    for(int i=0;i<maxFilas;i++){
        for(int j=0;j<maxColumnas;j++){
            asientos[i][j] = rand()%2;
        }
    }
    altoConsola = 45;
    anchoConsola = 165;
    cine::Set_Console_Sizes(anchoConsola,altoConsola,false);
    imprimir();
}


void MenuAsientos::imprimir(){
    system("cls && color 7");
    int colu;
    gotoxy(anchoConsola/2 - 8,2);cout << "P A N T A L L A";
    imprimirCine();
    cine::ShowConsoleCursor(true);
    do{
        gotoxy(anchoConsola/2-19,25);cout<<string(50,' ');gotoxy(anchoConsola/2-19,26);cout<<string(50,' ');
        //Consistecia para la fila
        do{
            gotoxy(anchoConsola/2-19,25);
            cout << "Ingrese la fila: "<<string(10,' ');cine::gotoX(anchoConsola/2-1);
            getline(cin,fila);
        }while(fila.size() != 1 || fila[0] < 65 || fila[0] > 65+maxFilas);

        //Consistencia para la columna
        do{
            gotoxy(anchoConsola/2-19,26);
            cout << "Ingrese la columna: ";string(10,' ');cine::gotoX(anchoConsola/2+2);
            getline(cin,columna);
            colu = stoi(columna);
        }while(colu<1 or colu>maxColumnas);

    }while(asientos[fila[0]-65][colu] == 0);

    ofstream Grabacion("boleta.txt", ios::app);
			if(Grabacion.fail()){
				cout << "Error en el archivo..." << endl;
				Sleep(2000);
				exit(1);
			}
			Grabacion<<fila<<columna<<endl;
			Grabacion.close();
}

void MenuAsientos::imprimirCine(){
    cine::gotoxy(50,4);
    //Imprime todos los asientos
    for(int i=0;i<maxFilas;i++){
        for(int j=0;j<maxColumnas;j++){
            imprimirUnAsiento(50+(j*6),4+(i*3),asientos[i][j]);
        }
    }
    //Imprime los numeros de las filas y columnas
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