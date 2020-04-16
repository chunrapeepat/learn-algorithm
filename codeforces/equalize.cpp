#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    int prev = -1;
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (1 - prev == (a[i] - '0')) {
                prev = -1;
            } else {
                ++cost;
                prev = a[i] - '0';
            }
        } else {
            prev = -1;
        }
    }

    cout << cost << endl;
}