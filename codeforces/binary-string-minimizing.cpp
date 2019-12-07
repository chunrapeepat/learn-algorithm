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
    int q; cin >> q;
    while (q--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        string res = "";
        int cnt = 0;
        bool ok = false;
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else {
                if (k >= cnt) {
                    k -= cnt;
                    res += '0';
                } else {
                    res += string(cnt - k, '1');
                    res += '0';
                    res += string(k, '1');
                    res += s.substr(i + 1);
                    cout << res << endl;
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            res += string(cnt, '1');
            cout << res << endl;
        }
    }
    return 0;
}
