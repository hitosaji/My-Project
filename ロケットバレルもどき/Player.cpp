#include "DxLib.h"
#include "player.h"
#include"startsetting.h"

Player::Player()
{
    playerImg = LoadGraph("Picture/Player.png");//プレイヤー画像の読み込み
    // 初期位置を画面中央に設定（ウィンドウ高さ 440 の中央）
    y = 220.0f;
}
void Player::Update(bool isPlaying, float startY)
{
    if (isPlaying)
    {
        if (CheckHitKey(KEY_INPUT_SPACE))    //キーの割り当て
        {
            vy -= ConstNumber::PLAYER_V;    // 上に加速（ロケット推進）
        }
        vy += ConstNumber::PLAYER_GRAVITY;     // 重力

        y += vy;      // 位置更新

        // 画面外に出ないように制限
        if (y < ConstNumber::PLAYER_LANDSCAPE_UP)      // 上
        {
            y = 0.0f;
            vy = 2.0f;
        }

        // 下端は完全には固定せず、少しめり込める余裕を与える
        // これにより「少しめり込み始める」タイミングでゲームオーバー判定を出せる
        const float bottomAllowance = 8.0f; // 余裕ピクセル数
        const float maxY = 440 - 64 + bottomAllowance;
        if (y > maxY) // 下
        {
            y = maxY;
            if (vy > 0) vy = 0;
        }

        boxcolider.Update(120, (int)y + 10, 40, 45);
    }
    else
    {
        y = startY;
        if (CheckHitKey(KEY_INPUT_SPACE))      //キーの割り当て
        {
            y -= 1.0f; // 上に加速（ロケット推進）
        }
    }
}
void Player::Draw()
{
    int size = 64;      //プレイヤー画像の大きさ

    DrawExtendGraph(100, (int)y, 100 + size, (int)y + size, playerImg, TRUE);      //プレイヤー画像の描画

    DrawBox(
        boxcolider.x1,
        boxcolider.y1,
        boxcolider.x2,
        boxcolider.y2,
        GetColor(255, 255, 0),
        FALSE
    );
}
