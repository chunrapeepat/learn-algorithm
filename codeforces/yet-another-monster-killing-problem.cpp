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

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second > right.second;
    }
};

ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}

int main() {
    FAST_IO;
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        vector<ll> monsters(m);
        for (int i = 0; i < m; ++i) {
            ll mon; cin >> mon;
            monsters[i] = mon;
        }
        int h; cin >> h;
        vector<pair<ll, ll>> heros(h);
        for (int i = 0; i < h; ++i) {
            ll p, s; cin >> p >> s;
            heros.push_back(mp(p, s));
        }
        sort(heros.begin(), heros.end(), sort_pred());
        vector<vector<ll>> dp(h, vector<ll>(m));
        for (int i = 0; i < h; ++i) {
            int counter = 1;
            for (int j = 0; j < m; ++j) {
                ll prev_dp = (i-1 >= 0) ? dp[i-1][j] : INT_MAX;
                if (monsters[j] > heros[i].first) {
                    counter = 1;
                    dp[i][j] = INT_MAX;
                    continue;
                }
//                cout << i << " " << heros[i].second << " " << counter << endl;
                if (heros[i].second <= counter) {
                    ++counter;
                }
                dp[i][j] = min(prev_dp, counter);
                if (dp[i][j] == prev_dp && dp[i][j] != counter) {
                    counter = 1;
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
