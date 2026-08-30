#pragma once
class Startsetting
{
public:
	Startsetting();
	~Startsetting(); // ← ここを追加


	void Update();   // 状態更新のみ
	void Draw();     // 描画をここに移動
	void Reset();


	int prev = 0;
	int pressCount = 0;
	bool isPlaying = false;

	float y = 220; // 初期待機位置を画面中央に設定 (ウィンドウ高さ 440 の中央)
	float vy = 0;

	// タイトルステージ: 0=タイトル画面, 1=説明画面, 2=ゲーム中
	int titleStage = 0;
	int titleImage = -1; // ハンドルは -1 で初期化
	int titleW = 0;
	int titleH = 0;
};