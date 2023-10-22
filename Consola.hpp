#pragma once
#include "funciones.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <string.h>

namespace cine{

    //Colores para el fondo
    enum ConsoleColor {
    Black = 0,
    Blue = BACKGROUND_BLUE,
    Green = BACKGROUND_GREEN,
    Red = BACKGROUND_RED,
    Intensity = BACKGROUND_INTENSITY
    };

    //Mueve la consola en eje X y Y
    void MoveWindow(int posx, int posy) 
    {
        RECT rectClient, rectWindow;
        HWND hWnd = GetConsoleWindow();
        GetClientRect(hWnd, &rectClient);
        GetWindowRect(hWnd, &rectWindow);
        MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
    }

    //Cambia el tamaño de la pantalla, Ancho y altura en pixeles. Tomar en cuenta para pantallas con menor resolucion
    void setConsoleSizeCenter(int ancho, int altura)
    {
        RECT rectClient, rectWindow;
        HWND hWnd = GetConsoleWindow();
        GetClientRect(hWnd, &rectClient);
        GetWindowRect(hWnd, &rectWindow);
        int posx, posy;
        posx = GetSystemMetrics(SM_CXSCREEN) / 2 - ancho / 2,
        posy = GetSystemMetrics(SM_CYSCREEN) / 2 - altura / 2,

        MoveWindow(hWnd, posx, posy, ancho, altura, TRUE);
    }






}// namespace cine