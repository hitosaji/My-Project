#include "DxLib.h"
#include "obstacles.h"
#include"startsetting.h"
#include"BoxColider.h"

int Obstacles::playerImg = -1;

Obstacles::Obstacles(int initialX, int initialY)
{
	if (playerImg == -1)
	{
		playerImg = LoadGraph("Picture/obstacles2.png");
	}

	x = initialX;
	y = initialY;

	vx = -2.0f;
	vy = 0.0f;

}

void Obstacles::Init()
{
}
void Obstacles::Update(bool isPlaying)
{
	if (isPlaying)
	{
		y += vy;
		x += vx;
	}

	
	box1.Update(x+310, y + 250 , 285, 120);

	box2.Update(x + 300, y + 280, 345, 100);

	box3.Update(x + 239, y + 320, 425, 95);

	box4.Update(x + 260, y + 380, 200, 95);

	box5.Update(x + 280, y + 440, 200, 150);

	box6.Update(x + 290, y + 600, 200, 95);

	box7.Update(x + 305, y + 650, 200, 95);

	box8.Update(x + 320, y + 700, 200, 95);

	box9.Update(x + 345, y + 780, 200, 95);

	box10.Update(x + 357, y + 820, 200, 95);

	box11.Update(x + 368, y + 860, 185, 95);

	box12.Update(x + 378, y + 900, 150, 95);

	box13.Update(x + 400, y + 940, 120, 95);

	box14.Update(x + 415, y + 980, 90, 95);

	box15.Update(x + 430, y + 1020, 70, 95);

	box16.Update(x + 440, y + 1050, 50, 95);

	box17.Update(x + 448, y + 1080, 30, 95);

	box18.Update(x + 450, y + 1110, 15, 95);



}

void Obstacles::Draw()
{

	float size = 0.9f;

	DrawRotaGraph3(x, y, 0, 0, size, size, 0, playerImg, TRUE, TRUE);

	//当たり判定の位置
	
	//DrawBox(box1.x1, box1.y1, box1.x2, box1.y2, GetColor(255, 0, 0), FALSE);   // 赤
	//DrawBox(box2.x1, box2.y1, box2.x2, box2.y2, GetColor(0, 255, 0), FALSE);   // 緑
	//DrawBox(box3.x1, box3.y1, box3.x2, box3.y2, GetColor(0, 0, 255), FALSE);   // 青 
	//DrawBox(box4.x1, box4.y1, box4.x2, box4.y2, GetColor(0, 255, 255), FALSE); // シアン
	//DrawBox(box5.x1, box5.y1, box5.x2, box5.y2, GetColor(255, 0, 255), FALSE); // マゼンタ
	//DrawBox(box6.x1, box6.y1, box6.x2, box6.y2, GetColor(255, 255, 0), FALSE); // 黄
	//DrawBox(box7.x1, box7.y1, box7.x2, box7.y2, GetColor(125, 255, 255), FALSE); // 白
	//DrawBox(box8.x1, box8.y1, box8.x2, box8.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box9.x1, box9.y1, box9.x2, box9.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box10.x1, box10.y1, box10.x2, box10.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box11.x1, box11.y1, box11.x2, box11.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box12.x1, box12.y1, box12.x2, box12.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box13.x1, box13.y1, box13.x2, box13.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box14.x1, box14.y1, box14.x2, box14.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box15.x1, box15.y1, box15.x2, box15.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box16.x1, box16.y1, box16.x2, box16.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box17.x1, box17.y1, box17.x2, box17.y2, GetColor(255, 255, 255), FALSE); // 白
	//DrawBox(box18.x1, box18.y1, box18.x2, box18.y2, GetColor(255, 255, 255), FALSE); // 白 
	
}