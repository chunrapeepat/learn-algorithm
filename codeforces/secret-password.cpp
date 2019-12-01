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

const int N = (int) 2e5 + 100;
vector<int> graph[N];
bool used[N];

void addEdge(int u, int v) {
    graph[u].pb(v);
    graph[v].pb(u);
}

void dfs(int i) {
    used[i] = true;

    for (int to : graph[i]) {
        if (!used[to]) dfs(to);
    }
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (char c : s) {
            addEdge(i, n + c - 'a');
        }
    }

    int CC = 0;
    for (int i = n; i < n+26; ++i) {
        if (!graph[i].empty() && !used[i]) {
            dfs(i);
            ++CC;
        }
    }
    cout << CC << endl;
    return 0;
}
