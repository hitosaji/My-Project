#pragma once
#include "Startsetting.h"

class Background
{
public:
	Startsetting startsetting; // メインの Startsetting をコピーして使用します

	void Init();
	void Load();
	void Draw();
	// Update はフレーム番号を受け取り、同フレームで複数回呼ばれても1回だけ実行する
	void Update(int currentFrame);
	void End();

	int handle1 = 0;
	float back1 = 0;
	float back2 = 0;
	int lastUpdateFrame = -1; // 同一フレーム重複更新防止用

};
