#pragma once

class Point {
public:
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};