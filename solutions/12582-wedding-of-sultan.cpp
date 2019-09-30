#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int to_i(char c) {
    int i = (int) c - 'A';
    return i;
}

void insert_node(vector<int>& result, stack<char>& s, char node) {
    result[to_i(node)] = 0;

    if (s.empty()) {
        s.push(node);
        return;
    }

    if (s.top() == node) {
        s.pop();
        return;
    }

    cout << "Shit " << result[to_i(s.top())] << " i = " << to_i(s.top()) << endl;

    result[to_i(s.top())] += 1;
    result[to_i(node)] += 1;
    s.push(node);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string path;
        cin >> path;

        vector<int> result(26, -1);
        stack<char> s;

        for (int i = 0; i < path.length(); ++i) {
            insert_node(result, s, path.at(i));
        }

        cout << "Case " << t << endl;
        for (int i = 0; i < 26; ++i) {
            if (result[i] != -1) {
                char c = (char) i + 'A';
                cout << c << " = " << result[i] << endl;
            }
        }
    }

    return 0;
}