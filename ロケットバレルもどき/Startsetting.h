#pragma once
class Startsetting
{
public:
	Startsetting();


	void Update();
	void Reset(); // ゲームリセット用の関数を追加)

	int prev = 0;

	int pressCount = 0;
	bool isPlaying = false;

	float y = 220; // 初期待機位置を画面中央に設定 (ウィンドウ高さ 440 の中央)
	float vy = 0;
};