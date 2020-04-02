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
          CWall wals; //������� �����
          wals.Draw(); //������������ �����
          CSnake snake; //������� ����
          snake.Draw();
          CFood food; //������� ���
          food.Draw();
          while (true)
          {
              if (wals.IsCross(snake) || snake.IsEatSelf()) //���� ���� � ����� ��� ������� ���� ���� �� �����
              {
                  score = snake.Score(); //����
                  break;
              }
              if (_kbhit()) {
                  snake.ChangeDirection(_getch());//���������� ����
              }
              snake.Move();
              snake.Draw();
              wals.Draw();

              if (snake.Eat(food)) //���� ���� ����� ���
              {
                  food.CreateFood(); //��������� � ������������ ��� 
                  food.Draw();
              }

              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{1,26}); //������� ���� �� �����
              printf("Score:%d", snake.Score());

              Sleep(100);
          }
      }
};
