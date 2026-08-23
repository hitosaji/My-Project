#include "DxLib.h"
#include "background.h"
#include "Config.h"

void Background::Init()
{
    // 画像読み込み
    handle1 = LoadGraph("Picture/perfect_loop1.bmp");

    back1 = ConstNumber::BACKGROUND_1;
    back2 = ConstNumber::BACKGROUND_2; // 予め2枚分の位置を用意
}

void Background::Update(int currentFrame)
{
    // 同一フレームで複数回呼ばれた場合は最初の一回だけ処理する
    if (lastUpdateFrame == currentFrame) return;
    lastUpdateFrame = currentFrame;

    // 起動直後から背景をスクロールする
    back1 -= ConstNumber::BACKGROUND_SPEED;
    back2 -= ConstNumber::BACKGROUND_SPEED;

    // ループ処理（画像幅に依存）
    if (back1 <= -2172) back1 = back2 + 2172;
    if (back2 <= -2172) back2 = back1 + 2172;
}

void Background::Draw()
{
    // 背景画像の描画
    DrawGraph((int)back1, 0, handle1, TRUE);
    DrawGraph((int)back2, 0, handle1, TRUE);
}
