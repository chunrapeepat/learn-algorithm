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

int dist(point_i a, point_i b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    // Compute the Euclidean distance between point (2, 2) and (6, 5)!
    point_i a = point_i(2, 2);
    point_i b = point_i(6, 5);

    cout << "The distance is: " << dist(a, b) << endl;
    return 0;
}