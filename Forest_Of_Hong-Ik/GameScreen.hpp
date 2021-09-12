
#pragma once


#include "PointerListScreen.hpp"
#include "Screen.hpp"
#include "GameMainMap.hpp"
#include "PlayerHouseMap.hpp"
#include "System_Message.hpp"
#include "Player.hpp"

class GameScreen {
private:
    // 메인 게임 맵
    GameMap* gameMainMap;

    // 플레이어 집안 맵
    GameMap* playerHouseMap;

    // 플레이어 설정
    Player* player;

    // 포인터 리스트 클래스
    PointerListScreen pointerListScreen;

public:
    GameScreen() {
        // 맵 설정
        this->gameMainMap = new GameMainMap();
        this->playerHouseMap = new PlayerHouseMap();

        // 플레이어 초기 설정
        this->player = new Player();

        ConsoleSize(GAME_SCREEN_X, GAME_SCREEN_Y);

        Screen::GameInterfaceScreen();
    } ~GameScreen() {
        delete gameMainMap;
        delete playerHouseMap;
        delete player;
    }

    // 실행
    void Run();
};

void GameScreen::Run() {
    // 처음 맵 출력
    this->gameMainMap->gameMapManager->printGameMap();

    while (true) {
        // 플레이어 이동
        CT_RETURN_VALUE return_value_for_gameMainMap = this->player->ctrlToMovePlayer(this->gameMainMap);

        if (return_value_for_gameMainMap == CT_RETURN_VALUE::R_CONTINUE) continue;
        else if (return_value_for_gameMainMap == CT_RETURN_VALUE::R_EXIT) return;

        // 구조물에 들어갈 수 있는 로직 만들기
        constexpr auto ENTER_BUILDING_KEY = VK_CONTROL;
        if (GetAsyncKeyState(ENTER_BUILDING_KEY) & 0x8000) {
            // 근처에 들어갈 수 있는 건물이 있는지 검사
            switch (this->gameMainMap->gameMapManager->Check_for_buildings_near_player()) {
            case MAP_TYPE::PLAYER_HOUSE:
                // 맵 저장하고 다른 맵(집)으로 이동
                if (this->gameMainMap->gameMapManager->saveGameMapAndData() == false) {
                    exit(1);
                }
                // 플레이어는 움직이는 로직을 담당하므로 재정의 할 필요가 없다.
                // 플레이어에 대한 데이터가 생길 때 그 때 재정의하는 코드를 작성한다.

                // 맵 출력
                this->playerHouseMap->gameMapManager->printGameMap();

                while (true) {
                    CT_RETURN_VALUE return_value_for_playerHouseMap = this->player->ctrlToMovePlayer(this->playerHouseMap);

                    if (return_value_for_playerHouseMap == CT_RETURN_VALUE::R_CONTINUE) continue;
                    else if (return_value_for_playerHouseMap == CT_RETURN_VALUE::R_EXIT) break;
                }

                // 플레이어가 나오면 playerHouseMap에 대한 데이터를 저장한다.
                if (this->playerHouseMap->gameMapManager->saveGameMapAndData() == false) {
                    exit(1);
                }

                // gameMainMap을 출력해준다.
                this->gameMainMap->gameMapManager->printGameMap();
                break;
            default: // 주변에 들어갈 건물이 없을 경우
                System_Message::System_There_is_not_building_near_player();
                break;
            }
        }
        // 플레이어 포인터 리스트
        constexpr auto OPEN_POINTER_LIST_KEY = VK_MENU; // It is Alt Key
        if (GetAsyncKeyState(OPEN_POINTER_LIST_KEY) & 0x8000) {
            this->pointerListScreen.Run(
                this->gameMainMap->gameMapManager->playerPointer->getX(), this->gameMainMap->gameMapManager->playerPointer->getY()
            );

            // 다시 출력
            Screen::GameInterfaceScreen();
            this->gameMainMap->gameMapManager->printGameMap();
        }

        Gotoxy(85, 2);
        std::cout << this->gameMainMap->gameMapManager->playerPointer->getX() - 18 << " : " << this->gameMainMap->gameMapManager->playerPointer->getY() - 6 << "    ";

        Gotoxy(85, 4);
        std::cout << this->gameMainMap->gameMapManager->get_mapTravelDistance_X() << " : " << this->gameMainMap->gameMapManager->get_mapTravelDistance_Y() << "   ";

        Sleep(10);
    }
}
