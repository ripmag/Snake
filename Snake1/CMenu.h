#pragma once
#include <windows.h>
#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
class CMenu
{
public:
	
	CMenu()
	{
		system("cls"); //очищаем экран и выводим меню
		cout << "Start Menu\nFor start the game press Enter\n";
		cout << "press Q and Enter for exit\n";
	}
	void GameOver(int score)
	{
		system("cls");
		cout << "QAME OVER!\nYour SCORE="<< score <<"\nFor start the game press Enter\n";
		cout << "press Q and Enter for exit\n";
		
	}
	bool StartGame()
	{
		char input;
		cin.get(input);
		switch (input)
		{
		case 'q':
		case 'Q':
			system("cls");
			return false;
		default:
			system("cls");
			return true;
			break;
		}
	}

};

