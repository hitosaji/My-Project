#include "DxLib.h"
#include "player.h"
#include "background.h"
#include "obstacles.h"
#include "Startsetting.h"
#include <vector>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(FALSE);
    SetGraphMode(640, 440, 32);

    if (DxLib_Init() == -1)
        return -1;

    SetDrawScreen(DX_SCREEN_BACK);

    // オブジェクト
    Startsetting startsetting;
    Player player;

    Background background;
    background.Init();

    // サウンド準備
    int explosionSound1 = -1;
	int explosionSound2 = 0;
    bool waitingExplosion = false; // 爆発音再生中フラグ
   
    explosionSound1 = LoadSoundMem("Sound/explosion.mp3");
    explosionSound2 = LoadSoundMem("Sound/Music.mp3");
    //BGM再生フラグ
    bool playingBgm = false;

    std::vector<Obstacles> allObstacles;

    //上部参考値(X,-1100)
    //中部参考値(X,-30)
    //下部参考値(X,50)

    /*allObstacles.push_back(Obstacles(100, -700));*/
    allObstacles.push_back(Obstacles(200, -1100));
    allObstacles.push_back(Obstacles(640, 0));
    allObstacles.push_back(Obstacles(1000, 100));
    allObstacles.push_back(Obstacles(900, -1100));
    allObstacles.push_back(Obstacles(940, -1130));
    allObstacles.push_back(Obstacles(980, -1150));
    allObstacles.push_back(Obstacles(1500, -50));
    allObstacles.push_back(Obstacles(1800, -1160));
    allObstacles.push_back(Obstacles(1950, -1000));
    allObstacles.push_back(Obstacles(2300, 70));
    allObstacles.push_back(Obstacles(2600, -100));
    allObstacles.push_back(Obstacles(2700, -60));
    allObstacles.push_back(Obstacles(2800, -20));
    allObstacles.push_back(Obstacles(2900, 20));
    allObstacles.push_back(Obstacles(3000, -1120));
    allObstacles.push_back(Obstacles(3050, -1090));
    allObstacles.push_back(Obstacles(3400, -10)); 
    allObstacles.push_back(Obstacles(3700, -60));
    allObstacles.push_back(Obstacles(4050, -920));
    allObstacles.push_back(Obstacles(4500, -60));
    allObstacles.push_back(Obstacles(4550, -150));
    allObstacles.push_back(Obstacles(4870, -1100));
    allObstacles.push_back(Obstacles(5100, -60));
    allObstacles.push_back(Obstacles(5400, -1050));
    allObstacles.push_back(Obstacles(5430, -1000));
    allObstacles.push_back(Obstacles(5460, -950));
    allObstacles.push_back(Obstacles(5490, -900));
    allObstacles.push_back(Obstacles(5800, 90));
    allObstacles.push_back(Obstacles(5840, 50));
    allObstacles.push_back(Obstacles(5880, 0));
    allObstacles.push_back(Obstacles(5920, -40));
    allObstacles.push_back(Obstacles(5960, -80));
    allObstacles.push_back(Obstacles(6000, -130));














    

    // ゲーム状態
    bool gameOver = false;
    bool dead = false;
    int playerLife = 3;
    int frameCounter = 0;

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        // ========================================
        // 更新処理
        // ========================================

        // スタート処理はMainで1回だけ
        startsetting.Update();

        // BGM 再生管理: ゲーム中のみループ再生、ゲームオーバー/爆発再生中は停止
        if (!gameOver && !waitingExplosion && startsetting.isPlaying == TRUE)
        {
            if (!playingBgm && explosionSound2 != -1)
            {
                PlaySoundMem(explosionSound2, DX_PLAYTYPE_LOOP);
                playingBgm = true;
            }
        }
        else
        {
            if (playingBgm && explosionSound2 != -1)
            {
                StopSoundMem(explosionSound2);
                playingBgm = false;
            }
        }
        // 爆発音再生中はゲーム進行を一時停止し、音の終了でゲームオーバーにする
        if (waitingExplosion)
        {
            if (explosionSound1 != -1)
            {
                // CheckSoundMem: 0 = 停止, 1 = 再生中
                if (CheckSoundMem(explosionSound1) == 0)
                {
                    gameOver = true;
                    waitingExplosion = false;
                }
            }
            else
            {
                gameOver = true;
                waitingExplosion = false;
            }
        }
        else if (!gameOver)
        {
            if (startsetting.isPlaying == TRUE)
            {
                // プレイヤー更新
                player.Update(startsetting.isPlaying, startsetting.y);

                // 画面下端にめり込み始めたらダメージ扱いにする
                if (player.y > 440 - 64)
                {
                    dead = true;
                }

                // 背景更新
                background.Update(frameCounter);

                // 障害物更新
                for (int i = 0; i < allObstacles.size(); i++)
                {
                    allObstacles[i].Update(startsetting.isPlaying);

                     //当たり判定
                    if (player.boxcolider.CheckOverlap(allObstacles[i].box1) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box2) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box3) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box4) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box5) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box6) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box7) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box8) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box9) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box10) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box11) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box12) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box13) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box14) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box15) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box16) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box17) ||
                        player.boxcolider.CheckOverlap(allObstacles[i].box18))
                    {
                        dead = true;
                        break;
                    }     
                }

                // ========================================
                // プレイヤーが死亡した場合
                // ========================================

                if (dead)
                {
                    playerLife--;
                    dead = false;

                    if (playerLife <= 0)
                    {
                        // 最終ライフで爆発音を鳴らす
                        if (explosionSound1 != -1)
                        {
                            // BGM を止めて爆発音再生
                            if (playingBgm && explosionSound2 != -1)
                            {
                                StopSoundMem(explosionSound2);
                                playingBgm = false;
                            }
                            PlaySoundMem(explosionSound1, DX_PLAYTYPE_BACK);
                            waitingExplosion = true;
                        }
                        else
                        {
                            gameOver = true;
                        }
                    }
                }
            }
        }

        // ========================================
        // 描画処理
        // ========================================

        background.Draw();

        for (int i = 0; i < allObstacles.size(); i++)
        {
            allObstacles[i].Draw();
        }

        player.Draw();

        // ゲームオーバー表示
        if (gameOver)
        {
            DrawString(
                250,
                200,
                "GAME OVER",
                GetColor(255, 0, 0)
            );
        }

        // ゲーム画面の枠
        DrawBox(
            0,
            0,
            640,
            440,
            GetColor(255, 255, 255),
            FALSE
        );

        ScreenFlip();
        frameCounter++;
    }

    DxLib_End();
    // サウンド解放
    if (explosionSound1 != -1) {
        StopSoundMem(explosionSound1);
        DeleteSoundMem(explosionSound1);
    }
    if (explosionSound2 != -1) {
        StopSoundMem(explosionSound2);
        DeleteSoundMem(explosionSound2);
    }

    return 0;
}