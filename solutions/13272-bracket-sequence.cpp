#include <iostream>
#include <stack>

using namespace std;

pair<int, char> make_pair(int a, char b) {
    pair<int, char> p({a, b});
    return p;
}

int main() {
    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        string B; cin >> B;
        stack<pair<int, char>> S;
        int* count = new int[B.length()];
        for (int l = 0; l < B.length(); ++l) {
            count[l] = 0;
        }

        for (int i = 0; i < B.length(); ++i) {
            if (S.empty()) {
                if (B[i] != '>' && B[i] != '}' && B[i] != ']' && B[i] != ')')
                    S.push(make_pair(i, B[i]));
                else
                    count[i] = -1;
                continue;
            }
            if (B[i] != '>' && B[i] != '}' && B[i] != ']' && B[i] != ')') {
                S.push(make_pair(i, B[i]));
                continue;
            }
            pair<int, char> top = S.top();
            if ((top.second == '<' && B[i] == '>') || (top.second == '[' && B[i] == ']') || (top.second == '{' && B[i] == '}') || (top.second == '(' && B[i] == ')')) {
                count[top.first] += 2;
                S.pop();
            } else {
                S = stack<pair<int, char>>();
//                cout << "Debug: " << B[i] << endl;
                count[i] = -1;
            }
        }

        while (!S.empty()) {
            pair<int, char> top = S.top();
            count[top.first] = -1;

            S.pop();
        }

        int sum = 0;
        for (int j = B.length() - 1; j >= 0; --j) {
            if (count[j] == -1) {
                sum = 0;
                continue;
            }
            if (count[j] != 0) {
                sum += count[j];
                count[j] = sum;
            }
        }

        printf("Case %d:\n", t);
        for (int k = 0; k < B.length(); ++k) {
            if (count[k] == -1) {
                cout << 0 << endl;
            } else {
                cout << count[k] << endl;
            }
        }
    }

    return 0;
}