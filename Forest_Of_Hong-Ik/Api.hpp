
#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <locale>
#include <vector>
#include <array>

using namespace std;

constexpr auto number_of_korean_vowel = 21;
const array<string, number_of_korean_vowel> korean_vowel = { "ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ" };
constexpr auto number_of_korean_consonant = 14;
const array<string, number_of_korean_consonant> korean_consonant = { "ㄱ", "ㄴ", "ㄷ", "ㄹ", "ㅁ", "ㅂ", "ㅅ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };

enum Color : int {
	BLACK, BLUE, GREEN, CYAN,
	RED, PURPLE, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN,
	LIGHTCYAN, LIGHTRED, LIGHTPURPLE,
	YELLOW, WHITE
};

// 콘솔 크기 정해줌
static void
ConsoleSize(int console_x, int console_y) {
	string command = "mode con: cols=" + to_string(console_x) + " lines=" + to_string(console_y);

	system(command.c_str());
}

// 콘솔 제목 정해줌
static void
ConsoleTitle(string Title = "NULL") {
	string command = "title " + Title;

	system(command.c_str());
}

// 콘솔 커서 이동
static void
Gotoxy(int x, int y) {
	COORD pos = {};
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 보임 안보임
static void
SetCursor(bool cursor_view = true) {
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = cursor_view; // true 보임, false 안보임

	ConsoleCursor.dwSize = 1; // 커서사이즈

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // 설정
}

// 색상 변경
static void
ConsoleColor(Color forground, Color background = BLACK) {
	int code = forground + background * 16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}

// 원래의 글자 색으로 변경
static void
ConsoleColorOriginal() {
	ConsoleColor(LIGHTGRAY, BLACK);
}

// 콘솔에 출력된 내용들을 지움
static void
ConsoleClear() {
	system("cls");
}

// 색깔출력 = 순차적으로
static void
ColorPrint(const string title, const int title_x, const int title_y, const Color color) {
	for (int i = 0; i < title.length(); i++) {
		Gotoxy(title_x + i, title_y);
		ConsoleColor(color);
		cout << title.at(i);

		Sleep(50);
	}
	ConsoleColorOriginal();
}

// 색깔출력 -> 색깔 원래대로 = 순차적으로
static void
ColorAndDownPrint(const string title, const int title_x, const int title_y, const Color color) {
	for (int i = 0; i < title.length(); i++) {
		Gotoxy(title_x + i, title_y);
		cout << title.at(i);
		ConsoleColorOriginal();

		Sleep(50);

		Gotoxy(title_x + i, 6);
		cout << title.at(i);
		ConsoleColor(color);

	}
	ConsoleColorOriginal();
}
