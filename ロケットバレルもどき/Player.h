 #pragma once
#include "BoxColider.h"

class Player
{
public:
    Player();
    BoxColider boxcolider;

    // 外部の再生フラグと開始Yを受け取る
    void Update(bool isPlaying, float startY, bool acceptInput, float deltaTime);
    void Draw();

    int px = 0;
    int py = 0;

    float y = 0;
    float vy = 0;
    int playerImg;
    int score = 0;
	int playerLife = 3; // プレイヤーのライフ数
    bool updated = false; // Update が呼ばれたかのフラグ（デバッグ）
    int lastKey = 0; // 最後のキー状態を保持（デバッグ）
};