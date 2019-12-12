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

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        int l, r, u, d; l = r = u = d = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L') ++l;
            else if (s[i] == 'R') ++r;
            else if (s[i] == 'U') ++u;
            else ++d;
        }
        int width = min(l, r);
        int height = min(u, d);
        if (width == 0 || height == 0) {
            if (l >= 1 && r >= 1) {
                cout << 2 << endl;
                cout << "LR" << endl;
            } else if (u >= 1 && d >= 1) {
                cout << 2 << endl;
                cout << "UD" << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << width*2 + height*2 << endl;
            for (int i = 0; i < width; ++i) {
                cout << "L";
            }
            for (int i = 0; i < height; ++i) {
                cout << "U";
            }
            for (int i = 0; i < width; ++i) {
                cout << "R";
            }
            for (int i = 0; i < height; ++i) {
                cout << "D";
            }
            cout << endl;
        }
    }
    return 0;
}
