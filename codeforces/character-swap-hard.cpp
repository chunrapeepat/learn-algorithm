#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        // check is it can swap
        vector<int> checker = vector<int>('z' + 1);
        for (int i = 0; i < n; ++i) {
            ++checker[s[i]];
            ++checker[t[i]];
        }
        bool can_swap = true;
        for (int j = 0; j < checker.size(); ++j) {
            if (checker[j] % 2 != 0) {
                can_swap = false;
                break;
            }
        }
        if (!can_swap) {
            cout << "No" << endl;
            continue;
        }

        // swap string
        vector<pair<int, int>> result;
        while (s.compare(t) != 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (s[i] == s[j]) {
                        swap(s[j], t[i]);
                        result.push_back(make_pair(i+1, j+1));
                    } else if(s[i] == t[j]) {
                        swap(s[j], t[j]);
                        result.push_back(make_pair(j+1, j+1));
                        swap(s[i], t[j]);
                        result.push_back(make_pair(j+1, i+1));
                    }
                }
            }
        }

        // print the result
        cout << "Yes" << endl;
        cout << result.size() << endl;
        for (int l = 0; l < result.size(); ++l) {
            cout << result[l].first << " " << result[l].second << endl;
        }
    }
    return 0;
}