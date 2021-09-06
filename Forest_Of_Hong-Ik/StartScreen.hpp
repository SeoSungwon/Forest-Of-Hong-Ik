
#include "Screen.hpp"

constexpr auto START_SCREEN_SIZE_X = 77;
constexpr auto START_SCREEN_SIZE_Y = 21;

class StartScreen {
private:
    void getKey() {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                break;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                exit(EXIT_SUCCESS);
            }
        }
    }
public:
    StartScreen() {
        SetCursor(false);

        ConsoleSize(START_SCREEN_SIZE_X, START_SCREEN_SIZE_Y);

        ConsoleColorOriginal();

        Screen::StartScreen();

        Screen::StartScreen_PlaneForViewing();

        Gotoxy(30, 11); cout << "[       ] 게임 시작";
        Gotoxy(30, 13); cout << " [     ]  게임 종료";

        ColorAndDownPrint("Forest Of Hong-Ik", 31, 6, GREEN);

        ColorPrint("ENTER", 32, 11, LIGHTGREEN);

        ColorPrint("ESC", 33, 13, LIGHTRED);
    }

    void Run() {
        this->getKey();
    }
};