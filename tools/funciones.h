#pragma once
#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string logo_fisicode = 
    R"( _____   ___   ____    ___    ____    ___    ____    _____ 
|  ___| |_ _| / ___|  |_ _|  / ___|  / _ \  |  _ \  | ____|
| |_     | |  \___ \   | |  | |     | | | | | | | | |  _|  
|  _|    | |   ___) |  | |  | |___  | |_| | | |_| | | |___ 
|_|     |___| |____/  |___|  \____|  \___/  |____/  |_____|)";

struct coordXY {
        int x;
        int y;
};

enum tecla {
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


void gotoxy(int x, int y) {
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hConsole, dwPos);
}

//Funcion para obtener el codigo de la tecla presionada
int getTecla(){
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
    return 0;
}

//Obtiene la posicion del cursor donde se encuentra
coordXY getCursorPosition(){
    coordXY coords;
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &BufferInfo);
    coords = { BufferInfo.dwCursorPosition.X, BufferInfo.dwCursorPosition.Y };
    return coords;
}

//Devuelve el tamano de la consola (columns/filas) como vector 2d { x, y }
coordXY getConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    coordXY coords;
    GetConsoleScreenBufferInfo(hConsole, &BufferInfo);
    coords = { BufferInfo.dwSize.X, BufferInfo.dwSize.Y };

    return coords;
}


//Mueve el cursor solo en el eje X
void gotoX(short x){
    COORD cursorPosition = { x, short(getCursorPosition().y) };
    SetConsoleCursorPosition(hConsole, cursorPosition);
}

//Mueve el cursor en el eje Y
void gotoY(short y){
    COORD cursorPosition = { short(getCursorPosition().x), y};
    SetConsoleCursorPosition(hConsole, cursorPosition);
}


void printRawCenter(string& raw) {
        SetConsoleTextAttribute(hConsole, 11); 
        vector<string> subStringsList;
        string buffer = "";

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
        for (string substr : subStringsList) {
            if (substr.length() >= biggestSlice) {
                biggestSlice = substr.length();
            }
        }

        // Calcula el desplazamiento horizontal
        int offset = (getConsoleSize().x)/2 - (biggestSlice / 2);
        // Imprime el texto centrado
        for (size_t i = 0; i < subStringsList.size(); i++) {
            gotoX(offset);
            cout<< subStringsList[i] << "\n";
        }
        SetConsoleTextAttribute(hConsole, 15);
}

    void CenterConsoleWindow();

    //Mostrar o no mostrar el cursor (parametro booleano)
    void ShowConsoleCursor(bool showFlag) {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    //Modifica el tamano de la ventana e impide que el usuario la modifique
    void Set_Console_Sizes(const int consola_ancho,const int consola_alto,bool cursor) {
        std::stringstream ss; ss << "MODE CON: COLS=" << consola_ancho << "LINES=" << consola_alto;
        system(ss.str().c_str());
        HWND consoleWindow = GetConsoleWindow();
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        CenterConsoleWindow();
        ShowConsoleCursor(cursor);
    }

    //Cetra la consola en la pantalla
    void CenterConsoleWindow() {
       RECT rectClient, rectWindow;
        HWND hWnd = GetConsoleWindow();
        GetClientRect(hWnd, &rectClient);
        GetWindowRect(hWnd, &rectWindow);
        int posx, posy;
        posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectClient.right - rectClient.left) / 2, 
        posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectClient.bottom - rectClient.top) / 2,

        MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
    }


//Retorna la fecha y hora actual
string obteneFechaHora() {
    SYSTEMTIME localTime; GetLocalTime(&localTime);
    stringstream ss; ss << localTime.wYear << "/" << localTime.wMonth << "/" << localTime.wDay;
    return ss.str();
}