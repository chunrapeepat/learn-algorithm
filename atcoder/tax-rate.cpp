#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n; cin >> n;
    double before = ceil(n * 100.00 / 108.00);

    if (floor(before * 1.08) == n) {
        cout << before << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}