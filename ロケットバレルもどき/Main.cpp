#include "DxLib.h"
#include "player.h"
#include "background.h"
#include "obstacles.h"
#include "Startsetting.h"
#include"GameState.h"
#include <vector>

// 障害物初期化関数
void PopulateObstacles(std::vector<Obstacles>& allObstacles)
{
    allObstacles.clear();
    allObstacles.push_back(Obstacles(200, -1100));
    allObstacles.push_back(Obstacles(640, 0));
    allObstacles.push_back(Obstacles(900, -1100));
    allObstacles.push_back(Obstacles(940, -1130));
    allObstacles.push_back(Obstacles(980, -1150));
    allObstacles.push_back(Obstacles(1000, 100));
    allObstacles.push_back(Obstacles(1500, -50));
    allObstacles.push_back(Obstacles(1800, -1160));
    allObstacles.push_back(Obstacles(1950, -1000));
    allObstacles.push_back(Obstacles(2300, 70));
    allObstacles.push_back(Obstacles(2600, -70));
    allObstacles.push_back(Obstacles(2700, -50));
    allObstacles.push_back(Obstacles(2800, -10));
    allObstacles.push_back(Obstacles(2900, 30));
    allObstacles.push_back(Obstacles(3000, -1120));
    allObstacles.push_back(Obstacles(3050, -1090));
    allObstacles.push_back(Obstacles(3400, -10)); 
    allObstacles.push_back(Obstacles(3700, -60));
    allObstacles.push_back(Obstacles(4080, -1000));
    allObstacles.push_back(Obstacles(4500, -40));
    allObstacles.push_back(Obstacles(4550, -70));
    allObstacles.push_back(Obstacles(4900, -1100));
    allObstacles.push_back(Obstacles(5100, -30));
    //階段
    allObstacles.push_back(Obstacles(5400, -1050));
    allObstacles.push_back(Obstacles(5430, -1000));
    allObstacles.push_back(Obstacles(5460, -1050));
    allObstacles.push_back(Obstacles(5490, -1100));
    allObstacles.push_back(Obstacles(5780, -1130));
    allObstacles.push_back(Obstacles(5800, 50));
    allObstacles.push_back(Obstacles(5840, 30));
    allObstacles.push_back(Obstacles(5880, 0));
    allObstacles.push_back(Obstacles(5920, -40));
    allObstacles.push_back(Obstacles(5960, -80));
    allObstacles.push_back(Obstacles(6400, -1130));
    allObstacles.push_back(Obstacles(6500, -20));
    allObstacles.push_back(Obstacles(6800, -1080));
    allObstacles.push_back(Obstacles(7000, -30));
    allObstacles.push_back(Obstacles(7100, -1170));
    allObstacles.push_back(Obstacles(7200, 10));
    allObstacles.push_back(Obstacles(7320, -1120));
    allObstacles.push_back(Obstacles(7400, -1100));
    allObstacles.push_back(Obstacles(7700, -30));
    allObstacles.push_back(Obstacles(7900, -1130));
    allObstacles.push_back(Obstacles(8100, -1150));
    allObstacles.push_back(Obstacles(8200, -10));
    allObstacles.push_back(Obstacles(8300, -1110));
    allObstacles.push_back(Obstacles(8450, -1130));
    allObstacles.push_back(Obstacles(8500, -20));
    allObstacles.push_back(Obstacles(8650, 100));
    allObstacles.push_back(Obstacles(8800, -1000));
    allObstacles.push_back(Obstacles(8870, -970));
    allObstacles.push_back(Obstacles(8970, -970));
    allObstacles.push_back(Obstacles(9070, -930));
    allObstacles.push_back(Obstacles(9180, 180));
    allObstacles.push_back(Obstacles(9170, -950));
    allObstacles.push_back(Obstacles(9200, 170));
    allObstacles.push_back(Obstacles(9270, -1000));
    allObstacles.push_back(Obstacles(9300, 150));
    allObstacles.push_back(Obstacles(9400, 80));
    allObstacles.push_back(Obstacles(9580, -40));
    allObstacles.push_back(Obstacles(9900, -1010));
    allObstacles.push_back(Obstacles(9950, 140));
    allObstacles.push_back(Obstacles(9975, -1020));

    allObstacles.push_back(Obstacles(10050, 90));
    allObstacles.push_back(Obstacles(10050, -1060));
    allObstacles.push_back(Obstacles(10150, 30));
    allObstacles.push_back(Obstacles(10125, -1090));
    allObstacles.push_back(Obstacles(10250, -20));
    allObstacles.push_back(Obstacles(10200, -1120));
    allObstacles.push_back(Obstacles(10275, -1150));

    allObstacles.push_back(Obstacles(10400, -20));

    allObstacles.push_back(Obstacles(10550, -20));
    allObstacles.push_back(Obstacles(10550, -1160));
    allObstacles.push_back(Obstacles(10650, 30));
    allObstacles.push_back(Obstacles(10625, -1130));
    allObstacles.push_back(Obstacles(10750, 90));
    allObstacles.push_back(Obstacles(10700, -1110));
    allObstacles.push_back(Obstacles(10775, -1085));
    allObstacles.push_back(Obstacles(10850, -1055));
    allObstacles.push_back(Obstacles(10925, -1015));






}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(FALSE);
    SetGraphMode(640, 440, 32);

    if (DxLib_Init() == -1)
        return -1;

   
    SetDrawScreen(DX_SCREEN_BACK);
    
    int titleImg = LoadGraph("Picture/Perilous Journey.png");
    int rankingImg = LoadGraph("Picture/RANKING BORD.png");


    // オブジェクト
    Startsetting startsetting;
    Player player;


    Background background;
    background.Init();

    // サウンド準備
    int explosionSound1 = -1;
	int explosionSound2 = 0;
    bool waitingExplosion = false; // 爆発音再生中フラグ
    bool pendingGameOver = false; // 爆発終了後にゲームオーバーにするか
    bool showDeathInfo = false; // 爆発終了後にスコア／残機を表示するフラグ
    int deathInfoStartTime = 0; // 表示開始時刻（ms）
   
    explosionSound1 = LoadSoundMem("Sound/explosion.mp3");
    explosionSound2 = LoadSoundMem("Sound/Music.mp3");
    //BGM再生フラグ
    bool playingBgm = false;

    std::vector<Obstacles> allObstacles;

    // 初期障害物を生成
    PopulateObstacles(allObstacles);

    // ゲーム状態
    bool gameOver = false;
    bool dead = false;
    int playerLife = 3;
    int frameCounter = 0;
	int highScore = 0;



    while (ProcessMessage() == 0)
    {
         ClearDrawScreen();

        // ========================================
        // 更新処理
        // ========================================

        if (gameState == GameState::Title)
        {
            DrawExtendGraph( 0, 0, 640, 440,titleImg, TRUE );
            // ランキング画像
            DrawExtendGraph(300, 10, 450, 140,rankingImg, TRUE );

            if (CheckHitKey(KEY_INPUT_RETURN))
            {
                gameState = GameState::Explanation;
            }

            ScreenFlip();
            continue;
        }

        if (gameState == GameState::Explanation)
        {
            // 背景を黒にする
            DrawBox(0, 0,640, 440,GetColor(0, 0, 0),TRUE);

             DrawString(220, 100,"操作説明",GetColor(255, 255, 255));

            DrawString(180, 180,"SPACE : 上昇",GetColor(255, 255, 255));

            DrawString(180, 220,"障害物を避けて進もう！",GetColor(255, 255, 255));

            DrawString(180, 350,"SPACE : ゲーム開始",GetColor(255, 255, 255));

            if (CheckHitKey(KEY_INPUT_UP))
            {
                gameState = GameState::Playing;
                
            }

            ScreenFlip();
            continue;
        }


        if (gameState == GameState::Playing)
        {
            DrawString(
                10, 10,
                "PLAYING",
                GetColor(255, 255, 255)
            );

            DrawFormatString(
                10, 30,
                GetColor(255, 255, 255),
                "isPlaying = %d",
                startsetting.isPlaying
            );

            // 以下そのまま
            
            if (!waitingExplosion && !showDeathInfo)
            {
                startsetting.Update();
            }

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
            // 爆発音再生中はゲーム進行を一時停止し、音の終了で処理を分岐する
            if (waitingExplosion)
            {
                if (explosionSound1 != -1)
                {
                    // CheckSoundMem: 0 = 停止, 1 = 再生中
                    if (CheckSoundMem(explosionSound1) == 0)
                    {
                        if (pendingGameOver)
                        {
                            // ライフ尽きている -> ゲームオーバー
                            gameOver = true;
                        }
                        else
                        {
                            // ライフ残あり -> 爆発音終了後に High Score と残機を表示する
                            showDeathInfo = true;
                            deathInfoStartTime = GetNowCount();
                            // 表示中はゲーム進行を止めるためスタート待機状態に戻す
                            startsetting.Reset();
                            player.vy = 0;
                        }

                        waitingExplosion = false;
                        pendingGameOver = false;
                    }
                }
                else
                {
                    if (pendingGameOver)
                    {
                        gameOver = true;
                    }
                    else
                    {
                        showDeathInfo = true;
                        deathInfoStartTime = GetNowCount();
                        startsetting.Reset();
                        player.vy = 0;
                    }

                    waitingExplosion = false;
                    pendingGameOver = false;
                }
            }
            else if (!gameOver)
            {
                if (startsetting.isPlaying == TRUE)
                {
                    if (startsetting.isPlaying && !waitingExplosion && !showDeathInfo) {
                        player.score += 4;
                    }
                    // プレイヤー更新（入力は爆発表示中は無効化）
                    player.Update(startsetting.isPlaying, startsetting.y, !(waitingExplosion || showDeathInfo));

                    // 画面下端にめり込み始めたらダメージ扱いにする
                    if (player.y > 440 - 50)
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


                    if (player.score > highScore)
                    {
                        highScore = player.score;
                    }


                    // ========================================
                    // プレイヤーが死亡した場合
                    // ========================================

                    if (dead)
                    {
                        playerLife--;
                        dead = false;

                        // BGM を止めて爆発音再生
                        if (playingBgm && explosionSound2 != -1)
                        {
                            StopSoundMem(explosionSound2);
                            playingBgm = false;

                        }

                        if (explosionSound1 != -1)
                        {
                            PlaySoundMem(explosionSound1, DX_PLAYTYPE_BACK);
                            waitingExplosion = true;
                            pendingGameOver = (playerLife <= 0);
                        }
                        else
                        {

                            if (playerLife <= 0)
                            {
                                gameOver = true;
                            }
                            else
                            {

                                // 即時リスポーン（音なし）
                                startsetting.Reset();
                                player.y = startsetting.y;
                                player.vy = 0;
                                background.Init();
                                frameCounter = 0;

                                PopulateObstacles(allObstacles);

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

            // 爆発音が終わった後（showDeathInfo）が true の間に High Score と残機を表示
            if (showDeathInfo)
            {
                // 背景を黒にする
                DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);

                char hsBuf[64];
                sprintf_s(hsBuf, "High Score: %d", highScore);
                DrawExtendString(200, 180, 2, 2, hsBuf, GetColor(255, 255, 255));

                char lifeBuf[64];
                sprintf_s(lifeBuf, "残機: %d", playerLife);
                DrawExtendString(200, 220, 2, 2, lifeBuf, GetColor(255, 255, 255));
            }

            // 爆発終了後に一定時間（2000ms）経過したらリスポーン処理を行う
            if (showDeathInfo)
            {
                int elapsed = GetNowCount() - deathInfoStartTime;
                if (elapsed >= 2000)
                {
                    // リスポーン実行
                    startsetting.Reset();
                    player.y = startsetting.y;
                    player.vy = 0;
                    background.Init();
                    frameCounter = 0;
                    PopulateObstacles(allObstacles);

                    // スコアを暗転終了後にリセット
                    player.score = 0;

                    showDeathInfo = false;
                }
            }

            // ゲームオーバー表示
            if (gameOver)
            {
                // 背景を黒にする
                DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);

                // GAME OVER
                DrawExtendString(150, 130, 4, 4, "GAME OVER", GetColor(255, 255, 255));

                // スコア
                char scoreBuf[64];
                sprintf_s(scoreBuf, "Score: %d", highScore);
                DrawExtendString(215, 220, 2, 2, scoreBuf, GetColor(255, 255, 255));
            }

            // ゲーム画面の枠
            DrawBox(0,0,640,440,GetColor(255, 255, 255),FALSE);

            ScreenFlip();
            frameCounter++;
            continue;

        
        }

       
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