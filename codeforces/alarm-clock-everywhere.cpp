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

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> events;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        events.push_back(x);
    }
    ll interval = -1;
    for (int i = 1; i < n; ++i) {
        ll diff = events[i] - events[i-1];
        if (interval == -1) interval = diff;
        interval = gcd(interval, diff);
    }
    for (int j = 0; j < m; ++j) {
        ll s; cin >> s;
        if (interval % s == 0 || interval == -1) {
            cout << "Yes" << endl;
            cout << events[0] << " " << j + 1 << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
