
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
    GameMap *gameMainMap;

    // �÷��̾� ���� ��
    GameMap *playerHouseMap;

    // �÷��̾� ����
    Player* player;

    // ������ ����Ʈ Ŭ����
    PointerListScreen pointerListScreen;

public:
    GameScreen() {
        // �� ����
        this->gameMainMap =    new GameMainMap();
        this->playerHouseMap = new PlayerHouseMap();

        // �÷��̾� �ʱ� ����
        this->player = new Player();

        ConsoleSize(GAME_SCREEN_X, GAME_SCREEN_Y);

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
    this->gameMainMap->gameMapManager->printGameMap(
        0, this->gameMainMap->gameMapManager->game_map_view_size_x, 0, this->gameMainMap->gameMapManager->game_map_view_size_y
    );
    while (true) {
        // �÷��̾� �̵�
        CT_RETURN_VALUE return_value = this->player->ctrlToMovePlayer(this->gameMainMap);
        
        if (return_value == CT_RETURN_VALUE::R_CONTINUE) continue;
        else if (return_value == CT_RETURN_VALUE::R_EXIT) break;

        // �������� �� �� �ִ� ���� �����
        constexpr auto ENTER_BUILDING_KEY = VK_CONTROL;
        if (GetAsyncKeyState(ENTER_BUILDING_KEY) & 0x8000) {
            // ��ó�� �� �� �ִ� �ǹ��� �ִ��� �˻�
            switch (this->gameMainMap->gameMapManager->Check_for_buildings_near_player()) {
            case MAP_TYPE::PLAYER_HOUSE:
                // TODO : �÷��̾ ���� ���� �� �� �� �ִ� ���񽺸� ������.
                if (this->gameMainMap->gameMapManager->saveGameMap() == false) {
                    exit(1);
                }
                System_Message::System_coming_soon_service();
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
                this->gameMainMap->gameMapManager->playerPointer->getX(), this->gameMainMap->gameMapManager->playerPointer->getY()
            );

            // �ٽ� ���
            Screen::GameInterfaceScreen();
            this->player->printMap(gameMainMap);
        }

        Gotoxy(85, 2);
        std::cout << this->gameMainMap->gameMapManager->playerPointer->getX() - 18 << " : " << this->gameMainMap->gameMapManager->playerPointer->getY() - 6 << "    ";

        Gotoxy(85, 4);
        std::cout << this->player->mapTravelDistance_X << " : " << this->player->mapTravelDistance_Y << "   ";
    }
}
