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

bool is_same_sign(int x, int y) {
    return (x >= 0) ^ (y < 0);
}

int main() {
    FAST_IO;
    int n, x; cin >> n >> x;
    vi A;
    while (n--) {
        int num; cin >> num;
        A.push_back(num);
    }
    int result = 0;
    int l = -1;
    int r = -1;
    int v = x > 0 ? INT_MIN : INT_MAX;
    if (x > 0) {
        // find max
        vi dp(A.size());
        for (int i = 0; i < A.size(); ++i) {
            int dp_prev = (i-1 >= 0) ? dp[i-1] : 0;
            if (dp_prev + A[i] > A[i]) {
                dp[i] = dp_prev + A[i];
                ++r;
            } else {
                dp[i] = A[i];
                l = r = i;
            }
            if (dp[i] > v) {
                v = dp[i];
            }
        }
    } else if (x < 0) {
        // find min
        vi dp(A.size());
        int minV = INT_MAX;
        for (int i = 0; i < A.size(); ++i) {
            int dp_prev = (i-1 >= 0) ? dp[i-1] : 0;
            if (dp_prev + A[i] < A[i]) {
                dp[i] = dp_prev + A[i];
                ++r;
            } else {
                dp[i] = A[i];
                l = r = i;
            }
            if (dp[i] < v) {
                v = dp[i];
            }
        }
    }

    if (is_same_sign(x, v) && x != 0) {
        for (int i = l; i <= r; ++i) {
            A[i] = A[i] * x;
        }
    }

    int maxV = -1;
    vi dp(A.size());
    for (int i = 0; i < A.size(); ++i) {
        int dp_prev = (i-1 >= 0) ? dp[i-1] : 0;
        if (dp_prev + A[i] > A[i]) {
            dp[i] = dp_prev + A[i];
            ++r;
        } else {
            dp[i] = A[i];
            l = r = i;
        }
        if (dp[i] > maxV) {
            maxV = dp[i];
        }
    }

    cout << max(maxV, 0) << endl;
    return 0;
}
