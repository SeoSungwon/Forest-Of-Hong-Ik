
#pragma once


#include "PointerListScreen.hpp"
#include "Screen.hpp"
#include "GameMainMap.hpp"
#include "PlayerHouseMap.hpp"
#include "System_Message.hpp"
#include "Player.hpp"

class GameScreen {
private:
    // ���� ���� ��
    GameMap* gameMainMap;

    // �÷��̾� ���� ��
    GameMap* playerHouseMap;

    // �÷��̾� ����
    Player* player;

    // ������ ����Ʈ Ŭ����
    PointerListScreen pointerListScreen;

public:
    GameScreen() {
        // �� ����
        this->gameMainMap = new GameMainMap();
        this->playerHouseMap = new PlayerHouseMap();

        // �÷��̾� �ʱ� ����
        this->player = new Player();

        // ConsoleSize(GAME_SCREEN_X, GAME_SCREEN_Y);
        ConsoleSize(200, 50);

        Screen::GameInterfaceScreen();
    } ~GameScreen() {
        delete gameMainMap;
        delete playerHouseMap;
        delete player;
    }

    // ����
    void Run();
};

void GameScreen::Run() {
    // ó�� �� ���
    this->gameMainMap->gameMapManager->printGameMap();

    auto lamda_print_player_information = [=]() {
        // �÷��̾� ���� ���
        Gotoxy(83, 1);
        cout << "< �÷��̾� ���� >";

        Gotoxy(85, 3);
        cout << "�� ü�� : ";
        Gotoxy(85, 5);
        cout << "�� ��θ� : ";
        Gotoxy(85, 7);
        cout << "�� �Ƿε� : ";
    };

    lamda_print_player_information();

    while (true) {
        // �÷��̾� �̵�
        CT_RETURN_VALUE return_value_for_gameMainMap = this->player->ctrlToMovePlayer(this->gameMainMap);

        if (return_value_for_gameMainMap == CT_RETURN_VALUE::R_CONTINUE) continue;
        else if (return_value_for_gameMainMap == CT_RETURN_VALUE::R_EXIT) {
            if (this->gameMainMap->gameMapManager->saveGameMapAndData() == true) {
                exit(1);
            }
            else exit(1);
        }

        // �������� �� �� �ִ� ���� �����
        constexpr auto ENTER_BUILDING_KEY = VK_CONTROL;
        if (GetAsyncKeyState(ENTER_BUILDING_KEY) & 0x8000) {
            // ��ó�� �� �� �ִ� �ǹ��� �ִ��� �˻�
            switch (this->gameMainMap->gameMapManager->Check_for_buildings_near_player()) {
            case MAP_TYPE::PLAYER_HOUSE:
                // �� �����ϰ� �ٸ� ��(��)���� �̵�
                if (this->gameMainMap->gameMapManager->saveGameMapAndData() == false) {
                    exit(1);
                }
                // �÷��̾�� �����̴� ������ ����ϹǷ� ������ �� �ʿ䰡 ����.
                // �÷��̾ ���� �����Ͱ� ���� �� �� �� �������ϴ� �ڵ带 �ۼ��Ѵ�.

                // �� ���
                this->playerHouseMap->gameMapManager->printGameMap();

                while (true) {
                    CT_RETURN_VALUE return_value_for_playerHouseMap = this->player->ctrlToMovePlayer(this->playerHouseMap);

                    if (return_value_for_playerHouseMap == CT_RETURN_VALUE::R_CONTINUE) continue;
                    else if (return_value_for_playerHouseMap == CT_RETURN_VALUE::R_EXIT) break;
                }

                // �÷��̾ ������ playerHouseMap�� ���� �����͸� �����Ѵ�.
                if (this->playerHouseMap->gameMapManager->saveGameMapAndData() == false) {
                    exit(1);
                }

                // gameMainMap�� ������ش�.
                this->gameMainMap->gameMapManager->printGameMap();
                break;
            default: // �ֺ��� �� �ǹ��� ���� ���
                System_Message::System_There_is_not_building_near_player();
                break;
            }
        }
        // �÷��̾� ������ ����Ʈ
        constexpr auto OPEN_POINTER_LIST_KEY = VK_MENU; // It is Alt Key
        if (GetAsyncKeyState(OPEN_POINTER_LIST_KEY) & 0x8000) {
            this->pointerListScreen.Run(
                this->gameMainMap->gameMapManager->playerPointer->getX(), 
                this->gameMainMap->gameMapManager->playerPointer->getY()
            );

            // �ٽ� ���
            Screen::GameInterfaceScreen();
            this->gameMainMap->gameMapManager->printGameMap();
        }

        Sleep(10);
    }
}
