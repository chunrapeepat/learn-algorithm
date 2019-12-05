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

char pick(char b, char e) {
    vi test(3, 1);
    if (b != '?') test[b-'a'] = 0;
    if (e != '?') test[e-'a'] = 0;
    for (int i = 0; i < 3; ++i) {
        if (test[i] == 1) return i + 'a';
    }
    return 'x';
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        const int n = s.length();
        s = '?' + s + '?';
        string res = "";
        bool impos = false;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != '?') {
                res += s[i];
                if (s[i] == s[i+1]) {
                    impos = true;
                }
                continue;
            }
            char p = pick(s[i-1], s[i+1]);
            s[i] = p;
            res += p;
        }
        if (impos) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
