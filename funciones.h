#pragma once
#include <iostream>
#include "Consola.hpp"
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <string.h>

//para llamar a cualquiera de estas  funciones usaremos cine::<funcion>
namespace cine 
{   
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    //Imprime mas rapido
    void print(char ch) {
        WriteConsole(consoleHandle, &ch, 1, NULL, NULL);
    }
    void print(std::string str) {
        WriteConsole(consoleHandle, str.c_str(), str.length(), NULL, NULL);
    }
    void print(const char* str) {
        WriteConsole(consoleHandle, str, strlen(str), NULL, NULL);
    }

    //Logotoipo de fisicode
    std::string logo_fisicode = 
    R"(_____   ___   ____    ___    ____    ___    ____    _____ 
|  ___| |_ _| / ___|  |_ _|  / ___|  / _ \  |  _ \  | ____|
| |_     | |  \___ \   | |  | |     | | | | | | | | |  _|  
|  _|    | |   ___) |  | |  | |___  | |_| | | |_| | | |___ 
|_|     |___| |____/  |___|  \____|  \___/  |____/  |_____|)";

    //Linea blanca
    

    //Estructura que permite trabajaar en conjuntos las coordenada (x,y) para no trabajarlas por separadas
    struct coordXY {
        int x;
        int y;
        bool operator == (const coordXY& vec) { return (x == vec.x && y == vec.y); }
        bool operator != (const coordXY& vec) { return !(*this == vec); }
        coordXY operator + (const coordXY& vec) { return { x + vec.x, y + vec.y }; }
        coordXY operator - (const coordXY& vec) { return { x - vec.x, y - vec.y }; }
    };

    enum key {
        //artificial keycodes
        Up = 250,
        Down = 251,
        Left = 252,
        Right = 253,

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

    //Imprime un texto con un determinado color
    void textoColorFondo(const std::string& text, ConsoleColor backgroundColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, backgroundColor);
    // Imprimir el texto
    cine::print(text);
    SetConsoleTextAttribute(consoleHandle, 0);
    }

    //Modifica la visibilidad del cursor
    void setCursorVisible(bool isVisible) {
        // Se usan escape sequences para modificar la visibilidad del cursor
        print("\x1b[?25" + std::string(isVisible ? "h" : "l"));
    }

    //Obtiene la posicion del cursor donde se encuentra
    cine::coordXY getCursorPosition(){
        cine::coordXY coords;
        CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
        GetConsoleScreenBufferInfo(consoleHandle, &BufferInfo);
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
    void gotoxy(cine::coordXY pos){
        COORD cursorPosition = { short(pos.x), short(pos.y) };
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
    }

    //Mueve el cursor solo en el eje X
    void gotoX(short x){
        COORD cursorPosition = { x, short(cine::getCursorPosition().y) };
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
    }

    //Mueve el cursor en el eje Y
    void gotoY(short y){
        COORD cursorPosition = { short(cine::getCursorPosition().x), y};
        SetConsoleCursorPosition(consoleHandle, cursorPosition);
    }

    // Devuelve el tamaño de la consola (columns/filas) como vector 2d { x, y }
    cine::coordXY getConsoleSize() {
        cine::coordXY coords;
        CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
        GetConsoleScreenBufferInfo(consoleHandle, &BufferInfo);
        coords = { BufferInfo.dwSize.X, BufferInfo.dwSize.Y };

        return coords;
    }
    
    //Limpia la pantalla
    void clear(){
        system("cls");
    }

    // Imprime un texto multilinea de forma centrada en la consola
    void printRawCenter(std::string raw) {
        std::vector<std::string> subStringsList;
        std::string buffer = "";

        // Divide la cadena en subcadenas en función de los saltos de línea
        for (size_t i = 0; i < raw.length(); i++) {
            if (raw[i] != '\n' && i != raw.length() - 1) {
                buffer += raw[i];
            } else {
                if (buffer.empty() && subStringsList.empty()) {
                    // Si es la primera línea vacía, agrega espacios para centrarla
                    size_t consoleWidth = getConsoleSize().x;
                    size_t padding = (consoleWidth - buffer.length()) / 2;
                    buffer = std::string(padding, ' ') + buffer;
                }
                subStringsList.push_back(buffer);
                buffer = "";
            }
        }

        // Determina la longitud de la línea más larga
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
            cine::print(subStringsList[i] + "\n");
        }
    }
    
    //Obtiene la tecla presionado o en su efecto el caracter;
    int getch(){
        if (_kbhit()) {
        //primero obtenemos el caracter de control
        int control = _getch();
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
        }
        return 0;
    }

    //Imprime un marco
    void imprimirMarco(short ancho, short altura, coordXY coordenadas){
        gotoxy(coordenadas);
        for(short i=0;i<altura;i++){
            if(i==0){
                print(char(201));
                for(short j=0;j<ancho-2;j++){
                    print(char(205));
                }print(char(187));print('\n');
            }else if(i==altura-1){
                gotoX(coordenadas.x);
                print(char(200));
                for(short j=0;j<ancho-2;j++){
                    print(char(205));
                }print(char(188));
            }else{
            gotoX(coordenadas.x);
            print(char(186));
            gotoX(getCursorPosition().x+ancho-2);print(char(186));
            print('\n');
            }
        }
    }
    std::string lineaBlanca(getConsoleSize().x-1,'\xC4');
    std::string DobleLineaBlanca(getConsoleSize().x-1,'\xCD');
}//namespaces cine

