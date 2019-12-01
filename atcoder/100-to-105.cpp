#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X; cin >> X;
    int times = X / 100;
    int nums = X % 100;
    while (nums > 0 && times > 0) {
        nums -= 5;
        --times;
    }
    cout << ((int) nums <= 0) << endl;
    return 0;
}