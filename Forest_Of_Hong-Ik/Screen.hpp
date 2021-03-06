
#pragma once

#include "Api.hpp"

constexpr auto GAME_SCREEN_X = 100;
constexpr auto GAME_SCREEN_Y = 29;

namespace Screen {
    static void StartScreen() {
        ConsoleClear();
        Gotoxy(0, 0);  cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
        Gotoxy(0, 1);  cout << "弛                                                                          弛";
        Gotoxy(0, 2);  cout << "弛                                                                          弛";
        Gotoxy(0, 3);  cout << "弛                                                                          弛";
        Gotoxy(0, 4);  cout << "弛                                                                          弛";
        Gotoxy(0, 5);  cout << "弛                                                                          弛";
        Gotoxy(0, 6);  cout << "弛                                                                          弛";
        Gotoxy(0, 7);  cout << "弛                                                                          弛";
        Gotoxy(0, 8);  cout << "弛                                                                          弛";
        Gotoxy(0, 9);  cout << "弛                                                                          弛";
        Gotoxy(0, 10); cout << "弛                                                                          弛";
        Gotoxy(0, 11); cout << "弛                                                                          弛";
        Gotoxy(0, 12); cout << "弛                                                                          弛";
        Gotoxy(0, 13); cout << "弛                                                                          弛";
        Gotoxy(0, 14); cout << "弛                                                                          弛";
        Gotoxy(0, 15); cout << "弛                                                                          弛";
        Gotoxy(0, 16); cout << "弛                                                                          弛";
        Gotoxy(0, 17); cout << "弛                                                                          弛";
        Gotoxy(0, 18); cout << "弛                                                                          弛";
        Gotoxy(0, 19); cout << "弛                                                                          弛";
        Gotoxy(0, 20); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
    }

    static void StartScreen_PlaneForViewing() {
        ConsoleColor(GREEN);
        Gotoxy(2, 1);  cout << "        ㄒ                                                          ㄒ   ";
        Gotoxy(2, 2);  cout << "ㄒ                                                      ㄒ               ";
        Gotoxy(2, 3);  cout << "               ㄒ                                                ㄒ      ";
        Gotoxy(2, 4);  cout << "   ㄒ                                                                  ㄒ";
        Gotoxy(2, 5);  cout << "         ㄒ                                                 ㄒ           ";
        Gotoxy(2, 6);  cout << "  ㄒ                                                              ㄒ     ";
        Gotoxy(2, 7);  cout << "          ㄒ                                           ㄒ                ";
        Gotoxy(2, 8);  cout << "     ㄒ                                                             ㄒ   ";
        Gotoxy(2, 9);  cout << "              ㄒ                                                 ㄒ      ";
        Gotoxy(2, 10); cout << " ㄒ                                                      ㄒ              ";
        Gotoxy(2, 12); cout << "            ㄒ                                                       ㄒ  ";
        Gotoxy(2, 13); cout << "    ㄒ                                                     ㄒ            ";
        Gotoxy(2, 14); cout << "ㄒ                                                                 ㄒ    ";
        Gotoxy(2, 15); cout << "         ㄒ                                                   ㄒ         ";
        Gotoxy(2, 16); cout << "  ㄒ                                                     ㄒ              ";
        Gotoxy(2, 17); cout << "              ㄒ                                                 ㄒ      ";
        Gotoxy(2, 18); cout << "       ㄒ                                                             ㄒ ";
        Gotoxy(2, 19); cout << "ㄒ                                                           ㄒ          ";
        ConsoleColorOriginal();
    }

    static void GameEmptyScreen() {
        ConsoleClear();
        Gotoxy(0,0); 
        cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
    }

    static void GameKeyInformation() {
        Gotoxy(70, 24);
        cout << "["; ConsoleColor(LIGHTRED); cout << " Ctrl "; ConsoleColorOriginal(); cout << "] 菟橫陛晦";
        cout << "  ["; ConsoleColor(BLUE); cout << " Alt "; ConsoleColorOriginal(); cout << "] 謝ル 葬蝶お";
    }

    static void GameInterfaceScreen() {
        ConsoleClear();
        Gotoxy(0,0); 
        cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "弛                                                                               弛                                             弛\n";
        cout << "戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "弛                                                                                                                             弛\n";
        cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";

        Screen::GameKeyInformation();
    }
}

