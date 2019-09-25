#include <iostream>
#include <cmath>

using namespace std;

struct point_i {
    int x, y;
    point_i() {
        x = y = 0;
    }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

point_i rotate(point_i p, int the) {
    double rad = (M_PI / 180) * the;
    return point_i(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

int main() {
    // Rotate a point (10, 3) by 90 degrees counter clockwise around origin.
    // What is the new coordinate of the rotated point? (easy to compute by hand).
    point_i a = point_i(10, 3);
    point_i p = rotate(a, 90);

    cout << "The new point is: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}