#pragma once
class CPoint
{
public:
	int x;
	int y;
	virtual void Draw()
	{
		
	};
	virtual bool IsCross(CPoint point)
	{
		if ((point.x == this->x) && (point.y == this->y))
			return true;
		return false;
	}

};

