
#pragma once

#include "StartScreen.hpp"
#include "GameScreen.hpp"

class Game {
public:
    Game() {
        ConsoleTitle("Forest Of Hong-Ik");
    }
    ~Game() {
        system("cls");
    }

    void Run() {
        // 첫 화면
        StartScreen start_game;

        start_game.Run();

        // 겜 시작
        GameScreen game_screen;

        game_screen.Run();
    }
};