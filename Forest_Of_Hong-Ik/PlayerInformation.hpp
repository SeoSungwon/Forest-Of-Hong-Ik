
#pragma once

#include <string>
#include <fstream>
#include <iostream>

class PlayerInformation{
private:
	// Informaions...
	int stamina;
	int stamina_max;
	int full;
	int full_max;
	int tired;
	int tired_max;

public:
	PlayerInformation() {
		const std::string str_file_name = "playerInformation";

		std::ifstream readFile;
		readFile.open(str_file_name, ios::in);
		
		if (readFile.is_open()) {
			std::string str_array[6] = { };
			int array_number = 0;

			while (readFile.eof() == false) {
				std::getline(readFile, str_array[array_number]);
				array_number++;
			}

			this->stamina = atoi(str_array[0].c_str());
			this->stamina_max = atoi(str_array[1].c_str());
			this->full = atoi(str_array[2].c_str());
			this->full_max = atoi(str_array[3].c_str());
			this->tired = atoi(str_array[4].c_str());
			this->tired_max = atoi(str_array[5].c_str());
		}
	}

	int get_stamina() {
		return stamina;
	}
	int get_stamina_max() {
		return stamina_max;
	}
	int get_be_full() {
		return full;
	}
	int get_be_full_max() {
		return full_max;
	}
	int get_tired() {
		return tired;
	}
	int get_tired_max() {
		return tired_max;
	}

	void append_stamina(int append_number) {
		this->stamina += append_number;
	}
	void append_full(int append_number) {
		this->full += append_number;
	}
	void append_tired(int append_number) {
		this->tired += append_number;
	}
};