// Snake1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include "CGame.h"

int main()
{
    CMenu menu;//класс меню
    while (menu.StartGame())
    {
        CGame game;//основной класс игры
        game.Start();
        menu.GameOver(game.score);
    }
    return 0;
}