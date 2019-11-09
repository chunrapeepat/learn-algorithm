#include <iostream>
#include <map>

using namespace std;

void insert(map<int, int>& m, int n) {
    if (m.find(n) == m.end()) {
        m.insert({n, 1});
    } else {
        m.insert({n, m.find(n)->second + 1});
    }
}

int main() {
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n * 2; ++i) {
        int num; cin >> num;

        if (m.find(num) == m.end()) {
            m.insert({num, 1});
        } else {
            m.find(num)->second += 1;
        }
    }
    bool can_swap = true;
    for (auto const& x : m) {
        cout << x.second << endl;
        if (x.second % 2 != 0) {
            can_swap = false;
            break;
        }
    }
    if (can_swap) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
