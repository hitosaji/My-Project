#pragma once
enum class GameState
{
    Title,
    Explanation,
    Playing,
    GameOver
};

GameState gameState = GameState::Title;

