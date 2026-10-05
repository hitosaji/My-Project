#include "DxLib.h"
#include "player.h"
#include "background.h"
#include "obstacles.h"
#include "Startsetting.h"
#include"GameState.h"
#include <vector>

//ランキング関数
void UpdateRanking(int highScore, int& rankingNo1, int& rankingNo2, int& rankingNo3)
{
    if (highScore > rankingNo1)
    {
        rankingNo3 = rankingNo2;
        rankingNo2 = rankingNo1;
        rankingNo1 = highScore;
    }
    else if (highScore > rankingNo2)
    {
        rankingNo3 = rankingNo2;
        rankingNo2 = highScore;
    }
    else if (highScore > rankingNo3)
    {
        rankingNo3 = highScore;
    }
}

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
    allObstacles.push_back(Obstacles(23050, -1070));  //+20
    allObstacles.push_back(Obstacles(23070, 50));  //+40
    allObstacles.push_back(Obstacles(23110, 30));  //+40
    allObstacles.push_back(Obstacles(23150, 0));  //+40
    allObstacles.push_back(Obstacles(23190, -40));  //+40
    allObstacles.push_back(Obstacles(23230, -80));

    //地形５ー１
    allObstacles.push_back(Obstacles(23500, -1000));  //+70
    allObstacles.push_back(Obstacles(23570, -910));  //+100
    allObstacles.push_back(Obstacles(23670, -890));  //+100
    allObstacles.push_back(Obstacles(23780, -850));  //+110
    allObstacles.push_back(Obstacles(23890, 190));  //-10
    allObstacles.push_back(Obstacles(23880, -860));  //+30
    allObstacles.push_back(Obstacles(23910, 175));  //+70
    allObstacles.push_back(Obstacles(23980, -890));

    //地形７ー１
    allObstacles.push_back(Obstacles(24350, -50)); //+50
    allObstacles.push_back(Obstacles(24400, -80)); //+50
    allObstacles.push_back(Obstacles(24450, -110)); //+50
    allObstacles.push_back(Obstacles(24500, -140)); //+360
    allObstacles.push_back(Obstacles(24860, -1110)); //+70
    allObstacles.push_back(Obstacles(24930, -1000)); //+70
    allObstacles.push_back(Obstacles(25000, -920)); //+100
    allObstacles.push_back(Obstacles(25100, -900)); //+100
    allObstacles.push_back(Obstacles(25200, -880)); //+100
    allObstacles.push_back(Obstacles(25300, -850)); //+100
    allObstacles.push_back(Obstacles(25400, -850)); //+100
    allObstacles.push_back(Obstacles(25500, -850)); //+100
    allObstacles.push_back(Obstacles(25600, -850)); //+100
    allObstacles.push_back(Obstacles(25700, -850)); //+100
    allObstacles.push_back(Obstacles(25800, -850));
    allObstacles.push_back(Obstacles(25900, -850));
    allObstacles.push_back(Obstacles(26000, -850));
    allObstacles.push_back(Obstacles(26100, -830));

    allObstacles.push_back(Obstacles(26400, 80));  //+60
    allObstacles.push_back(Obstacles(26460, -935));  //+310
    allObstacles.push_back(Obstacles(26770, -1040));  //+130
    allObstacles.push_back(Obstacles(26900, -40));  //+200
    allObstacles.push_back(Obstacles(27100, -130));  //+0
    allObstacles.push_back(Obstacles(27100, -1150));  //+200
    allObstacles.push_back(Obstacles(27300, -1100));  //+0
    allObstacles.push_back(Obstacles(27300, -90));  //+200
    allObstacles.push_back(Obstacles(27500, -130));  //+0
    allObstacles.push_back(Obstacles(27500, -1150));

    allObstacles.push_back(Obstacles(27740, -1090));  //+90
    allObstacles.push_back(Obstacles(27830, -980));  //+100
    allObstacles.push_back(Obstacles(27930, -870));  //+110
    allObstacles.push_back(Obstacles(28040, 140));  //+0
    allObstacles.push_back(Obstacles(28040, -910));  //+100
    allObstacles.push_back(Obstacles(28140, -940));  //+30
    allObstacles.push_back(Obstacles(28170, 110));  //+70
    allObstacles.push_back(Obstacles(28240, -970));  //+60
    allObstacles.push_back(Obstacles(28300, 80));  //+40
    allObstacles.push_back(Obstacles(28340, -970));  //+40 
    allObstacles.push_back(Obstacles(28380, 60));  //+60    
    allObstacles.push_back(Obstacles(28440, -970));  //+20
    allObstacles.push_back(Obstacles(28460, 60));  //+60
    allObstacles.push_back(Obstacles(28520, -1030));  //+80 
    allObstacles.push_back(Obstacles(28600, -1070));  //+50
    allObstacles.push_back(Obstacles(28650, 20));  //+30  
    allObstacles.push_back(Obstacles(28680, -1110));  //+20
    allObstacles.push_back(Obstacles(28700, -20));  //+60  
    allObstacles.push_back(Obstacles(28760, -1160));  //+10
    allObstacles.push_back(Obstacles(28770, -70));  //+60  
    allObstacles.push_back(Obstacles(28830, -110));  //+10
    allObstacles.push_back(Obstacles(28840, -1170));  //+60
    allObstacles.push_back(Obstacles(28900, -1180));  //+0
    allObstacles.push_back(Obstacles(28900, -150));
    allObstacles.push_back(Obstacles(29100, 70));
    allObstacles.push_back(Obstacles(29300, 90));
    allObstacles.push_back(Obstacles(29500, 110));

    allObstacles.push_back(Obstacles(30000, -750));
    allObstacles.push_back(Obstacles(30075, -325));
    allObstacles.push_back(Obstacles(30150, -750));
    allObstacles.push_back(Obstacles(30225, -325));
    allObstacles.push_back(Obstacles(30300, -750));
    allObstacles.push_back(Obstacles(30375, -325));
    allObstacles.push_back(Obstacles(30450, -750));
    allObstacles.push_back(Obstacles(30525, -325));
    allObstacles.push_back(Obstacles(30600, -750));
    allObstacles.push_back(Obstacles(30675, -325));
    allObstacles.push_back(Obstacles(30750, -750));
    allObstacles.push_back(Obstacles(30825, -325));
    allObstacles.push_back(Obstacles(30900, -750));
    allObstacles.push_back(Obstacles(30975, -325));
    allObstacles.push_back(Obstacles(31050, -750));
    allObstacles.push_back(Obstacles(31125, -325));
    allObstacles.push_back(Obstacles(31200, -750));
    allObstacles.push_back(Obstacles(31275, -325));
    allObstacles.push_back(Obstacles(31350, -750));
    allObstacles.push_back(Obstacles(31425, -325));
    allObstacles.push_back(Obstacles(31500, -750));
    allObstacles.push_back(Obstacles(31575, -325));

}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(FALSE);

    SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);

    SetGraphMode(660, 440, 32);

    if (DxLib_Init() == -1)
        return -1;

    SetDrawScreen(DX_SCREEN_BACK);
    
    int titleImg = LoadGraph("Picture/Perilous Journey1.png");
    int rankingImg = LoadGraph("Picture/RANKING BORD.png");
    int spaneImg = LoadGraph("Picture/SPACE.png");
	int PLAYERImg = LoadGraph("Picture/Player.png");

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
    bool clearFlag = false; // ゲームクリア（スコア閾値到達でのクリア）フラグ
    int deathInfoStartTime = 0; // 表示開始時刻（ms）
   
    explosionSound1 = LoadSoundMem("Sound/explosion.mp3");
    explosionSound2 = LoadSoundMem("Sound/Music.mp3");
    int clearSound = -1;
    clearSound = LoadSoundMem("Sound/lvup2.mp3");
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



    int blinkTimer = 0;

    static bool spaceLock = false;

    int oldTime = GetNowCount();
    

    while (ProcessMessage() == 0)
    {
        while (ProcessMessage() == 0)
        {
            int nowTime = GetNowCount();

            float deltaTime = (nowTime - oldTime) / 1000.0f;

            oldTime = nowTime;

            ClearDrawScreen();

            blinkTimer++;

            // ========================================
            // 更新処理
            // ========================================

            if (gameState == GameState::Title)
            {
                DrawExtendGraph(0, 0, 640, 440, titleImg, TRUE);
                // ランキング画像
                DrawExtendGraph(0, 220, 250, 475, rankingImg, TRUE);

                DrawExtendString(42, 308, 2, 2, "1.", GetColor(0, 0, 0));

                DrawExtendString(42, 348, 2, 2, "2.", GetColor(0, 0, 0));

                DrawExtendString(42, 389, 2, 2, "3.", GetColor(0, 0, 0));

                DrawExtendString(320, 395, 2, 2, "SPACE キーで開始", GetColor(255, 255, 255));

                char No1Buf[64];
                sprintf_s(No1Buf, "%d", rankingNo1);
                DrawExtendString(80, 308, 2, 2, No1Buf, GetColor(0, 0, 0));

                char No2Buf[64];
                sprintf_s(No2Buf, "%d", rankingNo2);
                DrawExtendString(80, 349, 2, 2, No2Buf, GetColor(0, 0, 0));

                char No3Buf[64];
                sprintf_s(No3Buf, "%d", rankingNo3);
                DrawExtendString(80, 390, 2, 2, No3Buf, GetColor(0, 0, 0));



                if (CheckHitKey(KEY_INPUT_SPACE))
                {
                    if (!spaceLock)
                    {
                        gameState = GameState::Explanation;

                        spaceLock = true;
                    }
                }
                else
                {
                    spaceLock = false;
                }

                ScreenFlip();
                continue;
            }

            if (gameState == GameState::Explanation)
            {
                // 背景を黒にする
                DrawBox(0, 0, 660, 440, GetColor(0, 0, 0), TRUE);

                DrawFormatString(10, 10, GetColor(255, 255, 255),
                    "Timer: %d", blinkTimer);

                DrawExtendString(150, 50, 5, 5, "操作説明", GetColor(255, 255, 255));

                DrawExtendString(200, 150, 2, 2, "SPACE : 上昇", GetColor(255, 255, 255));

                DrawExtendString(0, 200, 2, 2, "このゲームはスペースキーしか使いません!", GetColor(255, 255, 255));

                DrawExtendString(145, 260, 2, 2, "障害物を避けて進もう！", GetColor(255, 255, 255));

                if (blinkTimer < 40)
                {
                    DrawExtendString(132, 350, 2, 2, " - START to SPACE - ", GetColor(255, 255, 255));
                }
                else if (blinkTimer > 80)
                {
                    DrawExtendString(132, 350, 2, 2, " - START to SPACE - ", GetColor(0, 0, 0));
                    blinkTimer = 0;
                }


                if (CheckHitKey(KEY_INPUT_SPACE))
                {
                    if (!spaceLock)
                    {
                        gameState = GameState::Playing;

                        spaceLock = true;
                    }
                }
                else
                {
                    spaceLock = false;
                }

                ScreenFlip();
                continue;
            }


            if (gameState == GameState::Playing)
            {
                DrawString(10, 10,"PLAYING",GetColor(255, 255, 255));

                DrawFormatString(10, 30,GetColor(255, 255, 255),"isPlaying = %d",startsetting.isPlaying);

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
                //音による処理分岐
                if (waitingExplosion)
                {
                    if (explosionSound1 != -1)
                    {
                        // CheckSoundMem0=停止,1=再生中
                        if (CheckSoundMem(explosionSound1) == 0)
                        {
                            if (pendingGameOver)
                            {
                                //ゲームオーバー
                                gameOver = true;
                            }
                            else
                            {
                                //爆発音終了後に High Score と残機を表示する
                                showDeathInfo = true;
                                deathInfoStartTime = GetNowCount();
                                // 表示中はゲーム進行を止めるためスタート待機状態に戻す
                                startsetting.Reset();
                                player.vy = 0;

                                // 暗転（showDeathInfo）開始時点でライフを一度だけ減らす
                                if (playerLife > 0) playerLife--;

                                // スコアが 30000 を超えている場合はクリアサウンドを鳴らす
                                if (player.score > 30000)
                                {
                                    if (playingBgm && explosionSound2 != -1)
                                    {
                                        StopSoundMem(explosionSound2);
                                        playingBgm = false;
                                    }
                                    if (explosionSound1 != -1) StopSoundMem(explosionSound1);
                                    if (clearSound != -1) { PlaySoundMem(clearSound, DX_PLAYTYPE_BACK); clearFlag = true; }
                                }
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

                        // 暗転開始でライフを減らす
                        if (playerLife > 0) playerLife--;

                        // スコアが 30000 を超えている場合はクリアサウンドを鳴らす
                        if (player.score > 30000)
                        {
                            if (playingBgm && explosionSound2 != -1)
                            {
                                StopSoundMem(explosionSound2);
                                playingBgm = false;
                            }
                            if (explosionSound1 != -1) StopSoundMem(explosionSound1);
                            if (clearSound != -1) { PlaySoundMem(clearSound, DX_PLAYTYPE_BACK); clearFlag = true; }
                        }
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
                        player.Update(startsetting.isPlaying, startsetting.y, !(waitingExplosion || showDeathInfo), deltaTime);

                        // 画面下端にめり込み始めたらダメージ扱いにする
                        if (player.y > 440 - 50)
                        {
                            dead = true;
                        }

                        // 背景更新
                        background.Update(frameCounter, deltaTime);

                       


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
                            dead = false;

                            //残機が0の状態での死亡していたらゲームオーバー
                            if (playerLife == 0)
                            {
                               
                                if (playingBgm && explosionSound2 != -1)
                                {
                                    StopSoundMem(explosionSound2);
                                    playingBgm = false;
                                }

                                if (explosionSound1 != -1)
                                {
                                    PlaySoundMem(explosionSound1, DX_PLAYTYPE_BACK);
                                    waitingExplosion = true;
                                    pendingGameOver = true;
                                }
                                else
                                {
                                    gameOver = true;
                                }
                            }
                            else
                            {
                                if (playingBgm && explosionSound2 != -1)
                                {
                                    StopSoundMem(explosionSound2);
                                    playingBgm = false;
                                }

                                if (explosionSound1 != -1)
                                {
                                    PlaySoundMem(explosionSound1, DX_PLAYTYPE_BACK);
                                    waitingExplosion = true;
                                    pendingGameOver = false; 
                                }
                                else
                                {
                                    // 即時リスポーン
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

				DrawExtendGraph(540, 5, 600, 55, PLAYERImg, TRUE);

                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);

                DrawBox(518, 400, 655, 431, GetColor(0, 0, 0), TRUE);

                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

                DrawExtendGraph(480, 370, 630, 470, spaneImg, TRUE);
              
				DrawExtendString(592, 408, 1, 1, "/↑上昇", GetColor(255, 255, 255));
                
                DrawExtendString(595, 20, 2, 2, "×", GetColor(255, 255, 255));

                char lifeBuf[16];
                sprintf_s(lifeBuf, "%d", playerLife);
                
                DrawExtendString(630, 20, 2, 2, lifeBuf, GetColor(255, 255, 255));

                // 爆発音が終わった後がtrueの間にHigh Scoreと残機を表示
                if (showDeathInfo)
                {
                    
                    // 背景を黒にする
                    DrawBox(0, 0, 660, 480, GetColor(0, 0, 0), TRUE);

                    char hsBuf[64];
                    sprintf_s(hsBuf, "High Score: %d", highScore);
                    DrawExtendString(200, 180, 2, 2, hsBuf, GetColor(255, 255, 255));

                    char lifeBuf[64];

					DrawExtendGraph(260, 210, 320, 260, PLAYERImg, TRUE);
                    sprintf_s(lifeBuf, "    : %d", playerLife);
                    DrawExtendString(255, 220, 2, 2, lifeBuf, GetColor(255, 255, 255));
                    // クリア時は GAME CLEAR を表示
                    if (clearFlag)
                    {
                        DrawExtendString(160, 100, 4.0f, 4.0f, "GAME CLEAR", GetColor(255, 255, 255));
                        DrawExtendString(100, 340, 2.0f, 2.0f, "      SPACE to TITLE", GetColor(255, 255, 255));
                    }
		}

		// 爆発音が終わった後がtrueの間にHigh Scoreと残機を表示
		if (showDeathInfo)
		{
			int elapsed = GetNowCount() - deathInfoStartTime;
			if (elapsed >= 2000)
			{
                if (clearFlag)
                {
                    // クリア時はスペース入力を待つ
                    // SPACE 判定は下で行う
                }
                else
                {
                    // 通常のリスポーン
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
		}

        // クリア時: showDeathInfo 表示中に SPACE 押下でタイトルに戻す
        if (showDeathInfo && clearFlag)
        {
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                if (!spaceLock)
                {
                    if (clearSound != -1) StopSoundMem(clearSound);

                    UpdateRanking(highScore, rankingNo1, rankingNo2, rankingNo3);


                    gameState = GameState::Title;

                    playerLife = 3;
                    player.score = 0;
                    highScore = 0;

                    startsetting.Reset();
                    player.y = startsetting.y;
                    player.vy = 0;

                    background.Init();
                    frameCounter = 0;
                    PopulateObstacles(allObstacles);

                    showDeathInfo = false;
                    clearFlag = false;
                    spaceLock = true;
                }
            }
            else
            {
                spaceLock = false;
            }
        }

                // ゲームオーバー表示
                if (gameOver)
                {
                    // 背景を黒にする
                    DrawBox(0, 0, 660, 480, GetColor(0, 0, 0), TRUE);

                    // GAME OVER
                    DrawExtendString(160, 130, 4, 4, "GAME OVER", GetColor(255, 255, 255));

                    // スコア
                    char scoreBuf[64];
                    sprintf_s(scoreBuf, "Score: %d", highScore);
                    DrawExtendString(225, 220, 2, 2, scoreBuf, GetColor(255, 255, 255));

                    // SPACEを押したらタイトル画面へ
                    if (CheckHitKey(KEY_INPUT_SPACE))
                    {

                        UpdateRanking(highScore,rankingNo1, rankingNo2, rankingNo3);

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
                DrawBox(0, 0, 660, 440, GetColor(255, 255, 255), FALSE);

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
    }

    return 0;
}