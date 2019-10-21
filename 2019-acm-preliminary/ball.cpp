#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> diff(n, 0);

    // get input
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        diff[i] = b;
    }
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        diff[i] -= b;
    }

    // loop check cnt
    vector<int> cnt(n, 0);
    stack<pair<int, int>> cost;
    for (int i = 0; i < n; ++i) {
        cnt[i] = i > 0 ? cnt[i - 1] : 0;
        if (diff[i] == 0) continue;

        while (!cost.empty() && diff[i] != 0) {
            pair<int, int> t = cost.top();
            if ((t.second > 0 && diff[i] > 0) || (t.second < 0 && diff[i] < 0)) {
                break;
            }
            cost.pop();
            cnt[i] += abs(t.first - i) * min(abs(t.second), abs(diff[i]));
            if (abs(t.second) > abs(diff[i])) {
                cost.push(make_pair(t.first, t.second + diff[i]));
                diff[i] = 0;
            } else {
                diff[i] += t.second;
            }
        }

        if (diff[i] != 0) {
            cost.push(make_pair(i, diff[i]));
        }
    }

    // answer
    cout << cnt[n-1] << endl;
    return 0;
}