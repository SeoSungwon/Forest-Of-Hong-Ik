
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
    // ������ ����Ʈ
    vector<PointerDetail*> pointerList;

    void printScreen() {
        Screen::GameEmptyScreen();

        const string strTitle = "Point List";
        const int strTitlePosX = GAME_SCREEN_X / 2 - strTitle.length() / 2;
        const int strTitlePosY = 2;

        Gotoxy(strTitlePosX, strTitlePosY); cout << strTitle;

        Gotoxy(2, strTitlePosY); cout << "=========================================";
        Gotoxy(strTitlePosX + strTitle.length() + 2, strTitlePosY); cout << "=========================================";

        constexpr auto line_spacing = 25;

        // �� ���
        for (int i = 4; i < 27; i++) {
            for (int j = 1; j < 4; j++) {
                Gotoxy(line_spacing * j, i); cout << "��";
            }
        }

        // Ű ���
        Gotoxy(2, 1);  cout << "[ "; ConsoleColor(LIGHTRED); cout << "X"; ConsoleColor(WHITE); cout << " ] �ڷΰ���";
        Gotoxy(83, 1); cout << "[ "; ConsoleColor(LIGHTBLUE); cout << "C"; ConsoleColor(WHITE); cout << " ] ��ǥ �߰�";
    }
    void printCreateBox() {
        Gotoxy(21, 5); cout << "������������������������������������ "; Sleep(10);
        Gotoxy(21, 6); cout << "�� X �Է� -> ��� �� �� "; Sleep(10);
        Gotoxy(21, 7); cout << "������������������������������������ �� "; Sleep(10);
        Gotoxy(21, 8); cout << " __________________/"; Sleep(10);

        Gotoxy(21, 10); cout << "���������������������������������������������������������������������������������������������������������������������� "; Sleep(10);
        Gotoxy(21, 11); cout << "��                                                         �� �� "; Sleep(10);
        Gotoxy(21, 12); cout << "�� ��ǥ �̸� :                                             �� �� "; Sleep(10);
        Gotoxy(21, 13); cout << "��                                                         �� �� "; Sleep(10);
        Gotoxy(21, 14); cout << "���������������������������������������������������������������������������������������������������������������������� �� "; Sleep(10);
        Gotoxy(21, 15); cout << " ___________________________________________________________/"; Sleep(10);

        Gotoxy(21, 17); cout << "������������������������������������������������������������������������������������������ "; Sleep(10);
        Gotoxy(21, 18); cout << "�� ";
        ConsoleColor(LIGHTRED); cout << "�� �ڽ��� ��ġ�ϴ� ���� ��ǥ�� �߰��մϴ�"; ConsoleColorOriginal();
        cout << " �� �� "; Sleep(10);
        Gotoxy(21, 19); cout << "������������������������������������������������������������������������������������������ �� "; Sleep(10);
        Gotoxy(21, 20); cout << " _____________________________________________/"; Sleep(10);
    }
public:
    ~PointerListScreen() {
        for (int i = 0; i < pointerList.size(); i++) {
            delete pointerList.at(i);
        } pointerList.clear();
    }
    void Run(const int playerX, const int playerY) {
        // altŰ�� ������ Run�Լ��� ���� ��Ų��. 
        // y Ű�� ������ �ڽ�(�÷��̾�)�� ��ǥ�� ��ǥ�� �߰���Ų��.
        // x Ű�� ������ ��������.

        // �ѱ��� ���� �Ǵ� ������ �Էµ� ���� �˻��ϱ� ���� �迭
        
        auto lamda_print_pointList = [=]() {
            constexpr auto first_pointer_print = 5;
            // ��ǥ�� ���
            for (int i = 0; i < pointerList.size(); i++) {
                Gotoxy(2, 5 * (i + 1));
                cout << i + 1 << ". " << this->pointerList.at(i)->getPointerName();
            }
        };

        this->printScreen();
        lamda_print_pointList();

        while (true) {
            // _getch()�� ����
            if (_kbhit()) {
                switch (_getch()) {
                case static_cast<char>(ePls::EXIT_AND_END_KEY_LOWER):
                case static_cast<char>(ePls::EXIT_AND_END_KEY_UPPER):
                 // �ڷΰ���
                return;
                case static_cast<char>(ePls::CREATE_KEY_LOWER):
                case static_cast<char>(ePls::CREATE_KEY_UPPER):
                // ��ǥ�� �߰���Ų��.
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
                        } else { // x �Է��� ���� ������
                            this->pointerList.push_back(new PointerDetail(playerX, playerY, inputPointerName));
                            // �ٽ� ���
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