#pragma once
#include "CFigure.h"
class CFood : public CFigure
{
public:

	CFood()
	{
		CreateFood();//� ������������ ������ ��� � ������������ ����� �� ����
	}
	CPoint CreateFood(int widht = 100,int heght = 50)
	{		
			x = rand() % (widht - 2) + 1;
			y = rand() % (heght - 2) + 1;
			return CPoint(x, y);
	}
	CPoint GetPoint()
	{
		return CPoint(x, y);
	}
	void Draw()
	{
		//��� ������ � ���� �������� ����� (�������� ������ :) )
		SetDCBrushColor(hdc, RGB(255, 0, 0));
		Ellipse(hdc,
			x * scale,
			y * scale,
			x * scale + scale,
			y * scale + scale);
	}

};

