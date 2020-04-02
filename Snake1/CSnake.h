#pragma once
#include "CFigure.h"
#include "CDirection.h"
#include <conio.h>

class CSnake : public CFigure
{
public:
	CDirection direction = CDirection::down;

	CSnake()
	{// ������ ���� � ����� ����
		listPoints.push_back(CPoint(50, 25));
	}
	void Draw()
	{
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			SetDCBrushColor(hdc, RGB(0, 255, 255));
			if (it == listPoints.begin()) //������ ������
				Ellipse(hdc, it->x * scale, it->y * scale, it->x * scale + scale, it->y * scale + scale);
			else //������ ������� ����
			{
				Rectangle(hdc, it->x * scale, it->y * scale, it->x * scale + scale, it->y * scale + scale);
			}
		}
	}
	void Move()
	{
		listPoints.push_front(GetNextStep());//������� ���������� ���� �� �����������
		Wipe(listPoints.back()); //�������� �����
		listPoints.pop_back(); //������� ���������� ������
		
	}
	bool Eat(CPoint food)
	{
		if (listPoints.front() == food)
		{//���� ������ �� ���
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
			{//������ �������� �� �����?
				if (*it == *listPoints.begin())
					return true;
			}
			return false;

		}
		return false;
	}
	bool IsOccupied(CPoint p) //���������� ������ ����� ���� ?
	{
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			if (p == *it)
				return true;
		}
		return false;
	}
	CPoint GetNextStep()
	{//������� ���������� ���� (����������)
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

