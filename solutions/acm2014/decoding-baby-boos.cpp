#include <iostream>
#include <vector>

using namespace std;

int m(char c) {
    return c - 'A' + 1;
}

char r(int i) {
    char c = (char) (i + 'A' - 1);
    return c;
}

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        string message; cin >> message;

        vector<int> map(27, 0);

        int R; cin >> R;
        for (int i = 0; i < R; ++i) {
            char replace; cin >> replace;
            char old; cin >> old;

            if (map[m(old)] == 0) {
                map[m(old)] = m(replace);
            }

            for (int k = 1; k < 27; ++k) {
                if (map[k] == m(old)) {
                    map[k] = m(replace);
                }
            }
        }

        for (int i = 0; i < message.length(); ++i) {
            char c = message[i];
            if (c == '_' || map[m(c)] == 0) {
                cout << message[i];
                continue;
            }
            cout << r(map[m(c)]);
        }

        cout << endl;
    }

    return 0;
}