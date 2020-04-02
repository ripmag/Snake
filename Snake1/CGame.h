#pragma once
#include <iostream>
#include <windows.h>
#include "CFigure.h"
#include "CWall.h"
#include "CSnake.h"
#include "CFood.h"
#include "CMenu.h"
class CGame
{
public: int score = 0;

      void Start()
      {
          CWall wals; //создаеём стены
          wals.Draw(); //отрисовываем стены
          CSnake snake; //создаем змею
          snake.Draw();
          CFood food; //создаем еду
          food.Draw();
          while (true)
          {
              if (wals.IsCross(snake) || snake.IsEatSelf()) //если змея в стене или укусила сама себя то конец
              {
                  score = snake.Score(); //счёт
                  break;
              }
              if (_kbhit()) {
                  snake.ChangeDirection(_getch());//управление змеёй
              }
              snake.Move();
              snake.Draw();
              wals.Draw();

              if (snake.Eat(food)) //если змея съела еду
              {
                  food.CreateFood(); //добавляем и отрисовываем ещё 
                  food.Draw();
              }

              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{1,26}); //выводим счёт на экран
              printf("Score:%d", snake.Score());

              Sleep(100);
          }
      }
};
