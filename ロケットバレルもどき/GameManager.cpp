#include "GameManager.h"
#include "DxLib.h"

GameManager::GameManager()
    : playerLives(3)
    , showLifeScreen(false)
    , showStartScreen(false)
    , pausedAfterHit(false)
    , collisionTime(0)
    , pauseMs(1000)
    , invulUntil(0)
    , collisionHandled(false)
{
    // 初期障害物X位置（Main.cpp と合わせる）
    initialXs = { 640, 1000, 1500, 2300, 2600, 2700 };
}

void GameManager::DetectCollision(Player& player, std::vector<Obstacles>& obstacles, Background& background, bool& gameOver, bool& Dead)
{
    // 衝突判定はプレイ中のみ
    if (!player.startsetting.isPlaying) return;
    // すでに衝突処理中なら重複処理しない
    if (pausedAfterHit) return;
    if (collisionHandled) return;
    // 再起動の無敵状態
    if (GetNowCount() < invulUntil) return;

    for (int i = 0; i < (int)obstacles.size(); i++)
    {
        if (player.boxcolider.CheckOverlap(obstacles[i].box1) ||
            player.boxcolider.CheckOverlap(obstacles[i].box2) ||
            player.boxcolider.CheckOverlap(obstacles[i].box3) ||
            player.boxcolider.CheckOverlap(obstacles[i].box4) ||
            player.boxcolider.CheckOverlap(obstacles[i].box5) ||
            player.boxcolider.CheckOverlap(obstacles[i].box6))
        {
            // 停止
            for (int j = 0; j < (int)obstacles.size(); j++) obstacles[j].Stop();

            playerLives--;
            collisionHandled = true;
            background.startsetting.isPlaying = false;
            collisionTime = GetNowCount();
            pausedAfterHit = true;
            Dead = true;

            // プレイ中フラグを落として二重判定を防ぐ
            player.startsetting.isPlaying = false;

            break;
        }
    }
}

void GameManager::EnterLifeScreen(Player& player, Background& background, std::vector<Obstacles>& obstacles)
{

}

void GameManager::EnterStartScreen(Player& player, Background& background, std::vector<Obstacles>& obstacles)
{
    // Reset player startstate
    player.startsetting.pressCount = 0;
    player.startsetting.isPlaying = false;
    player.y = 200.0f;
    player.vy = 0.0f;

    // Reset obstacles
    for (int j = 0; j < (int)obstacles.size(); j++) {
        obstacles[j].x = initialXs[j];
        obstacles[j].startsetting.pressCount = 0;
        obstacles[j].startsetting.isPlaying = false;
        obstacles[j].Resume();
    }

    // Reset background
    background.startsetting.isPlaying = false;
    background.back1 = 0;
    background.back2 = 2172;
    // allow collisions again after resetting
    collisionHandled = false;
}

void GameManager::Update(Player& player, Background& background, std::vector<Obstacles>& obstacles, bool& gameOver)
{
    // handle pausedAfterHit -> showLifeScreen transition
    if (pausedAfterHit)
    {
        unsigned int now = GetNowCount();
        if (now - collisionTime >= pauseMs)
        {
            pausedAfterHit = false;
            showLifeScreen = true;
            EnterLifeScreen(player, background, obstacles);
        }
    }

    // If lives reached zero, set game over here (centralized)
    if (playerLives <= 0)
    {
        gameOver = true;
        // ensure life screen not shown
        showLifeScreen = false;
        showStartScreen = false;
        pausedAfterHit = false;
    }

    // If in life screen, handle input to go to start screen (drawing is handled separately)
    if (showLifeScreen)
    {
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            showLifeScreen = false;
            showStartScreen = true;
            // clear pause flags
            pausedAfterHit = false;
            collisionTime = 0;

            EnterStartScreen(player, background, obstacles);
        }
    }
    else if (showStartScreen)
    {
        // Wait for player to press space 3 times (handled inside Player::Update / Startsetting)
        // Draw string is handled by Startsetting::Update
        if (player.startsetting.isPlaying)
        {
            // resume obstacles and background
            for (int j = 0; j < (int)obstacles.size(); j++) {
                obstacles[j].startsetting.isPlaying = true;
                obstacles[j].Resume();
            }
            background.startsetting.isPlaying = true;
            // give short invulnerability after restart to avoid immediate re-collision
            invulUntil = GetNowCount() + 500; // 0.5s invul
            showStartScreen = false;
        }
    }
    else
    {
        // nothing special to do
    }
}

void GameManager::DrawOverlay()
{
    if (showLifeScreen)
    {
        DrawBox(0, 0, 640, 440, GetColor(0, 0, 0), TRUE);
        char buf[64];
        sprintf_s(buf, "Lives: %d", playerLives);
        DrawString(260, 200, buf, GetColor(255, 255, 255));
    }
}
bool GameManager::IsGameOver() const
{
    return playerLives <= 0;
}

int GameManager::GetLives() const
{
    return playerLives;
}

bool GameManager::IsPaused() const
{
    return pausedAfterHit;
}
