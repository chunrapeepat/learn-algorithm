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

ll max(ll a, ll b) {
    if (a > b) return a;
    return b;
}

int main() {
    FAST_IO;
    ll n, x; cin >> n >> x;
    vector<ll> A;
    while (n--) {
        ll num; cin >> num;
        A.push_back(num);
    }
    ll result, best1, best2, best3;
    result = best1 = best2 = best3 = 0;
    for (int i = 0; i < A.size(); ++i) {
        best3 = max(0, max(A[i], max(best1 + A[i], max(best2 + A[i], best3 + A[i]))));
        best2 = max(0, max(x * A[i], max(best1 + x * A[i], best2 + x * A[i])));
        best1 = max(0, max(A[i], best1 + A[i]));
        result = max(best1, max(best2, best3));
    }
    cout << result << endl;
    return 0;
}
