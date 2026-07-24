#include "DxLib.h"
#include <iostream>
#include "Startsetting.h"

Startsetting::Startsetting()
{
}

void Startsetting::Update()
{
    int now = CheckHitKey(KEY_INPUT_SPACE);

    if (now == 1 && prev == 0) // 押した瞬間
    {
        if (!isPlaying)
        {
            pressCount++;

            if (pressCount >= 3)
            {
                isPlaying = true; // ゲーム開始
            }
        }
    }
    if (isPlaying)
    {
        // 通常の処理
      // y += vy;
    }
    else
    {
        // 待機状態（固定）
        y = 200; // 中央に固定
        vy = 0;
    }

    if (!isPlaying)
    {
        DrawString(320, 330, "Three Space Presses to Start", GetColor(255, 255, 255));
    }
    prev = now;
}