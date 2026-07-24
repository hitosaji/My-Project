#pragma once
#include"Startsetting.h"
#include"BoxColider.h"
class Player
{
public:
	Player();
	Startsetting startsetting;
	BoxColider boxcolider;

	
	void Update();
	void Draw();


	int px = 0;
	int py = 0;


	float y = 0;
	float vy = 0;
	int playerImg;

	
};