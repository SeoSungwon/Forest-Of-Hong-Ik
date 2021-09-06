
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
const array<string, number_of_korean_vowel> korean_vowel = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };
constexpr auto number_of_korean_consonant = 14;
const array<string, number_of_korean_consonant> korean_consonant = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };

enum Color : int {
	BLACK, BLUE, GREEN, CYAN,
	RED, PURPLE, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN,
	LIGHTCYAN, LIGHTRED, LIGHTPURPLE,
	YELLOW, WHITE
};

// �ܼ� ũ�� ������
static void
ConsoleSize(int console_x, int console_y) {
	string command = "mode con: cols=" + to_string(console_x) + " lines=" + to_string(console_y);

	system(command.c_str());
}

// �ܼ� ���� ������
static void
ConsoleTitle(string Title = "NULL") {
	string command = "title " + Title;

	system(command.c_str());
}

// �ܼ� Ŀ�� �̵�
static void
Gotoxy(int x, int y) {
	COORD pos = {};
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Ŀ�� ���� �Ⱥ���
static void
SetCursor(bool cursor_view = true) {
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = cursor_view; // true ����, false �Ⱥ���

	ConsoleCursor.dwSize = 1; // Ŀ��������

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}

// ���� ����
static void
ConsoleColor(Color forground, Color background = BLACK) {
	int code = forground + background * 16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}

// ������ ���� ������ ����
static void
ConsoleColorOriginal() {
	ConsoleColor(LIGHTGRAY, BLACK);
}

// �ֿܼ� ��µ� ������� ����
static void
ConsoleClear() {
	system("cls");
}

// ������� = ����������
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

// ������� -> ���� ������� = ����������
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
