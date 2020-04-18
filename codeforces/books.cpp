// template-cpp-algor
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

// type
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
// shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define R first
#define C second
#define X first
#define Y second
#define INIT_RANDOM_SEED srand(time(0));
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

/* CODE START BELOW THIS POINT!!! */
void solve(int n, int t, vi& a) {
    vi f(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += a[i];
        f[i] = cnt;
    }
    vi sum(n, 0);
    vi res(n+1, 0);
    int result = -1;
    for (int i = n-1; i >= 0; --i) {
        if (sum[i+1] + a[i] <= t) {
            sum[i] += a[i];
            res[i] = res[i+1] + 1;
        } else {
            int target = f[i] + (t - a[i]);
            int index = i;
            int val = sum[i];
            for (int j = i; j < n - 1; ++j) {
                if (sum[j] <= target) {
                    index = j;
                    val = sum[j];
                } else {
                    break;
                }
            }
            sum[i] = val - sum[i] + a[i];
            res[i] = index - i + 1;
        }
        if (res[i] > result)
            result = res[i];
    }
    cout << result << endl;
}

int main() {
    int n, t; cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    solve(n, t, a);
    return 0;
}
