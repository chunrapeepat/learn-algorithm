#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair

int main() {
    FAST_IO;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> antennas(n);
    for (int i = 0; i < n; ++i) {
        int x, s; cin >> x >> s;
        int left = max(0, x - s);
        int right = min(m, x + s);
        antennas[i] = mp(left, right);
    }
    vi dp(m+1);
    for (int pos = m-1; pos >= 0; --pos) {
        dp[pos] = m - pos;
        for (int j = 0; j < n; ++j) {
            int left = antennas[j].first;
            int right = antennas[j].second;

            if (left <= pos + 1 && right >= pos + 1) {
                dp[pos] = dp[pos + 1];
                break;
            }

            if (pos < left) {
                int cost = left - pos - 1;
                int nextPos = min(m, right + cost);
                dp[pos] = min(dp[pos], cost + dp[nextPos]);
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}
