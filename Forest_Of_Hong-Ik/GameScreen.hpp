
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
    GameMap *gameMainMap;

    // 플레이어 집안 맵
    GameMap *playerHouseMap;

    // 플레이어 설정
    Player* player;

    // 포인터 리스트 클래스
    PointerListScreen pointerListScreen;

public:
    GameScreen() {
        // 맵 설정
        this->gameMainMap =    new GameMainMap();
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
    this->gameMainMap->gameMapManager->printGameMap(
        0, this->gameMainMap->gameMapManager->game_map_view_size_x, 0, this->gameMainMap->gameMapManager->game_map_view_size_y
    );
    while (true) {
        // 플레이어 이동
        CT_RETURN_VALUE return_value = this->player->ctrlToMovePlayer(this->gameMainMap);
        
        if (return_value == CT_RETURN_VALUE::R_CONTINUE) continue;
        else if (return_value == CT_RETURN_VALUE::R_EXIT) break;

        // 구조물에 들어갈 수 있는 로직 만들기
        constexpr auto ENTER_BUILDING_KEY = VK_CONTROL;
        if (GetAsyncKeyState(ENTER_BUILDING_KEY) & 0x8000) {
            // 근처에 들어갈 수 있는 건물이 있는지 검사
            switch (this->gameMainMap->gameMapManager->Check_for_buildings_near_player()) {
            case MAP_TYPE::PLAYER_HOUSE:
                // TODO : 플레이어가 집에 들어가서 뭘 할 수 있는 서비스를 만들어라.
                if (this->gameMainMap->gameMapManager->saveGameMap() == false) {
                    exit(1);
                }
                System_Message::System_coming_soon_service();
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
            this->player->printMap(gameMainMap);
        }

        Gotoxy(85, 2);
        std::cout << this->gameMainMap->gameMapManager->playerPointer->getX() - 18 << " : " << this->gameMainMap->gameMapManager->playerPointer->getY() - 6 << "    ";

        Gotoxy(85, 4);
        std::cout << this->player->mapTravelDistance_X << " : " << this->player->mapTravelDistance_Y << "   ";
    }
}
