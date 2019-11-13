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
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        map<ll, bool> checker;
        while (x < y) {
            if (checker.find(x) != checker.end()) break;
            checker.insert({x, true});
            if (x % 2 == 0) {
                x = x * 3 / 2;
            } else {
                x = (x-1) * 3 / 2;
            }
        }
        if (x >= y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
