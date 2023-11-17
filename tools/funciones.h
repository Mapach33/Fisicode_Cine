#pragma once
#include <iostream>
#include <locale.h>
#include <fstream>
#include "consola.hpp"
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

using namespace std;

struct coordXY {
        int x;
        int y;
};

enum key {
        //numeros ramdons
        Up = 600,
        Down = 700,
        Left = 800,
        Right = 900,

        Backspace = 8,
        Tab = 9, 
        End = 35,
        Home = 36,
        Supr = 46, 

        a = 97,
        w = 119,
        s = 115,
        d = 100,

        ExitKey = 27,
        Space = 32,
        Enter = 13
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) {
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hConsole, dwPos);
}

//para llamar a cualquiera de estas  funciones usaremos cine::<funcion>
namespace cine 
{   
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Imprime mas rapido
    // void print(char ch) {
    //     WriteConsole(hConsole, &ch, 1, NULL, NULL);
    // }
    // void print(std::string str) {
    //     WriteConsole(hConsole, str.c_str(), str.length(), NULL, NULL);
    // }
    // void print(const char* str) {
    //     WriteConsole(hConsole, str, strlen(str), NULL, NULL);
    // }

    //Logotoipo de fisicode
    std::string logo_fisicode = 
    R"( _____   ___   ____    ___    ____    ___    ____    _____ 
|  ___| |_ _| / ___|  |_ _|  / ___|  / _ \  |  _ \  | ____|
| |_     | |  \___ \   | |  | |     | | | | | | | | |  _|  
|  _|    | |   ___) |  | |  | |___  | |_| | | |_| | | |___ 
|_|     |___| |____/  |___|  \____|  \___/  |____/  |_____|)";

    

    //Estructura que permite trabajaar en conjuntos las coordenada (x,y) para no trabajarlas por separadas


    //Obtiene la posicion del cursor donde se encuentra
    coordXY getCursorPosition(){
        coordXY coords;
        CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
        GetConsoleScreenBufferInfo(hConsole, &BufferInfo);
        coords = { BufferInfo.dwCursorPosition.X, BufferInfo.dwCursorPosition.Y };
        return coords;
    }

    //Mueve el cursor a un al punto x y
    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    //gotoxy con parametro de coordenada
    void gotoxy(coordXY pos){
        COORD cursorPosition = { short(pos.x), short(pos.y) };
        SetConsoleCursorPosition(hConsole, cursorPosition);
    }

    //Mueve el cursor solo en el eje X
    void gotoX(short x){
        COORD cursorPosition = { x, short(cine::getCursorPosition().y) };
        SetConsoleCursorPosition(hConsole, cursorPosition);
    }

    //Mueve el cursor en el eje Y
    void gotoY(short y){
        COORD cursorPosition = { short(cine::getCursorPosition().x), y};
        SetConsoleCursorPosition(hConsole, cursorPosition);
    }

    // Devuelve el tamano de la consola (columns/filas) como vector 2d { x, y }
    coordXY getConsoleSize() {
        coordXY coords;
        CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
        GetConsoleScreenBufferInfo(hConsole, &BufferInfo);
        coords = { BufferInfo.dwSize.X, BufferInfo.dwSize.Y };

        return coords;
    }
    
    // Imprime un texto multilinea de forma centrada en la consola
    void printRawCenter(std::string& raw) {
        SetConsoleTextAttribute(hConsole, 11); 
        std::vector<std::string> subStringsList;
        std::string buffer = "";

        // Divide la cadena en subcadenas en funcion de los saltos de linea
        for (size_t i = 0; i < raw.length(); i++) {
            if (raw[i] != '\n' && i != raw.length() - 1) {
                buffer += raw[i];
            } else {
                if (buffer.empty() && subStringsList.empty()) {
                    // Si es la primera linea vacia, agrega espacios para centrarla
                    size_t consoleWidth = getConsoleSize().x;
                    size_t padding = (consoleWidth - buffer.length()) / 2;
                    buffer = std::string(padding, ' ') + buffer;
                }
                subStringsList.push_back(buffer);
                buffer = "";
            }
        }

        // Determina la longitud de la linea mas larga
        size_t biggestSlice = 0;
        for (std::string substr : subStringsList) {
            if (substr.length() >= biggestSlice) {
                biggestSlice = substr.length();
            }
        }

        // Calcula el desplazamiento horizontal
        int offset = (getConsoleSize().x)/2 - (biggestSlice / 2);
        // Imprime el texto centrado
        for (size_t i = 0; i < subStringsList.size(); i++) {
            cine::gotoX(offset);
            cout<< subStringsList[i] << "\n";
        }
        SetConsoleTextAttribute(hConsole, 15);
    }
    
    //Obtiene la tecla presionado o en su efecto el caracter;
    int getch(){
        //if (_kbhit()) { // Comprobar si se presiono una tecla
        //primero obtenemos el caracter de control
        int control = _getch(); //  
        int input; 
        if (_kbhit()) input = _getch();

        switch (control) {
        case 224://caso cuando es caracter de control
            if (input == 77) return Right;
            if (input == 75) return Left;
            if (input == 72) return Up;
            if (input == 80) return Down;
            break;
        default:
            return control;//sino hay caracter de control solo retorna asci de la tecla
            break;
        }
        //}
        return 0;
    }
}//namespaces cine


//Retorna la fecha y hora actual
string obteneFechaHora() {
    SYSTEMTIME localTime; GetLocalTime(&localTime);
    stringstream ss; ss << localTime.wYear << "/" << localTime.wMonth << "/" << localTime.wDay;
    return ss.str();
}