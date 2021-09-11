
#pragma once

#include "PlayerInformation.hpp"
#include "GameMap.hpp"

enum class ctrlToMovePlayerReturnValue {
    R_NOTHING,
    R_CONTINUE,
    R_EXIT
}; typedef ctrlToMovePlayerReturnValue CT_RETURN_VALUE;

class Player : public PlayerInformation {
private: // private class membar
   
private: // private functions
    // Ctrl to move
    void Move_map_with_player_x(GameMap *specific_map, const int append_map_print_interval_x);
    void Move_map_with_player_y(GameMap *specific_map, const int append_map_print_interval_y);

    // direction : 1 -> UP / 2 -> DOWN / 3 -> LEFT / 4 -> RIGHT
    bool Checking_final(const int direction, const int append_x, const int append_y, GameMap* specific_map, MAP_TYPE eType);

    // 플레이어 지우고 그리기
    void erasePlayer(GameMap* specific_map);
    void drawPlayer(GameMap* specific_map, MAP_TYPE player_eType);

public:
    Player() {
    }

    // return : true -> continue / false -> nothing
    CT_RETURN_VALUE ctrlToMovePlayer(GameMap *specific_map);

    void printMap(GameMap *specific_map);
};

void Player::Move_map_with_player_x(GameMap *specific_map, const int append_map_print_interval_x) {
    specific_map->gameMapManager->append_mapTravelDistance_X(append_map_print_interval_x);
}

void Player::Move_map_with_player_y(GameMap *specific_map, const int append_map_print_interval_y) {
    specific_map->gameMapManager->append_mapTravelDistance_Y(append_map_print_interval_y);
}

bool Player::Checking_final(const int direction, const int append_x, const int append_y, GameMap *specific_map, MAP_TYPE eType) {
    /* 장애물이 있는지 검사 */
    if (specific_map->gameMapManager->Check_player_hits_obstacle(direction) == false) {
        return false;
    }
    this->erasePlayer(specific_map);
    /* 플레이어 이동 */
    specific_map->gameMapManager->playerPointer->addX(append_x);
    specific_map->gameMapManager->playerPointer->addY(append_y);
    this->drawPlayer(specific_map, eType);
    /* 맵 어떻게 이동할 지 확인 */
    switch (direction) {
    case 1: // 복쪽으로
        this->Move_map_with_player_y(specific_map, append_y);
        break;
    case 2: // 남쪽으로
        this->Move_map_with_player_y(specific_map, append_y);
        break;
    case 3: // 서쪽으로
        this->Move_map_with_player_x(specific_map, append_x);
        break;
    case 4: // 동쪽으로
        this->Move_map_with_player_x(specific_map, append_x);
        break;
    }
    /* 맵 출력 */
    this->printMap(specific_map);

    return true;
}

void Player::erasePlayer(GameMap *specific_map) {
    specific_map->gameMapManager->changeMapType(
        specific_map->gameMapManager->playerPointer->getX(),
        specific_map->gameMapManager->playerPointer->getY(),
        MAP_TYPE::LAND
    );
}

void Player::drawPlayer(GameMap *specific_map, MAP_TYPE player_eType) {
    specific_map->gameMapManager->changeMapType(
        specific_map->gameMapManager->playerPointer->getX(),
        specific_map->gameMapManager->playerPointer->getY(),
        player_eType
    );
}

CT_RETURN_VALUE Player::ctrlToMovePlayer(GameMap *specific_map) {
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        return CT_RETURN_VALUE::R_EXIT;
    }

    // 플레이어 이동
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (this->Checking_final(1, 0, -1, specific_map, MAP_TYPE::PLAYER_UP) == false) {
            return CT_RETURN_VALUE::R_CONTINUE;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (this->Checking_final(2, 0, 1, specific_map, MAP_TYPE::PLAYER_DOWN) == false) {
            return CT_RETURN_VALUE::R_CONTINUE;
        }
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (this->Checking_final(3, -1, 0, specific_map, MAP_TYPE::PLAYER_LEFT) == false) {
            return CT_RETURN_VALUE::R_CONTINUE;
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (this->Checking_final(4, 1, 0, specific_map, MAP_TYPE::PLAYER_RIGHT) == false) {
            return CT_RETURN_VALUE::R_CONTINUE;
        }
    }

    return CT_RETURN_VALUE::R_NOTHING;
}

void Player::printMap(GameMap *specific_map) {
    // pt = parameter
    const int pt_StartX = specific_map->gameMapManager->get_mapTravelDistance_X();
    const int pt_EndX = 
        specific_map->gameMapManager->get_mapTravelDistance_X() + specific_map->gameMapManager->game_map_view_size_x;
   
    const int pt_StartY = specific_map->gameMapManager->get_mapTravelDistance_Y();
    const int pt_EndY = 
        specific_map->gameMapManager->get_mapTravelDistance_Y() + specific_map->gameMapManager->game_map_view_size_y;

    specific_map->gameMapManager->printGameMap(
        pt_StartX,
        pt_EndX,
        pt_StartY,
        pt_EndY
    );
}