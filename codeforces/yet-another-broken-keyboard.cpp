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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi alpha(50, 0); // allowed
    while (k--) {
        char ch; cin >> ch;
        alpha[ch-'a'] = 1;
    }
    vector<ll> sep;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (alpha[s[i]-'a'] == 0) {
            sep.pb(cnt);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    if (cnt > 0) sep.pb(cnt);
    ll res = 0;
    for (int i = 0; i < sep.size(); ++i) {
        res += (sep[i] * (sep[i]+1)) / 2;
    }
    cout << res << endl;
    return 0;
}
