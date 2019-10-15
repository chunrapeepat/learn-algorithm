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

#define DEBUG(x) cout << "debug> " << x << endl;
#define PRINT(x) cout << x << endl;
#define PRINTCASE(i, x) cout << "Case " << i << ": " << x << endl;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define LOOP_TESTCASE(x) for (int t = 1; t <= x; t++)
#define pb push_back
#define mp make_pair

int main () {
    FAST_IO
    int T; cin >> T;

    LOOP_TESTCASE(T) {
        string S; cin >> S;

        vi counter(26, 0);

        FOR(i, 0, S.length()) {
            counter[S[i] - 'a'] += 1;
        }

        int mn = INT_MAX;
        FOR(i, 0, counter.size()) {
            mn = min(mn, counter[i]);
        }

        PRINTCASE(t, mn)
    }
}