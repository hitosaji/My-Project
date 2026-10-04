#include "DxLib.h"
#include "Startsetting.h"
#include<iostream>

Startsetting::Startsetting()
{
}

void Startsetting::Reset()
{
	
	isPlaying = false;
	y = 220;
	vy = 0;

	pressCount = 0;
	prev = 0;
}

void Startsetting::Update()
{
	int now = CheckHitKey(KEY_INPUT_SPACE);

	// SPACEを押した瞬間だけカウント
	if (now && !prev)
	{
		pressCount++;

		// 3回押したらゲーム開始
		if (pressCount >= 3)
		{
			isPlaying = true;
		}
	}

	// 状態更新のみ（描画は Draw() に移動）
	y = isPlaying ? y : 220;
	vy = isPlaying ? vy : 0;

	prev = now;
}

void Startsetting::Draw()
{
	if (!isPlaying)
	{
		char buf[16];
		sprintf_s(buf, "%d", 3 - pressCount);

		DrawExtendString(240, 35, 25.0f, 25.0f, buf, GetColor(0, 0, 0));
	}
}
	
