#include "DxLib.h"
#include "player.h"
#include"startsetting.h"
#include"Config.h"

Player::Player()
{
    playerImg = LoadGraph("Picture/Player.png");//プレイヤー画像の読み込み
}
void Player::Update()
{
    startsetting.Update();
    startsetting.isPlaying;

    if (startsetting.isPlaying == TRUE)
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

        if (y > 480 - 64)      // 下
        {
            y = 480 - 64;
            if (vy > 0) vy = 0;
        } 
     boxcolider.Update(120 , (int)y+10, 40, 45);
    }
    else
    {
        y = startsetting.y;
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