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
        vi res;
        int d = 1;
        while (n / d != 1) {
            res.pb(n / d);
            d = n / (n/d) + 1;
        }
        cout << res.size() + 2<< endl;
        cout << "0 1 ";
        for (int i = res.size() - 1; i >= 0; --i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
