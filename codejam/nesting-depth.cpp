#include <iostream>

using namespace std;

void solve(int t) {
    string str; cin >> str;
    printf("Case #%d: ", t);

    int parentheses = 0;

    for (int i = 0; i < str.length(); ++i) {
        int num = str[i] - '0';
        int diff = num - parentheses;
        parentheses = num;

        if (diff > 0) {
            for (int j = 0; j < diff; ++j)
                cout << '(';
        } else if (diff < 0) {
            diff *= -1;
            for (int j = 0; j < diff; ++j)
                cout << ')';
        }

        cout << num;
    }

    for (int j = 0; j < parentheses; ++j)
        cout << ')';
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}