#include "DxLib.h"
#include "Startsetting.h"

Startsetting::Startsetting()
{
	titleStage = 0;
	titleImage = LoadGraph("Picture/Perilous Journey.png"); // 実行ファイルからの相対パス
	if (titleImage != -1) {
		GetGraphSize(titleImage, &titleW, &titleH);
	}
	else {
		titleW = titleH = 0;
	}
}

Startsetting::~Startsetting()
{
	if (titleImage != -1) {
		DeleteGraph(titleImage);
	}
}

void Startsetting::Reset()
{
	pressCount = 0;
	prev = 0;
	isPlaying = false;
	y = 220;
	vy = 0;
	titleStage = 0;
}

void Startsetting::Update()
{
	int now = CheckHitKey(KEY_INPUT_SPACE);

	if (now == 1 && prev == 0) {
		if (!isPlaying) {
			if (titleStage == 0) titleStage = 1;
			else if (titleStage == 1) { isPlaying = true; titleStage = 2; }
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
		if (titleStage == 0)
		{
			if (titleImage != -1 && titleW > 0 && titleH > 0)
			{
				int x = (640 - titleW) / 2;
				int y0 = (440 - titleH) / 2;
				DrawGraph(640, 440, titleImage, TRUE);
			}
			else
			{
				DrawString(160, 120, "ロケットバレルもどき", GetColor(255, 220, 80));
				DrawString(220, 200, "スペースキーで次に進む", GetColor(255, 255, 255));
			}
		}
		else if (titleStage == 1)
		{
			// 背景を黒にする
			DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
			DrawString(100, 330, "このゲームはスペースキーだけ使います", GetColor(255, 255, 255));
		}
	}
}
	
