
#pragma once

class Pointer {
private:
    int x, y;

public:
    Pointer(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const { return this->x; }
    int getY() const { return this->y; }

    void addX(const int add_x) { this->x += add_x; }
    void addY(const int add_y) { this->y += add_y; }
};