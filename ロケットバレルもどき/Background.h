#pragma once
#include"Startsetting.h"
class Background
{
public:
	Startsetting startsetting;

	void Init();
	void Draw();
	void Update();

	int handle1 = 0;
	float back1 = 0;
	float back2 = 0;

};