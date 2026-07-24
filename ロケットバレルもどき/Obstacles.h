#pragma once
#include"Startsetting.h"
#include"BoxColider.h"


class Obstacles
{
public:

	Startsetting startsetting;
	BoxColider box1;
	BoxColider box2;
	BoxColider box3;
	BoxColider box4;
	BoxColider box5;
	BoxColider box6;



	Obstacles(int x, int y);
	void Update();
	void Draw();
	void Init();

	int y;
	int x;
	int vy;
	int vx;
	int playerImg;

};