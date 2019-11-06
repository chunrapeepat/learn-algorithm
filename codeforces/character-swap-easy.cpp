#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main() {
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        string s; cin >> s;
        string t; cin >> t;

        map<pair<char, char>, bool> checker;
        int cnt = 0;
        int other = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            if (checker.find(make_pair(s[i], t[i])) != checker.end()) {
                ++cnt;
                ++other;
                continue;
            }
            ++other;
            checker.insert({make_pair(s[i], t[i]), true});
        }
        if ((cnt == 1 && other == 2) || (cnt == 0 && other == 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}