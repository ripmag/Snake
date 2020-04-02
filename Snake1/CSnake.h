#pragma once
#include "CFigure.h"
#include "CDirection.h"
#include <conio.h>

class CSnake : public CFigure
{
public:
	CDirection direction = CDirection::down;

	CSnake()
	{// голову змеи в центр поля
		listPoints.push_back(CPoint(50, 25));
	}
	void Draw()
	{
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			SetDCBrushColor(hdc, RGB(0, 255, 255));
			if (it == listPoints.begin()) //рисуем голову
				Ellipse(hdc, it->x * scale, it->y * scale, it->x * scale + scale, it->y * scale + scale);
			else //рисуем змеиное тело
			{
				Rectangle(hdc, it->x * scale, it->y * scale, it->x * scale + scale, it->y * scale + scale);
			}
		}
	}
	void Move()
	{
		listPoints.push_front(GetNextStep());//просчёт следующего шага от направления
		Wipe(listPoints.back()); //затираем хвост
		listPoints.pop_back(); //удаляем координаты хвоста
		
	}
	bool Eat(CPoint food)
	{
		if (listPoints.front() == food)
		{//если попали на еду
			listPoints.push_front(GetNextStep());
			return true;
		}
		return false;
	}
	void ChangeDirection(char navigation)
	{

		switch (navigation)
		{
		case 'w':
			if(direction!= CDirection::down)
			direction = CDirection::up;
			break;
		case 's':
			if (direction != CDirection::up)
			direction = CDirection::down;
			break;
		case 'a':
			if (direction != CDirection::right)
			direction = CDirection::left;
			break;
		case 'd':
			if (direction != CDirection::left)
			direction = CDirection::right;
			break;
		default:
			break;
		}

	}
	bool IsEatSelf()
	{
		if (listPoints.size() > 4)
		{
			auto it = listPoints.begin(); it++;
			for (; it != listPoints.end(); ++it)
			{//голова попадает на хвост?
				if (*it == *listPoints.begin())
					return true;
			}
			return false;

		}
		return false;
	}
	bool IsOccupied(CPoint p) //территория занята телом змеи ?
	{
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			if (p == *it)
				return true;
		}
		return false;
	}
	CPoint GetNextStep()
	{//просчёт следующего шага (координаты)
		CPoint NextStep = listPoints.front();
		switch (direction)
		{
		case CDirection::up:
			NextStep.y--;
			break;
		case CDirection::down:
			NextStep.y++;
			break;
		case CDirection::left:
			NextStep.x--;
			break;
		case CDirection::right:
			NextStep.x++;
			break;
		}
		return (NextStep);
	}
	int Score()
	{
		return listPoints.size();
	}
};

