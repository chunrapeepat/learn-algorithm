#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int last = k + (3*n - 1);
    vector<vector<int>> result;

    int curr = last - n + 1;
    int l = k;
    int r = last - n;
    int skip = 0;

    vector<int> v_skip;

    while (curr <= last && l < r) {
        if (l + r > curr) {
            ++skip;
            v_skip.push_back(r);
            r--;
            continue;
        }
        if (l + r < curr) {
            ++skip;
            v_skip.insert(v_skip.begin(), l);
            l++;
            continue;
        }

        vector<int> temp = vector<int>(3);
        temp[0] = l;
        temp[1] = r;
        temp[2] = curr;
        result.push_back(temp);

        l++;
        r--;
        curr++;
    }

    if (l == r && skip > 0) {
        v_skip.insert(v_skip.begin(), l);
    }
    if (skip > 0) {
        sort(v_skip.begin(), v_skip.end());
        l = 0;
        r = v_skip.size() - 1;
        while (curr <= last && l < r) {
            if (v_skip[l] + v_skip[r] > curr) {
                cout << -1 << endl;
                return 0;
            }

            vector<int> temp = vector<int>(3);
            temp[0] = v_skip[l];
            temp[1] = v_skip[r];
            temp[2] = curr;
            result.push_back(temp);

            curr++;
            l++;
            r--;
        }
    }

    if (result.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}