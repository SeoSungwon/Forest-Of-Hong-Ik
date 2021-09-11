
#pragma once

#include "GameMap.hpp"

// �÷��̾ ���� ��� �� ��
// �� �� �ִ� ��
// 1. ���ڱ�
// 2. ���� - �⺻ �ϳ� �ش�. ( �������� �缭 �߰� �� ���� �𸣰��� )

// ���� - �÷��̾ �������� ����

class PlayerHouseMap : public GameMap {
public:
	PlayerHouseMap() : GameMap() {
		constexpr auto fileName = "PlayerHouseMap.txt";
		constexpr auto fileDataName = "PlayerHouseMapData.txt";

		constexpr auto map_top_left_corner_x = 17;
		constexpr auto map_top_left_corner_y = 5;
		
		constexpr auto game_map_view_size_x = 39;
		constexpr auto game_map_view_size_y = 19;

		// ������ Ŭ���� �ʱ�ȭ
		gameMapManager = new GetGameMapManager(
			fileName, fileDataName,
			map_top_left_corner_x, map_top_left_corner_y,
			game_map_view_size_x, game_map_view_size_y);
	}
	~PlayerHouseMap() { delete gameMapManager; }
};