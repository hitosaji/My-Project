#include "DxLib.h"
#include "obstacles.h"
#include"startsetting.h"
#include"BoxColider.h"

Obstacles::Obstacles(int initialX, int initialY)
{
	playerImg = LoadGraph("Picture/obstacles2.png");

	x = initialX;
	y = initialY;

	vx = -2;
	vy = 0;

}
void Obstacles::Init()
{
}
void Obstacles::Update()
{
	startsetting.Update();
	startsetting.isPlaying;

	if (startsetting.isPlaying == TRUE)
	{
		y += vy;
		x += vx;
	}

	// �����蔻��p�ɍX�V�i�摜�T�C�Y�ɍ��킹�Ē������Ă��������j
	// ��
	box1.Update(x+310, y + 250 , 300, 100);

	// �^��
	box2.Update(x + 300, y + 280, 345, 100);

	// ��
	box3.Update(x + 239, y + 320, 450, 95);


	box4.Update(x + 260, y + 380, 200, 95);


	box5.Update(x + 280, y + 440, 200, 150);


	box6.Update(x + 290, y + 600, 200, 95);
}

void Obstacles::Draw()
{
	float size = 0.9f;

	DrawRotaGraph3(x, y, 0, 0, size, size, 0, playerImg, TRUE, TRUE);

	//当たり判定の位置
	DrawBox(box1.x1, box1.y1, box1.x2, box1.y2, GetColor(255, 0, 0), FALSE);   // 赤
	DrawBox(box2.x1, box2.y1, box2.x2, box2.y2, GetColor(0, 255, 0), FALSE);   // 緑
	DrawBox(box3.x1, box3.y1, box3.x2, box3.y2, GetColor(0, 0, 255), FALSE);   // 青 
	DrawBox(box4.x1, box4.y1, box4.x2, box4.y2, GetColor(0, 255, 255), FALSE); // シアン
	DrawBox(box5.x1, box5.y1, box5.x2, box5.y2, GetColor(255, 0, 255), FALSE); // マゼンタ
	DrawBox(box6.x1, box6.y1, box6.x2, box6.y2, GetColor(255, 255, 0), FALSE); // 黄

}