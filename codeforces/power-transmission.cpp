#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

const int N = 1001;
int x[N], y[N];
map<pair<int, int>, set<ll>> slope_map;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    ll total = 0, res = 0;
    for (int i = 1; i <= n - 1; ++i) for (int j = i + 1; j <= n; ++j) {
        // construct formula
        int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
        int a = y1 - y2, b = x1 - x2;
        // normalize
        int d = gcd(a, b); a /= d, b /= d;
        if (a < 0 || (a == 0 && b < 0)) {
            a = -a;
            b = -b;
        }
        // store in map
        pair<int, int> slope(a, b);
        ll c = 1LL * a * x1 - 1LL * b * y1;
        if (!slope_map[slope].count(c)) {
            ++total;
            slope_map[slope].insert(c);
            res += total - slope_map[slope].size();
        }
    }
    cout << res << endl;
    return 0;
}