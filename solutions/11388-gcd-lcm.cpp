#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int g, l; cin >> g >> l;

        if (l % g == 0) {
            cout << g << " " << l << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}