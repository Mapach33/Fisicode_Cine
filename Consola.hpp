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

    //Mostrar o no mostrar el cursor (parametro booleano)
    void ShowConsoleCursor(bool showFlag) {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    //Modifica el tamaño de la ventana e impide que el usuario la modifique
    void Set_Console_Sizes(int console_width, int console_height) {
        std::stringstream ss; ss << "MODE CON: COLS=" << console_width << "LINES=" << console_height;
        system(ss.str().c_str());

        double_line = std::string (console_width,'\xCD');
        single_line = std::string (console_width,'\xC4');

        HWND consoleWindow = GetConsoleWindow();
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        ShowConsoleCursor(0);
    }
    

    



}// namespace cine