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
	BoxColider box7;
	BoxColider box8;
	BoxColider box9;
	BoxColider box10;
	BoxColider box11;
	BoxColider box12;
	BoxColider box13;
	BoxColider box14;
	BoxColider box15;
	BoxColider box16;
	BoxColider box17;
	BoxColider box18;



	Obstacles(int x, int y);
	void Update(bool isPlaying);
	void Draw();
	void Init();

	int y;
	int x;
	float vy;
	int vx;
	int playerImg;
	int player_Life=3;

};