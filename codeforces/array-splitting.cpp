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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> v;
    for (int i = n-1; i >= 0; --i) {
        sum += a[i];
        if (i > 0) v.pb(sum);
    }

    ll result = sum;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < k - 1; ++i) {
        result += v[i];
    }

    cout << result << endl;
    return 0;
}
