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
        int n; cin >> n;
        vi recent = vi(n+1, -1);
        int v_min = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (recent[a] == -1) {
                recent[a] = i;
            } else {
                int dist = abs(i - recent[a]);
                if (dist < v_min) {
                    v_min = dist;
                }
                recent[a] = i;
            }
        }

        if (v_min == INT_MAX) v_min = -2;
        cout << v_min + 1 << endl;
    }
    return 0;
}
