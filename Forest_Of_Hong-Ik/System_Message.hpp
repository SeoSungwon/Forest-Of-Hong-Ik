
#pragma once

#include "Api.hpp"

namespace System_Message {
    static void System_Message_Clear() {
        // y : 22 ~ 27
        Gotoxy(2, 21);
        cout << "                                                         ";
        Gotoxy(2, 22);
        cout << "                                                         ";
        Gotoxy(2, 23);
        cout << "                                                         ";
        Gotoxy(2, 24);
        cout << "                                                         ";
        Gotoxy(2, 25);
        cout << "                                                         ";
        Gotoxy(2, 26);
        cout << "                                                         ";
    }
    static void System_coming_soon_service() {
        System_Message_Clear();

        Gotoxy(2, 22);
        cout << "< System >";
        Gotoxy(5, 24);
        cout << "���� ����� �� �����ϴ�.";
    }
    static void System_There_is_not_building_near_player() {
        System_Message_Clear();

        Gotoxy(2, 22);
        cout << "< System >";
        Gotoxy(5, 24);
        cout << "������ �� �ִ� �ǹ��� ��ó�� �����ϴ�.";
    }
}