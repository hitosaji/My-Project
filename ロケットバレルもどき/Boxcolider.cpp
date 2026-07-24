#include"DxLib.h"
#include"BoxColider.h"

void BoxColider::Update(int x, int y, int w, int h)
{
    x1 = x;
    y1 = y;
    x2 = x + w;
    y2 = y + h;
}