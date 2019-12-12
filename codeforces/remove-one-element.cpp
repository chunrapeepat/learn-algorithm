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
    int n; cin >> n;
    vi A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vi inc(n); inc[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i-1]) {
            inc[i] = inc[i-1] + 1;
        } else {
            inc[i] = 1;
        }
    }
    vi dp(n); dp[0] = 1;
    int v_max = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i-1]) {
            dp[i] = dp[i-1] + 1;
        } else {
            if (i-2 >= 0 && A[i-2] < A[i]) {
                dp[i] = inc[i-2] + 1;
            } else {
                dp[i] = 1;
            }
        }
        if (dp[i] > v_max) v_max = dp[i];
    }
    if (v_max == 1) {
        cout << 0 << endl;
    } else {
        cout << v_max << endl;
    }
//    for (int x = 0; x < n; ++x) {
//        cout << dp[x] << " ";
//    }
//    cout << endl;
    return 0;
}
