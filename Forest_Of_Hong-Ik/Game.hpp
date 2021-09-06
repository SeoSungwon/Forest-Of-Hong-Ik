
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
        // ù ȭ��
        StartScreen start_game;

        start_game.Run();

        // �� ����
        GameScreen game_screen;

        game_screen.Run();
    }
};