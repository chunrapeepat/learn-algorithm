// Can't Solve :(
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
    vi pick(4);
    vi res;
    int a, b, c, d;
    for (int i = 0; i < 4; ++i) {
        cin >> pick[i];
    }
    a = pick[0];
    b = pick[1];
    c = pick[2];
    d = pick[3];
    res.pb(0); pick[0]--;
    for (int i = 0; i < 3; ++i) {
        while (pick[i] > 0 && pick[i+1] > 0) {
            if (pick[i] >= pick[i+1]) {
                res.pb(i);
                res.pb(i+1);
                pick[i]--;
                pick[i+1]--;
            } else {
                res.pb(i+1);
                res.pb(i);
                pick[i+1]--;
                pick[i]--;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (pick[i] > 0) {
            res.pb(i);
        }
    }
    bool ok = true;
    for (int i = 0; i < res.size()-1; ++i) {
        if (abs(res[i] - res[i+1]) != 1) ok = false;
    }
    if (res.size() != (a+b+c+d) || !ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
