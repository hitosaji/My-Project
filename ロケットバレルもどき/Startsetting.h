#pragma once
class Startsetting
{
public:
	Startsetting();


	void Update();

	int prev = 0;

	int pressCount = 0;
	bool isPlaying = false;

	float y = 0;
	float vy = 0;
};