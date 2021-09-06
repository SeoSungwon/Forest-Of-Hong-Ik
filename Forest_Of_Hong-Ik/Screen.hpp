
#pragma once

#include "Api.hpp"

constexpr auto GAME_SCREEN_X = 100;
constexpr auto GAME_SCREEN_Y = 29;

namespace Screen {
    static void StartScreen() {
        ConsoleClear();
        Gotoxy(0, 0);  cout << "┌──────────────────────────────────────────────────────────────────────────┐";
        Gotoxy(0, 1);  cout << "│                                                                          │";
        Gotoxy(0, 2);  cout << "│                                                                          │";
        Gotoxy(0, 3);  cout << "│                                                                          │";
        Gotoxy(0, 4);  cout << "│                                                                          │";
        Gotoxy(0, 5);  cout << "│                                                                          │";
        Gotoxy(0, 6);  cout << "│                                                                          │";
        Gotoxy(0, 7);  cout << "│                                                                          │";
        Gotoxy(0, 8);  cout << "│                                                                          │";
        Gotoxy(0, 9);  cout << "│                                                                          │";
        Gotoxy(0, 10); cout << "│                                                                          │";
        Gotoxy(0, 11); cout << "│                                                                          │";
        Gotoxy(0, 12); cout << "│                                                                          │";
        Gotoxy(0, 13); cout << "│                                                                          │";
        Gotoxy(0, 14); cout << "│                                                                          │";
        Gotoxy(0, 15); cout << "│                                                                          │";
        Gotoxy(0, 16); cout << "│                                                                          │";
        Gotoxy(0, 17); cout << "│                                                                          │";
        Gotoxy(0, 18); cout << "│                                                                          │";
        Gotoxy(0, 19); cout << "│                                                                          │";
        Gotoxy(0, 20); cout << "└──────────────────────────────────────────────────────────────────────────┘";
    }

    static void StartScreen_PlaneForViewing() {
        ConsoleColor(GREEN);
        Gotoxy(2, 1);  cout << "        ＃                                                          ＃   ";
        Gotoxy(2, 2);  cout << "＃                                                      ＃               ";
        Gotoxy(2, 3);  cout << "               ＃                                                ＃      ";
        Gotoxy(2, 4);  cout << "   ＃                                                                  ＃";
        Gotoxy(2, 5);  cout << "         ＃                                                 ＃           ";
        Gotoxy(2, 6);  cout << "  ＃                                                              ＃     ";
        Gotoxy(2, 7);  cout << "          ＃                                           ＃                ";
        Gotoxy(2, 8);  cout << "     ＃                                                             ＃   ";
        Gotoxy(2, 9);  cout << "              ＃                                                 ＃      ";
        Gotoxy(2, 10); cout << " ＃                                                      ＃              ";
        Gotoxy(2, 12); cout << "            ＃                                                       ＃  ";
        Gotoxy(2, 13); cout << "    ＃                                                     ＃            ";
        Gotoxy(2, 14); cout << "＃                                                                 ＃    ";
        Gotoxy(2, 15); cout << "         ＃                                                   ＃         ";
        Gotoxy(2, 16); cout << "  ＃                                                     ＃              ";
        Gotoxy(2, 17); cout << "              ＃                                                 ＃      ";
        Gotoxy(2, 18); cout << "       ＃                                                             ＃ ";
        Gotoxy(2, 19); cout << "＃                                                           ＃          ";
        ConsoleColorOriginal();
    }

    static void GameEmptyScreen() {
        ConsoleClear();
        Gotoxy(0,0); 
        cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "└─────────────────────────────────────────────────────────────────────────────────────────────────┘\n";
    }

    static void GameKeyInformation() {
        Gotoxy(60, 21);
        cout << "["; ConsoleColor(LIGHTRED); cout << " Ctrl "; ConsoleColorOriginal(); cout << "] 들어가기";
        cout << "  ["; ConsoleColor(BLUE); cout << " Alt "; ConsoleColorOriginal(); cout << "] 좌표 리스트";
    }

    static void GameInterfaceScreen() {
        ConsoleClear();
        Gotoxy(0,0); 
        cout << "┌───────────────────────────────────────────────────────────────────────────────┬─────────────────┐\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "│                                                                               │                 │\n";
        cout << "├───────────────────────────────────────────────────────────────────────────────┴─────────────────┤\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "│                                                                                                 │\n";
        cout << "└─────────────────────────────────────────────────────────────────────────────────────────────────┘\n";

        Screen::GameKeyInformation();
    }
}

