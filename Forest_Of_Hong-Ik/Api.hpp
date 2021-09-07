
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

enum Color : int {
	BLACK, BLUE, GREEN, CYAN,
	RED, PURPLE, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN,
	LIGHTCYAN, LIGHTRED, LIGHTPURPLE,
	YELLOW, WHITE
};

// set console size
static void
ConsoleSize(int console_x, int console_y) {
	string command = "mode con: cols=" + to_string(console_x) + " lines=" + to_string(console_y);

	system(command.c_str());
}

// set console title
static void
ConsoleTitle(string Title = "NULL") {
	string command = "title " + Title;

	system(command.c_str());
}

// set cursor position
static void
Gotoxy(int x, int y) {
	COORD pos = {};
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// true : visible / false : invisible
static void
SetCursor(bool cursor_view = true) {
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = cursor_view;

	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); 
}

// console print font color
static void
ConsoleColor(Color forground, Color background = BLACK) {
	int code = forground + background * 16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}

// console color original
static void
ConsoleColorOriginal() {
	ConsoleColor(LIGHTGRAY, BLACK);
}

// system "cls"
static void
ConsoleClear() {
	system("cls");
}

// Sequentially outputting a string in a specific color
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

// specific_color1 print -> specific_color2 print
// it is used by printing first screen title
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
