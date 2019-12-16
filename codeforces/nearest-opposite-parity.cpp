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

int n;
vi ans, a;
vvi g;

void bfs(const vi& start, const vi& end) {
    vi d(n, INT_MAX);
    queue<int> q;
    for (auto v : start) {
        d[v] = 0;
        q.push(v);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto to : g[v]) {
            if (d[to] == INT_MAX) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    for (auto v : end) {
        if (d[v] != INT_MAX) {
            ans[v] = d[v];
        }
    }
}

int main() {
    cin >> n;
    a = vi(n);
    g = vvi(n);
    vi even, odd;
    // store index in array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) odd.pb(i);
        else even.pb(i);
    }
    // add edges
    for (int i = 0; i < n; ++i) {
        int l = i - a[i];
        int r = i + a[i];
        if (0 <= l) g[l].pb(i);
        if (r < n) g[r].pb(i);
    }
    // run multi-source bfs
    ans = vi(n, -1);
    bfs(odd, even);
    bfs(even, odd);
    // print the result
    for (auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}
