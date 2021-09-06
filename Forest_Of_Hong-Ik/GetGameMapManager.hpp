
#pragma once

#include <iostream>
#include <fstream>
#include <string>

constexpr auto TEXT_MAP_FILE_SIZE_X = 400;
constexpr auto TEXT_MAP_FILE_SIZE_Y = 200;

enum MAP_TYPE : int { // Player : 5 ~ 8
	/*OBJECT*/AIR, LAND, ABLE_FARMING_LAND, FENCE, WALL, PLAYER_UP, PLAYER_DOWN, PLAYER_LEFT, PLAYER_RIGHT, PLAYER_HOUSE, PLAYER_BOX,
	/*ANIMALS*/PIG, CHICKEN, COW, DUCK,
	/*VEGETABLE*/PEPPER, CUCUMBER, EGGPLANT, CARROT, DAIKON, SPRING_ONION, TOMATO,
	/*FRUIT*/BANANA, PEACH, APPLE, MANDARIN, GRAPE, PERSIMMON
};

class GetGameMapManager {
private:
	// text���� ������ �迭�� int������ ���� �ִ´�.
	int Map[TEXT_MAP_FILE_SIZE_X][TEXT_MAP_FILE_SIZE_Y];
public:
	int map_top_left_corner_x;
	int map_top_left_corner_y;

	int game_map_view_size_x;
	int game_map_view_size_y;

	Pointer* playerPointer;
	Pointer* playerHousePointer;

	GetGameMapManager(std::string file_name, 
		const int map_top_left_corner_x, const int map_top_left_corner_y,
		const int game_map_view_size_x, const int game_map_view_size_y);
	~GetGameMapManager() {
		delete playerPointer;
		delete playerHousePointer;
	}

	// �� ��� �Լ�
	void printGameMap(const int start_x, const int end_x, const int start_y, const int end_y);
	
	// �� ������Ʈ �ٲٱ�
	void changeMapType(const int object_x, const int object_y, const MAP_TYPE changing_object);

	/*      �÷��̾� �ε��� Ȯ��      */
	// 1 : VK_UP / 2 : VK_DOWN / 3 : VK_LEFT / 4 : VK_RIGHT
	// true : �̵� O / false : �̵� X
	bool Check_player_hits_obstacle(const int direction);

	// �÷��̾� �ʿ� �ǹ��� �ִ��� Ȯ�� true : �ִ�. false : ����.
	MAP_TYPE Check_for_buildings_near_player();
};

GetGameMapManager::GetGameMapManager(std::string file_name, 
	const int map_top_left_corner_x, const int map_top_left_corner_y,
	const int game_map_view_size_x, const int game_map_view_size_y) {

	std::ifstream readMapFile;
	readMapFile.open(file_name);

	// �迭 �ʱ�ȭ(����� ä���)
	for (int array_y = 0; array_y < TEXT_MAP_FILE_SIZE_Y; array_y++) {
		for (int array_x = 0; array_x < TEXT_MAP_FILE_SIZE_X; array_x++) {
			this->Map[array_y][array_x] = MAP_TYPE::AIR;
		}
	}

	// Ŭ���� ������ �ʱ�ȭ
	this->playerPointer =      NULL;
	this->playerHousePointer = NULL;

	// ���� ���� �ֱ�
	this->map_top_left_corner_x = map_top_left_corner_x;
	this->map_top_left_corner_y = map_top_left_corner_y;

	this->game_map_view_size_x = game_map_view_size_x;
	this->game_map_view_size_y = game_map_view_size_y;

	// �� �� �� �о� ���� mapLine�� 1�� ���ϸ鼭 ���� ���� �о��.
	int mapLine = 0;

	if (readMapFile.is_open()) {
		while (!readMapFile.eof()) {
			std::string str;
			std::getline(readMapFile, str);

			for (int string_position = 0; string_position < str.length(); string_position++) {
				/*
				Ex Code :
					char chr = '1';
					int num = char - '0';
					cout << num; => 1 ���
				Explanation :
					������ �ƽ�Ű ���� 48������ 0~9�� �Ҵ��ϰ� �����Ƿ�, char�� '1'�� ������ 49�� ������.
					���� 0�� �ƽ�Ű ���� 48�� char���� ������ ���ָ� ������ ���ڸ� �� �� �ִ�.
				*/
				this->Map[mapLine][string_position] = (int)(str.at(string_position) - '0');

				// �ǹ� �Ǵ� ���𰡸� �� �� �ִ� �������� �����͸� ������.
				if (this->Map[mapLine][string_position] >= MAP_TYPE::PLAYER_UP
					&& this->Map[mapLine][string_position] <= MAP_TYPE::PLAYER_RIGHT) {
					const int playerX = string_position;
					const int playerY = mapLine;
					this->playerPointer = new Pointer(playerX, playerY);
				}
				if (Map[mapLine][string_position] == MAP_TYPE::PLAYER_HOUSE) {
					const int houseX = string_position;
					const int houseY = mapLine;
					this->playerHousePointer = new Pointer(houseX, houseY);
				}
				if (this->Map[mapLine][string_position] == MAP_TYPE::PLAYER_BOX) {

				}
			}
			mapLine++;
		}
	}
}

void GetGameMapManager::printGameMap(const int start_x, const int end_x, const int start_y, const int end_y) {
	int mapY = 1;

	for (int i = this->map_top_left_corner_y + start_y; i < this->map_top_left_corner_y + end_y; i++) {
		Gotoxy(2, mapY);

		// MAP_TYPE�� ���� ������Ʈ ���
		for (int j = this->map_top_left_corner_x + start_x; j < this->map_top_left_corner_x + end_x; j++) {
			if (Map[i][j] == AIR) { // ����
				ConsoleColor(BLACK, BLACK);
				cout << "  ";
				ConsoleColorOriginal();
			}
			if (Map[i][j] == LAND) { // ��
				ConsoleColor(BLACK, BLACK);
				cout << "  ";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == WALL) { // ��
				ConsoleColor(DARKGRAY, DARKGRAY);
				cout << "��";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_UP) { // ���� ���� �÷��̾�
				ConsoleColor(YELLOW);
				cout << "��";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_DOWN) { // ���� ���� �÷��̾�
				ConsoleColor(YELLOW);
				cout << "��";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_LEFT) { // ���� ���� �÷��̾�
				ConsoleColor(YELLOW);
				cout << "��";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_RIGHT) { // ���� ���� �÷��̾�
				ConsoleColor(YELLOW);
				cout << "��";
			}
			else if (Map[i][j] == PLAYER_HOUSE) { // �÷��̾� ��
				ConsoleColor(YELLOW, BLACK);
				cout << "��";
				ConsoleColorOriginal();
			}
			else {
				continue;
			}
		}
		mapY++;
	}
}

void GetGameMapManager::changeMapType(const int object_x, const int object_y, const MAP_TYPE changing_object) {
	this->Map[object_y][object_x] = changing_object;
}

bool GetGameMapManager::Check_player_hits_obstacle(const int direction) {
	// �ݺ� �Ǵ� �ڵ带 ���� �Լ��� ��ü
	auto lamda_hits_obstacle = [=](const int add_x, const int add_y) {
		// �ڵ尡 �� mapObject��� ������ ���� �����ϰ� ���ش�.
		const auto mapObject = 
			this->Map[this->playerPointer->getY() + add_y][this->playerPointer->getX() + add_x];

		// ������ �� �ִ� �� �� �ִ� ���̸� true ��ȯ
		if (mapObject == MAP_TYPE::AIR
			|| mapObject == MAP_TYPE::LAND
			|| mapObject == MAP_TYPE::ABLE_FARMING_LAND) {
			return true;
		}
		// ��� ������ ���� ������(����������) �� �� ������ �� ������(true ��ȯ) "�� ���� �Ϲ� ������ �ٲ۴�".
		else if (mapObject == MAP_TYPE::ABLE_FARMING_LAND) {
			this->Map[this->playerPointer->getY() + add_y][this->playerPointer->getX() + add_x]
				= MAP_TYPE::ABLE_FARMING_LAND;
			return true;
		}
		// �� �̿��� ���� �� ��������(false��ȯ)
		else {
			return false;
		}

		return false;
	};

	/*
	* 1 : UPŰ�� ���� �÷��̾�
	* 2 : DOWNŰ�� ���� �÷��̾�
	* 3 : LEFTŰ�� ���� �÷��̾�
	* 4 : RIGHTŰ�� ���� �÷��̾�
	*/

	if (direction >= 1 && direction <= 4) {
		if (direction == 1) {
			// ���� �ִ� ��ü�� ���θ� ���� ���� �Ű����� add_y�� -1�� �ִ´�.
			return lamda_hits_obstacle(0, -1);
		}
		else if (direction == 2) {
			// �Ʒ��� �ִ� ��ü�� ���θ� ���� ���� �Ű����� add_y�� +1�� �ִ´�.
			return lamda_hits_obstacle(0, +1);
		}
		else if (direction == 3) {
			// ���ʿ� �ִ� ��ü�� ���θ� ���� ���� �Ű����� add_x�� -1�� �ִ´�.
			return lamda_hits_obstacle(-1, 0);
		}
		else if (direction == 4) {
			// �����ʿ� �ִ� ��ü�� ���θ� ���� ���� �Ű����� add_x�� +1�� �ִ´�.
			return lamda_hits_obstacle(+1, 0);
		}
	}
	return false;
}

MAP_TYPE GetGameMapManager::Check_for_buildings_near_player() {
	constexpr auto number_of_buildings = 1;
	const array<int, number_of_buildings> buildings = { MAP_TYPE::PLAYER_HOUSE };

	MAP_TYPE near_player_building = MAP_TYPE::AIR;

	/*
		* �������Ͽ� �÷��̾�� ���� ����� ���� �ǹ��� �ִ��� Ȯ���Ѵ�.
		*             ��
		*        ��  PLAYER ��
		*             ��
		*
	*/

	for (int building_number = 0; building_number < buildings.size(); building_number++) {
		// �÷��̾� �ֺ� ������Ʈ���� �ҷ��´�.
		const int player_up_side_object =    this->Map[this->playerPointer->getY() - 1][this->playerPointer->getX()];
		const int player_down_side_object =  this->Map[this->playerPointer->getY() + 1][this->playerPointer->getX()];
		const int player_left_side_object =  this->Map[this->playerPointer->getY()][this->playerPointer->getX() - 1];
		const int player_right_side_object = this->Map[this->playerPointer->getY()][this->playerPointer->getX() + 1];

		if (player_up_side_object == buildings[building_number] /* �� Ȯ�� */
			|| player_down_side_object == buildings[building_number] /* �Ʒ� Ȯ�� */
			|| player_left_side_object == buildings[building_number] /* ���� Ȯ�� */
			|| player_right_side_object == buildings[building_number] /* ������ Ȯ�� */) {
			near_player_building = (MAP_TYPE)buildings[building_number];
			break;
		}
	}

	return near_player_building;
}