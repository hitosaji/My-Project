#pragma once
#include <vector>
#include "player.h"
#include "background.h"
#include "obstacles.h"

class GameManager
{
public:
    GameManager();

    // collision detection called from main loop
    void DetectCollision(Player& player, std::vector<Obstacles>& obstacles, Background& background, bool& gameOver, bool& Dead);

    // per-frame update (handles pause timing, life screen, start screen, inputs)
    void Update(Player& player, Background& background, std::vector<Obstacles>& obstacles, bool& gameOver);
    // Draw overlays (life screen) after world is drawn
    void DrawOverlay();
    bool IsGameOver() const;
    int GetLives() const;
    bool IsPaused() const;

private:
    int playerLives;
    bool showLifeScreen;
    bool showStartScreen;
    bool pausedAfterHit;
    unsigned int collisionTime;
    const unsigned int pauseMs;
    unsigned int invulUntil;
    bool collisionHandled;
    std::vector<int> initialXs;

    void EnterLifeScreen(Player& player, Background& background, std::vector<Obstacles>& obstacles);
    void EnterStartScreen(Player& player, Background& background, std::vector<Obstacles>& obstacles);
};
