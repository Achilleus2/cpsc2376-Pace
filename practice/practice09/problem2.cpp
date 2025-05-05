#include <iostream>

struct Point {
    float x;
    float y;
};

Point calcMidpoint(const Point* p1, const Point* p2) {
    float midpointx = (p1->x + p2->x) / 2;
    float midpointy = (p1->y + p2->y) / 2;

    return Point{ midpointx, midpointy };  
}

int main() {
    Point a{ 1.0f, 2.0f };
    Point b{ 5.0f, 6.0f };

    Point mid = calcMidpoint(&a, &b);

    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl; // Should be (3, 4)

    return 0;
}
