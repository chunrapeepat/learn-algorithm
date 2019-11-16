#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 1 || n <= 0) {
        cout << "No" << endl;
    } else {
        bool can = true;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[(n/2) + i]) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}