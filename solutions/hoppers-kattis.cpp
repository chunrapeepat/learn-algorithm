#include <studio.h>
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
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair

int main() {
    int N, M; cin >> N >> M;
    vector<int> cnt(N, 0);
    while(M--) {
        int u, v; cin >> u >> v;
        cnt[u-1] += 1;
        cnt[v-1] += 1;
    }
    int max = 0;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] > max) max = cnt[i];
    }
    cout << N - max << endl;
    return 0;
}
