
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
	// text파일 정보를 배열에 int형으로 집어 넣는다.
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

	// 맵 출력 함수
	void printGameMap(const int start_x, const int end_x, const int start_y, const int end_y);
	
	// 맵 오브젝트 바꾸기
	void changeMapType(const int object_x, const int object_y, const MAP_TYPE changing_object);

	/*      플레이어 부딪힘 확인      */
	// 1 : VK_UP / 2 : VK_DOWN / 3 : VK_LEFT / 4 : VK_RIGHT
	// true : 이동 O / false : 이동 X
	bool Check_player_hits_obstacle(const int direction);

	// 플레이어 쪽에 건물이 있는지 확인 true : 있다. false : 없다.
	MAP_TYPE Check_for_buildings_near_player();
};

GetGameMapManager::GetGameMapManager(std::string file_name, 
	const int map_top_left_corner_x, const int map_top_left_corner_y,
	const int game_map_view_size_x, const int game_map_view_size_y) {

	std::ifstream readMapFile;
	readMapFile.open(file_name);

	// 배열 초기화(공기로 채우기)
	for (int array_y = 0; array_y < TEXT_MAP_FILE_SIZE_Y; array_y++) {
		for (int array_x = 0; array_x < TEXT_MAP_FILE_SIZE_X; array_x++) {
			this->Map[array_y][array_x] = MAP_TYPE::AIR;
		}
	}

	// 클래스 포인터 초기화
	this->playerPointer =      NULL;
	this->playerHousePointer = NULL;

	// 변수 집어 넣기
	this->map_top_left_corner_x = map_top_left_corner_x;
	this->map_top_left_corner_y = map_top_left_corner_y;

	this->game_map_view_size_x = game_map_view_size_x;
	this->game_map_view_size_y = game_map_view_size_y;

	// 한 줄 씩 읽어 내고 mapLine에 1를 더하면서 다음 줄을 읽어낸다.
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
					cout << num; => 1 출력
				Explanation :
					숫자의 아스키 값은 48번부터 0~9를 할당하고 있으므로, char형 '1'은 정수값 49를 가진다.
					따라서 0의 아스키 값인 48을 char형의 값에서 빼주면 순수한 숫자를 얻어낼 수 있다.
				*/
				this->Map[mapLine][string_position] = (int)(str.at(string_position) - '0');

				// 건물 또는 무언가를 할 수 있는 구조물의 포인터를 저장함.
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

		// MAP_TYPE에 따른 오브젝트 출력
		for (int j = this->map_top_left_corner_x + start_x; j < this->map_top_left_corner_x + end_x; j++) {
			if (Map[i][j] == AIR) { // 공기
				ConsoleColor(BLACK, BLACK);
				cout << "  ";
				ConsoleColorOriginal();
			}
			if (Map[i][j] == LAND) { // 땅
				ConsoleColor(BLACK, BLACK);
				cout << "  ";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == WALL) { // 벽
				ConsoleColor(DARKGRAY, DARKGRAY);
				cout << "■";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_UP) { // 북쪽 보는 플레이어
				ConsoleColor(YELLOW);
				cout << "▲";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_DOWN) { // 남쪽 보는 플레이어
				ConsoleColor(YELLOW);
				cout << "▼";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_LEFT) { // 서쪽 보는 플레이어
				ConsoleColor(YELLOW);
				cout << "◀";
				ConsoleColorOriginal();
			}
			else if (Map[i][j] == PLAYER_RIGHT) { // 동쪽 보는 플레이어
				ConsoleColor(YELLOW);
				cout << "▶";
			}
			else if (Map[i][j] == PLAYER_HOUSE) { // 플레이어 집
				ConsoleColor(YELLOW, BLACK);
				cout << "집";
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
	// 반복 되는 코드를 람다 함수로 대체
	auto lamda_hits_obstacle = [=](const int add_x, const int add_y) {
		// 코드가 길어서 mapObject라는 변수를 만들어서 간결하게 해준다.
		const auto mapObject = 
			this->Map[this->playerPointer->getY() + add_y][this->playerPointer->getX() + add_x];

		// 지나갈 수 있는 갈 수 있는 것이면 true 반환
		if (mapObject == MAP_TYPE::AIR
			|| mapObject == MAP_TYPE::LAND
			|| mapObject == MAP_TYPE::ABLE_FARMING_LAND) {
			return true;
		}
		// 농사 가능한 밭을 갈려고(짓밟을려고) 할 때 지나갈 수 있으며(true 반환) "그 땅은 일반 땅으로 바꾼다".
		else if (mapObject == MAP_TYPE::ABLE_FARMING_LAND) {
			this->Map[this->playerPointer->getY() + add_y][this->playerPointer->getX() + add_x]
				= MAP_TYPE::ABLE_FARMING_LAND;
			return true;
		}
		// 그 이외의 것은 못 지나간다(false반환)
		else {
			return false;
		}

		return false;
	};

	/*
	* 1 : UP키를 누른 플레이어
	* 2 : DOWN키를 누른 플레이어
	* 3 : LEFT키를 누른 플레이어
	* 4 : RIGHT키를 누른 플레이어
	*/

	if (direction >= 1 && direction <= 4) {
		if (direction == 1) {
			// 위에 있는 물체의 여부를 묻기 위해 매개변수 add_y에 -1을 넣는다.
			return lamda_hits_obstacle(0, -1);
		}
		else if (direction == 2) {
			// 아래에 있는 물체의 여부를 묻기 위해 매개변수 add_y에 +1를 넣는다.
			return lamda_hits_obstacle(0, +1);
		}
		else if (direction == 3) {
			// 왼쪽에 있는 물체의 여부를 묻기 위해 매개변수 add_x에 -1를 넣는다.
			return lamda_hits_obstacle(-1, 0);
		}
		else if (direction == 4) {
			// 오른쪽에 있는 물체의 여부를 묻기 위해 매개변수 add_x에 +1를 넣는다.
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
		* 동서남북에 플레이어와 가장 가까운 곳에 건물이 있는지 확인한다.
		*             ■
		*        ■  PLAYER ■
		*             ■
		*
	*/

	for (int building_number = 0; building_number < buildings.size(); building_number++) {
		// 플레이어 주변 오브젝트들을 불러온다.
		const int player_up_side_object =    this->Map[this->playerPointer->getY() - 1][this->playerPointer->getX()];
		const int player_down_side_object =  this->Map[this->playerPointer->getY() + 1][this->playerPointer->getX()];
		const int player_left_side_object =  this->Map[this->playerPointer->getY()][this->playerPointer->getX() - 1];
		const int player_right_side_object = this->Map[this->playerPointer->getY()][this->playerPointer->getX() + 1];

		if (player_up_side_object == buildings[building_number] /* 위 확인 */
			|| player_down_side_object == buildings[building_number] /* 아래 확인 */
			|| player_left_side_object == buildings[building_number] /* 왼쪽 확인 */
			|| player_right_side_object == buildings[building_number] /* 오른쪽 확인 */) {
			near_player_building = (MAP_TYPE)buildings[building_number];
			break;
		}
	}

	return near_player_building;
}