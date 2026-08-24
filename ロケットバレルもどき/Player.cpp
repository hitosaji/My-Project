#include "DxLib.h"
#include "player.h"
#include"startsetting.h"
#include"Config.h"

Player::Player()
{
    playerImg = LoadGraph("Picture/Player.png");//プレイヤー画像の読み込み
    // 初期位置を画面中央に設定（ウィンドウ高さ 440 の中央）
    y = 220.0f;
}
void Player::Update(bool isPlaying, float startY)
{
    // Update が呼ばれたことを示すフラグを立てる（Draw で表示する）
    updated = true;

    if (isPlaying)
    {
        // キー状態を取得して保存
        int key = CheckHitKey(KEY_INPUT_SPACE);
        lastKey = key;
        if (key)    // スペース押下中
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

     
        const float bottomAllowance = 8.0f; // 余裕ピクセル数
        const float maxY = 452 - 64 + bottomAllowance;
        if (y > maxY) // 下
        {
            y = maxY;
            if (vy > 0) vy = 0;
        }

        boxcolider.Update(120, (int)y + 10, 30, 35);
    }
    else
    {
        y = startY;
        int key = CheckHitKey(KEY_INPUT_SPACE);
        lastKey = key;
        if (key)      //キーの割り当て
        {
            y -= 1.0f; // 上に加速（ロケット推進）
        }
    }
}
void Player::Draw()
{
    int size = 64;      //プレイヤー画像の大きさ

    DrawExtendGraph(100, (int)y, 100 + size, (int)y + size, playerImg, TRUE);      //プレイヤー画像の描画

    /*DrawBox(
        boxcolider.x1,
        boxcolider.y1,
        boxcolider.x2,
        boxcolider.y2,
        GetColor(255, 255, 0),
        FALSE
    );*/

    // デバッグ表示: 位置と速度
    char buf[128];
    sprintf_s(buf, "y=%.2f vy=%.2f", y, vy);
    DrawString(10, 10, buf, GetColor(255, 255, 255));

    // Update 呼ばれたか表示
    char buf2[64];
    sprintf_s(buf2, "updated=%d", updated ? 1 : 0);
    DrawString(10, 30, buf2, GetColor(255, 255, 255));
    // 次フレームのためにリセット
    updated = false;

    // デバッグ: キー状態と定数表示
    char buf3[128];
    sprintf_s(buf3, "key=%d V=%.2f G=%.2f", lastKey, ConstNumber::PLAYER_V, ConstNumber::PLAYER_GRAVITY);
    DrawString(10, 50, buf3, GetColor(255, 255, 255));
}
