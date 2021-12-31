
#pragma once

#include "Screen.hpp"
#include "PointerDetail.hpp"

#include <conio.h>
#include <vector>
#include <array>

enum class ePointerListScreenKey {
    EXIT_AND_END_KEY_LOWER = 'x',
    EXIT_AND_END_KEY_UPPER = 'X',
    CREATE_KEY_LOWER = 'c',
    CREATE_KEY_UPPER = 'C'
}; typedef ePointerListScreenKey ePls;

class PointerListScreen {
private:
    // 포인터 리스트
    vector<PointerDetail*> pointerList;

    void printScreen() {
        Screen::GameEmptyScreen();

        Gotoxy(2, 2); cout << "====================================================";
        cout << " Point List "; cout << "====================================================";

        constexpr auto line_spacing = 25;

        // 줄 출력
        for (int i = 4; i < 27; i++) {
            for (int j = 1; j < 4; j++) {
                Gotoxy(line_spacing * j, i); cout << "Ⅱ";
            }
        }

        // 키 출력
        Gotoxy(2, 1);  cout << "[ "; ConsoleColor(LIGHTRED); cout << "X"; ConsoleColor(WHITE); cout << " ] 뒤로가기";
        Gotoxy(83, 1); cout << "[ "; ConsoleColor(LIGHTBLUE); cout << "C"; ConsoleColor(WHITE); cout << " ] 좌표 추가";
    }
    void printCreateBox() {
        Gotoxy(21, 5); cout << "┌────────────────┐ "; Sleep(10);
        Gotoxy(21, 6); cout << "│ X 입력 -> 취소 │ │ "; Sleep(10);
        Gotoxy(21, 7); cout << "└────────────────┘ │ "; Sleep(10);
        Gotoxy(21, 8); cout << " __________________/"; Sleep(10);

        Gotoxy(21, 10); cout << "┌─────────────────────────────────────────────────────────┐ "; Sleep(10);
        Gotoxy(21, 11); cout << "│                                                         │ │ "; Sleep(10);
        Gotoxy(21, 12); cout << "│ 좌표 이름 :                                             │ │ "; Sleep(10);
        Gotoxy(21, 13); cout << "│                                                         │ │ "; Sleep(10);
        Gotoxy(21, 14); cout << "└─────────────────────────────────────────────────────────┘ │ "; Sleep(10);
        Gotoxy(21, 15); cout << " ___________________________________________________________/"; Sleep(10);

        Gotoxy(21, 17); cout << "┌───────────────────────────────────────────┐ "; Sleep(10);
        Gotoxy(21, 18); cout << "│ ";
        ConsoleColor(LIGHTRED); cout << "※ 자신이 위치하는 곳의 좌표를 추가합니다"; ConsoleColorOriginal();
        cout << " │ │ "; Sleep(10);
        Gotoxy(21, 19); cout << "└───────────────────────────────────────────┘ │ "; Sleep(10);
        Gotoxy(21, 20); cout << " _____________________________________________/"; Sleep(10);
    }
public:
    ~PointerListScreen() {
        for (int i = 0; i < pointerList.size(); i++) {
            delete pointerList.at(i);
        } pointerList.clear();
    }
    void Run(const int playerX, const int playerY) {
        // alt키를 누르면 Run함수를 실행 시킨다. 
        // y 키를 누르면 자신(플레이어)의 좌표에 좌표를 추가시킨다.
        // x 키를 누르면 나가진다.

        // 한글의 자음 또는 모음만 입력된 것을 검사하기 위한 배열
        
        auto lamda_print_pointList = [=]() {
            constexpr auto first_pointer_print = 5;
            // 좌표들 출력
            for (int i = 0; i < pointerList.size(); i++) {
                Gotoxy(2, 5 * (i + 1));
                cout << i + 1 << ". " << this->pointerList.at(i)->getPointerName();
            }
        };

        this->printScreen();
        lamda_print_pointList();

        while (true) {
            // _getch()로 받음
            if (_kbhit()) {
                switch (_getch()) {
                case static_cast<char>(ePls::EXIT_AND_END_KEY_LOWER):
                case static_cast<char>(ePls::EXIT_AND_END_KEY_UPPER):
                 // 뒤로가기
                return;
                case static_cast<char>(ePls::CREATE_KEY_LOWER):
                case static_cast<char>(ePls::CREATE_KEY_UPPER):
                // 좌표를 추가시킨다.
                    this->printCreateBox();
                    SetCursor(); // true
                    while (true) {
                        Gotoxy(36, 12);
                        string inputPointerName = "";
                        cin >> inputPointerName;
                        if (inputPointerName == "x"
                         || inputPointerName == "X"
                         || inputPointerName == "\n") {
                            this->printScreen();
                            SetCursor(false);
                            break;
                        } else { // x 입력을 받지 않으면
                            this->pointerList.push_back(new PointerDetail(playerX, playerY, inputPointerName));
                            // 다시 출력
                            this->printScreen();
                            lamda_print_pointList();
                            SetCursor(false);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
};