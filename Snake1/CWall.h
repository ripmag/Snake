#pragma once
#include "CFigure.h"
class CWall : public CFigure
{
public:
	CWall(int widht=100, int hight=50)
	{//рисуем 4 стены
		for (int x = 0;x < widht+1;x++)
		{
			listPoints.push_back(CPoint(x, 0));
			listPoints.push_back(CPoint(x, hight));
		}
		for (int y = 0;y < hight;y++)
		{
			listPoints.push_back(CPoint(0, y));
			listPoints.push_back(CPoint(widht, y));
		}

	}
	bool IsCross(CFigure figure)
	{//проверка на пересечение
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			if (figure.IsCross(*it))
				return true;
		}
		return false;
	}
};

