#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int R, P, S; cin >> R >> P >> S;
        string bob; cin >> bob;

        int win = 0;
        vector<char> result = vector<char>(n);

        for (int i = 0; i < n; ++i) {
            if (bob[i] == 'R' && P >= 1) {
                --P; ++win;
                result[i] = 'P';
            } else if (bob[i] == 'P' && S >= 1) {
                --S; ++win;
                result[i] = 'S';
            } else if (bob[i] == 'S' && R >= 1) {
                --R; ++win;
                result[i] = 'R';
            }
        }

        if (win >= (n / 2) + (n % 2)) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                if (result[i] != 0) {
                    cout << result[i];
                } else {
                    if (R > 0) {
                        cout << 'R';
                        --R;
                    } else if (P > 0) {
                        cout << 'P';
                        --P;
                    } else {
                        cout << 'S';
                        --S;
                    }
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}