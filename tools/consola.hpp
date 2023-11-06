#pragma once
#include "funciones.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <string.h>
namespace cine{
    
    std::string double_line;
    std::string single_line;

    //Colores para el fondo
    enum ConsoleColor {
    Black = 0,
    Blue = BACKGROUND_BLUE,
    Green = BACKGROUND_GREEN,
    Red = BACKGROUND_RED,
    Intensity = BACKGROUND_INTENSITY
    };

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

    //Mostrar o no mostrar el cursor (parametro booleano)
    void ShowConsoleCursor(bool showFlag) {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    //Modifica el tamaño de la ventana e impide que el usuario la modifique
    void Set_Console_Sizes(const int consola_ancho,const int consola_alto,bool cursor) {
        std::stringstream ss; ss << "MODE CON: COLS=" << consola_ancho << "LINES=" << consola_alto;
        system(ss.str().c_str());

        double_line = std::string (consola_ancho,'\xCD');
        single_line = std::string (consola_ancho,'\xC4');

        HWND consoleWindow = GetConsoleWindow();
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        CenterConsoleWindow();
        ShowConsoleCursor(cursor);
    }
    
}// namespace cine