#pragma once
class BoxColider
{
public:

	void Update(int x, int y, int w, int h);

	bool CheckOverlap(const BoxColider& other)const
	{
		if ((x2 < other.x1) || (x1 > other.x2) || (y2 < other.y1) || (y1 > other.y2))
		{
			return false;
		}
		return true;
	}

	int x1;
	int y1;
	int x2;
	int y2;

};