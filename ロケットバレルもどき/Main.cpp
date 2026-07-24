#include "DxLib.h"
#include "player.h"
#include"background.h"
#include"obstacles.h"
#include <vector>
#include"GameState.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);// ウィンドウモード
    SetGraphMode(640, 440, 32);
    DxLib_Init();           // DxLib初期化 
    SetDrawScreen(DX_SCREEN_BACK);
    if (DxLib_Init() == -1) return -1;

    Player player;
   
    Background background;
    background.Init();

    std::vector<Obstacles> allObstacles;
    allObstacles.push_back(Obstacles(640, 0));
    allObstacles.push_back(Obstacles(1000, 100));
    allObstacles.push_back(Obstacles(1500, -50));
    allObstacles.push_back(Obstacles(2300, 70));
    allObstacles.push_back(Obstacles(2600, 50));
    allObstacles.push_back(Obstacles(2700, 25));
   /* allObstacles.push_back(Obstacles(300, -250));*/  //確認用

    bool gameOver = false;
	bool Dead = false;
    int playerLife = 3; // プレイヤーのライフを3に設定

    while (ProcessMessage() == 0)
    {
        // 描画 
        ClearDrawScreen();

        if (!gameOver)
        {
            background.Update();
            player.Update();


            for (int i = 0; i < allObstacles.size(); i++)
            {
                allObstacles[i].Update();

                if (player.boxcolider.CheckOverlap(allObstacles[i].box1) ||
                    player.boxcolider.CheckOverlap(allObstacles[i].box2) ||
                    player.boxcolider.CheckOverlap(allObstacles[i].box3) ||
                    player.boxcolider.CheckOverlap(allObstacles[i].box4) ||
                    player.boxcolider.CheckOverlap(allObstacles[i].box5) ||
                    player.boxcolider.CheckOverlap(allObstacles[i].box6))
                {
                    Dead = true;
                    break;
                }
                else if (Dead)
                {
                    playerLife--;
                    Dead = false;
                    break;
                }
		        else if (playerLife <= 0)
                {
                 DrawString(200, 200, "Game Over", GetColor(255, 0, 0));
                    gameOver = true;
                }
            }
        
        }
        
        
  
        background.Draw();

       

        for (int i = 0; i < allObstacles.size(); i++)
        {
            allObstacles[i].Draw();
        }

        player.Draw();


        if (gameOver)
        {
            DrawString(250, 200, "GAME OVER", GetColor(255, 0, 0));
        }

       
       
        DrawBox(0, 0, 640, 440, GetColor(255, 255, 255), FALSE); //ゲーム画面の枠



        ScreenFlip();
    }

    DxLib_End();
    return 0;
}