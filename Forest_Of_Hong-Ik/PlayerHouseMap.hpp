
#pragma once

#include "GameMap.hpp"

// 플레이어가 집에 들어 갈 때
// 할 수 있는 것
// 1. 잠자기
// 2. 상자 - 기본 하나 준다. ( 상점에서 사서 추가 할 지는 모르겠음 )

// 로직 - 플레이어를 움직여서 선택

class PlayerHouseMap : public GameMap {
public:
	PlayerHouseMap() : GameMap() {
		constexpr auto fileName = "PlayerHouseMap.txt";
		constexpr auto fileDataName = "PlayerHouseMapData.txt";

		constexpr auto map_top_left_corner_x = 17;
		constexpr auto map_top_left_corner_y = 5;
		
		constexpr auto game_map_view_size_x = 39;
		constexpr auto game_map_view_size_y = 19;

		// 포인터 클래스 초기화
		gameMapManager = new GetGameMapManager(fileName, fileDataName,
			map_top_left_corner_x, map_top_left_corner_y,
			game_map_view_size_x, game_map_view_size_y);
	}
	~PlayerHouseMap() { delete gameMapManager; }
};