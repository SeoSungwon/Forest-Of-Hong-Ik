
#pragma once

#include "GameMap.hpp"

class GameMainMap : public GameMap {
public:
    GameMainMap() : GameMap() {
        constexpr auto gameMapTextFileName = "GameMap.txt";
        constexpr auto gameMapDataTextFileName = "GameMapData.txt";

        constexpr auto map_top_left_corner_x = 17;
        constexpr auto map_top_left_corner_y = 5;

        constexpr auto game_map_view_size_x = 39;
        constexpr auto game_map_view_size_y = 19;

        // 포인터 클래스 초기화.
        gameMapManager = new GetGameMapManager(gameMapTextFileName, gameMapDataTextFileName,
            map_top_left_corner_x, map_top_left_corner_y,
            game_map_view_size_x, game_map_view_size_y);

        
    } ~GameMainMap() { delete gameMapManager; }
};