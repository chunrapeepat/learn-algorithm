// Wrong Test
// 1 2 3 5 3 9 4 5 6
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
    int withoutRemove = INT_MIN;
    vi inc(n); inc[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i-1]) {
            inc[i] = inc[i-1] + 1;
        } else {
            inc[i] = 1;
        }
        if (inc[i] > withoutRemove) {
            withoutRemove = inc[i];
        }
    }
    vi dec(n); dec[n-1] = 1;
    for (int i = n-2; i >= 0; --i) {
        if (A[i] < A[i+1]) {
            dec[i] = dec[i+1] + 1;
        } else {
            dec[i] = 1;
        }
    }
    int v_max = -1;
    for (int i = 0; i < n; ++i) {
        int res;
        int prev = (i-1 >= 0) ? inc[i-1] : 0;
        int next = (i+1 < n) ? dec[i+1] : 0;
        if (A[i-1] < A[i+1]) {
            res = prev + next;
        } else {
            res = max(prev, next);
        }
        if (res > v_max) v_max = res;
    }
    cout << max(withoutRemove, v_max) << endl;
//    cout << max(withoutRemove, v_max) << endl;
//    cout << "Inc: ";
//    for (int x = 0; x < n; ++x) {
//        cout << inc[x] << " ";
//    }
//    cout << endl;
//    cout << "Dec: ";
//    for (int x = 0; x < n; ++x) {
//        cout << dec[x] << " ";
//    }
//    cout << endl;
    return 0;
}

//int main() {
//    int n; cin >> n;
//    vi A(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> A[i];
//    }
//    vi inc(n); inc[0] = 1;
//    for (int i = 1; i < n; ++i) {
//        if (A[i] > A[i-1]) {
//            inc[i] = inc[i-1] + 1;
//        } else {
//            inc[i] = 1;
//        }
//    }
//    vi dp(n); dp[0] = 1;
//    int v_max = 1;
//    for (int i = 1; i < n; ++i) {
//        if (A[i] > A[i-1]) {
//            dp[i] = dp[i-1] + 1;
//        } else {
//            if (i-2 >= 0 && A[i-2] < A[i]) {
//                dp[i] = inc[i-2] + 1;
//            } else {
//                dp[i] = 1;
//            }
//        }
//        if (dp[i] > v_max) v_max = dp[i];
//    }
//    if (v_max == 1) {
//        cout << 0 << endl;
//    } else {
//        cout << v_max << endl;
//    }
////    for (int x = 0; x < n; ++x) {
////        cout << dp[x] << " ";
////    }
////    cout << endl;
//    return 0;
//}
