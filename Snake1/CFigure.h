#pragma once
#include <list>
#include <windows.h>
#include <atltypes.h>

using namespace std;
class CFigure : public CPoint
{
public:
	HDC hdc;
	int const scale = 8; //для масштаба
	list <CPoint> listPoints; //набор точек фигуры

	CFigure()
	{
		hdc = GetDC(GetConsoleWindow());
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, RGB(0, 255, 0));
	}

	virtual void Draw()
	{//отрисовка всех точек фигуры
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{		
			Rectangle(hdc, it->x * scale  , it->y * scale  , it->x * scale + scale , it->y * scale + scale );	
		}
	}
	virtual void Wipe(CPoint pixel)
	{//затирание "пикселя"
		SelectObject(hdc, GetStockObject(DC_BRUSH));		
		SetDCBrushColor(hdc, RGB(0, 0, 0));		
		Rectangle(hdc, pixel.x * scale, pixel.y * scale, pixel.x * scale + scale , pixel.y * scale + scale );		
	}
	bool IsCross(CFigure figure)
	{//пересечение с фигурой
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			if (figure.IsCross(*it))
				return true;
		}
		return false;
	}
	
	bool IsCross(CPoint point)
	{//пересечение с точкой
		for (auto it = listPoints.begin(); it != listPoints.end(); ++it)
		{
			if ((point.x == it->x) && (point.y == it->y))
				return true;
		}
		return false;	
	}
};

