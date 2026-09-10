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

    //地形１
    allObstacles.push_back(Obstacles(200, -1100));  //+440
    allObstacles.push_back(Obstacles(640, 0));  //+260
    allObstacles.push_back(Obstacles(900, -1100));  //+40
    allObstacles.push_back(Obstacles(940, -1130));  //+40
    allObstacles.push_back(Obstacles(980, -1150));  //+20
    allObstacles.push_back(Obstacles(1000, 100));  //+500
    allObstacles.push_back(Obstacles(1500, -50));  //+300
    allObstacles.push_back(Obstacles(1800, -1160));  //+150
    allObstacles.push_back(Obstacles(1950, -1000)); 

    //地形２
    allObstacles.push_back(Obstacles(2300, 70));  //+300
    allObstacles.push_back(Obstacles(2600, -70));  //+100
    allObstacles.push_back(Obstacles(2700, -50));  //+100
    allObstacles.push_back(Obstacles(2800, -10));  //+100
    allObstacles.push_back(Obstacles(2900, 30));  //+100
    allObstacles.push_back(Obstacles(3000, -1120));  //+50
    allObstacles.push_back(Obstacles(3050, -1090));  //+350
    allObstacles.push_back(Obstacles(3400, -10));  //+300
    allObstacles.push_back(Obstacles(3700, -60));  //+380
    allObstacles.push_back(Obstacles(4080, -1000));  

    //地形３
    allObstacles.push_back(Obstacles(4500, -40));  //+50
    allObstacles.push_back(Obstacles(4550, -70));  //+350
    allObstacles.push_back(Obstacles(4900, -1100));  //+200
    allObstacles.push_back(Obstacles(5100, -30));  //+300
    allObstacles.push_back(Obstacles(5430, -1000));  //+30
    allObstacles.push_back(Obstacles(5460, -1050));  //+30
    allObstacles.push_back(Obstacles(5490, -1100));  //+290
    allObstacles.push_back(Obstacles(5780, -1130));  //+20
    allObstacles.push_back(Obstacles(5800, 50));  //+40
    allObstacles.push_back(Obstacles(5840, 30));  //+40
    allObstacles.push_back(Obstacles(5880, 0));  //+40
    allObstacles.push_back(Obstacles(5920, -40));  //+40
    allObstacles.push_back(Obstacles(5960, -80));

    //地形４
    allObstacles.push_back(Obstacles(6400, -1130));  //+100
    allObstacles.push_back(Obstacles(6500, -20));  //+300
    allObstacles.push_back(Obstacles(6800, -1080));  //+200
    allObstacles.push_back(Obstacles(7000, -30));  //+100
    allObstacles.push_back(Obstacles(7100, -1170));  //+100
    allObstacles.push_back(Obstacles(7200, 10));  //+120
    allObstacles.push_back(Obstacles(7320, -1120));  //+80
    allObstacles.push_back(Obstacles(7400, -1100));  //+300
    allObstacles.push_back(Obstacles(7700, -30));  //+200
    allObstacles.push_back(Obstacles(7900, -1130));  //+200
    allObstacles.push_back(Obstacles(8100, -1150));  //+100
    allObstacles.push_back(Obstacles(8200, -10));  //+100
    allObstacles.push_back(Obstacles(8300, -1110));  //+150
    allObstacles.push_back(Obstacles(8450, -1130));  //+50
    allObstacles.push_back(Obstacles(8500, -20));  //+150
    allObstacles.push_back(Obstacles(8650, 100));  

    //地形５
    allObstacles.push_back(Obstacles(8800, -1000));  //+70
    allObstacles.push_back(Obstacles(8870, -970));  //+100
    allObstacles.push_back(Obstacles(8970, -970));  //+100
    allObstacles.push_back(Obstacles(9070, -930));  //+110
    allObstacles.push_back(Obstacles(9180, 180));  //-10
    allObstacles.push_back(Obstacles(9170, -950));  //+30
    allObstacles.push_back(Obstacles(9200, 170));  //+70
    allObstacles.push_back(Obstacles(9270, -1000));

    //地形６
    allObstacles.push_back(Obstacles(9300, 150));  //+100
    allObstacles.push_back(Obstacles(9400, 80));  //+180
    allObstacles.push_back(Obstacles(9580, -40));  //+320
    allObstacles.push_back(Obstacles(9900, -1010));  //+50
    allObstacles.push_back(Obstacles(9950, 140));  //+25
    allObstacles.push_back(Obstacles(9975, -1020));  //+75
    allObstacles.push_back(Obstacles(10050, 90));  //+-0
    allObstacles.push_back(Obstacles(10050, -1060));  //+100
    allObstacles.push_back(Obstacles(10150, 30));  //-25
    allObstacles.push_back(Obstacles(10125, -1090));  //+125
    allObstacles.push_back(Obstacles(10250, -20));  //-50
    allObstacles.push_back(Obstacles(10200, -1120));  //+75
    allObstacles.push_back(Obstacles(10275, -1150));  //+125
    allObstacles.push_back(Obstacles(10400, -20));  //+150
    allObstacles.push_back(Obstacles(10550, -20));  //+-0
    allObstacles.push_back(Obstacles(10550, -1160));  //+100
    allObstacles.push_back(Obstacles(10650, 30));  //-25
    allObstacles.push_back(Obstacles(10625, -1130));  //+125
    allObstacles.push_back(Obstacles(10750, 90));  //-50
    allObstacles.push_back(Obstacles(10700, -1110));  //+75
    allObstacles.push_back(Obstacles(10775, -1085));  //+75
    allObstacles.push_back(Obstacles(10850, -1055));  //+75
    allObstacles.push_back(Obstacles(10925, -1015));

    //地形７
    allObstacles.push_back(Obstacles(11250, -50));
    allObstacles.push_back(Obstacles(11300, -80));
    allObstacles.push_back(Obstacles(11350, -110));
    allObstacles.push_back(Obstacles(11400, -140));
    allObstacles.push_back(Obstacles(11760, -1110));
    allObstacles.push_back(Obstacles(11830, -1000));
    allObstacles.push_back(Obstacles(11900, -920));
    allObstacles.push_back(Obstacles(12000, -920));
    allObstacles.push_back(Obstacles(12100, -920));
    allObstacles.push_back(Obstacles(12200, -920));
    allObstacles.push_back(Obstacles(12300, -920));
    allObstacles.push_back(Obstacles(12400, -920));
    allObstacles.push_back(Obstacles(12500, -920));
    allObstacles.push_back(Obstacles(12600, -920));
    allObstacles.push_back(Obstacles(12700, -920));

    //地形２ー１
    allObstacles.push_back(Obstacles(13000, 60));
    allObstacles.push_back(Obstacles(13300, -100));
    allObstacles.push_back(Obstacles(13400, -60));
    allObstacles.push_back(Obstacles(13500, -20));
    allObstacles.push_back(Obstacles(13600, 20));
    allObstacles.push_back(Obstacles(13700, -1090));
    allObstacles.push_back(Obstacles(13750, -1060));
    allObstacles.push_back(Obstacles(14100, -40));
    allObstacles.push_back(Obstacles(14400, -90));
    allObstacles.push_back(Obstacles(14780, -950));

    //地形４ー１
    allObstacles.push_back(Obstacles(15200, -1100));  //+100
    allObstacles.push_back(Obstacles(15300, -20));  //+300
    allObstacles.push_back(Obstacles(15600, -1050));  //+200
    allObstacles.push_back(Obstacles(15800, -30));  //+100
    allObstacles.push_back(Obstacles(15900, -1090));  //+100
    allObstacles.push_back(Obstacles(16000, 10));  //+120
    allObstacles.push_back(Obstacles(16120, -1070));  //+80
    allObstacles.push_back(Obstacles(16200, -1050));  //+300
    allObstacles.push_back(Obstacles(16500, -30));  //+200
    allObstacles.push_back(Obstacles(16700, -1070));  //+200
    allObstacles.push_back(Obstacles(16900, -1100));  //+100
    allObstacles.push_back(Obstacles(17000, -10));  //+100
    allObstacles.push_back(Obstacles(17100, -1080));  //+150
    allObstacles.push_back(Obstacles(17250, -1100));  //+50
    allObstacles.push_back(Obstacles(17300, -20));  //+150
    allObstacles.push_back(Obstacles(17450, 100));

    //地形１ー１
    allObstacles.push_back(Obstacles(17700, -880));  //+440
    allObstacles.push_back(Obstacles(18140, -40));  //+260
    allObstacles.push_back(Obstacles(18400, -1010));  //+40
    allObstacles.push_back(Obstacles(18440, -1030));  //+40
    allObstacles.push_back(Obstacles(18480, -1050));  //+20
    allObstacles.push_back(Obstacles(18500, 60));  //+500
    allObstacles.push_back(Obstacles(19000, -90));  //+300
    allObstacles.push_back(Obstacles(19300, -1060));  //+150
    allObstacles.push_back(Obstacles(19450, -900));

    //地形６ー１
    allObstacles.push_back(Obstacles(19600, 150));  //+100
    allObstacles.push_back(Obstacles(19700, 80));  //+180
    allObstacles.push_back(Obstacles(20080, -40));  //+320
    allObstacles.push_back(Obstacles(20400, -990));  //+50
    allObstacles.push_back(Obstacles(20450, 140));  //+25
    allObstacles.push_back(Obstacles(20475, -1000));  //+75
    allObstacles.push_back(Obstacles(20550, 90));  //+-0
    allObstacles.push_back(Obstacles(20550, -1030));  //+100
    allObstacles.push_back(Obstacles(20650, 30));  //-25
    allObstacles.push_back(Obstacles(20625, -1060));  //+125
    allObstacles.push_back(Obstacles(20750, -20));  //-50
    allObstacles.push_back(Obstacles(20700, -1090));  //+75
    allObstacles.push_back(Obstacles(20775, -1120));  //+125
    allObstacles.push_back(Obstacles(20900, -20));  //+150
    allObstacles.push_back(Obstacles(21050, -20));  //+-0
    allObstacles.push_back(Obstacles(21050, -1090));  //+100
    allObstacles.push_back(Obstacles(21150, 30));  //-25
    allObstacles.push_back(Obstacles(21125, -1060));  //+125
    allObstacles.push_back(Obstacles(21250, 90));  //-50
    allObstacles.push_back(Obstacles(21200, -1040));  //+75
    allObstacles.push_back(Obstacles(21275, -1015));  //+75
    allObstacles.push_back(Obstacles(21350, -980));  //+75
    allObstacles.push_back(Obstacles(21425, -940));

    //地形３ー１
    allObstacles.push_back(Obstacles(21800, -40));  //+50
    allObstacles.push_back(Obstacles(21850, -70));  //+350
    allObstacles.push_back(Obstacles(22200, -1100));  //+200
    allObstacles.push_back(Obstacles(22400, -30));  //+300
    allObstacles.push_back(Obstacles(22700, -1000));  //+30
    allObstacles.push_back(Obstacles(22730, -1050));  //+30
    allObstacles.push_back(Obstacles(22760, -1100));  //+290
    allObstacles.push_back(Obstacles(23050, -1065));  //+20
    allObstacles.push_back(Obstacles(23070, 50));  //+40
    allObstacles.push_back(Obstacles(23110, 30));  //+40
    allObstacles.push_back(Obstacles(23150, 0));  //+40
    allObstacles.push_back(Obstacles(23190, -40));  //+40
    allObstacles.push_back(Obstacles(23230, -80));

    //地形５
    allObstacles.push_back(Obstacles(23500, -1000));  //+70
    allObstacles.push_back(Obstacles(23570, -970));  //+100
    allObstacles.push_back(Obstacles(23670, -970));  //+100
    allObstacles.push_back(Obstacles(23780, -930));  //+110
    allObstacles.push_back(Obstacles(23890, 180));  //-10
    allObstacles.push_back(Obstacles(23880, -950));  //+30
    allObstacles.push_back(Obstacles(23910, 170));  //+70
    allObstacles.push_back(Obstacles(23980, -1000));

}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(FALSE);

    SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);

    SetGraphMode(640, 440, 32);

    if (DxLib_Init() == -1)
        return -1;

    SetDrawScreen(DX_SCREEN_BACK);
    
    int titleImg = LoadGraph("Picture/Perilous Journey1.png");
    int rankingImg = LoadGraph("Picture/RANKING BORD.png");


    // オブジェクト
    Startsetting startsetting;
    Player player;


    Background background;
    background.Load();
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
    int rankingNo1 = 0;
    int rankingNo2 = 0;
    int rankingNo3 = 0;

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
            DrawExtendGraph(0, 220, 250, 475,rankingImg, TRUE );

            DrawExtendString(42, 308, 2, 2, "1.", GetColor(0, 0, 0));

            DrawExtendString(42, 348, 2, 2, "2.", GetColor(0, 0, 0));

            DrawExtendString(42, 389, 2, 2, "3.", GetColor(0, 0, 0));

            DrawExtendString(320, 395, 2, 2, "Enter キーで開始", GetColor(255, 255, 255));

            char No1Buf[64];
            sprintf_s(No1Buf, "%d", rankingNo1);
            DrawExtendString(80, 308, 2, 2, No1Buf, GetColor(0, 0, 0));

            char No2Buf[64];
            sprintf_s(No2Buf, "%d", rankingNo2);
            DrawExtendString(80, 348, 2, 2, No2Buf, GetColor(0, 0, 0));

            char No3Buf[64];
            sprintf_s(No3Buf, "%d", rankingNo3);
            DrawExtendString(80, 388, 2, 2, No3Buf, GetColor(0, 0, 0));



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
                        player.score += 2;
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
                            player.boxcolider.CheckOverlap(allObstacles[i].box18) ||
                            player.boxcolider.CheckOverlap(allObstacles[i].box19))
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

             startsetting.Draw();


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

                // SPACEを押したらタイトル画面へ
                if (CheckHitKey(KEY_INPUT_SPACE))
                {
                    gameState = GameState::Title;
                    gameOver = false;

                    // ゲームを初期状態に戻す
                    playerLife = 3;
                    player.score = 0;
                    highScore = 0;

                    startsetting.Reset();

                    player.y = startsetting.y;
                    player.vy = 0;

                    background.Init();
                    frameCounter = 0;

                    PopulateObstacles(allObstacles);
                }
            }



            // ゲーム画面の枠
            DrawBox(0,0,640,440,GetColor(255, 255, 255),FALSE);

            ScreenFlip();
            frameCounter++;
            continue;

        
        }

       
    }

    background.End();
    
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