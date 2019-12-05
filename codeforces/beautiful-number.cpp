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
        vi P(n);
        int l, r;
        for (int i = 0; i < n; ++i) {
            cin >> P[i];
            if (P[i] == 1) {
                l = r = i;
            }
        }
        vi res(n+1);
        for (int i = 1; i <= n; ++i) {
            if (r + 1 < n) {
                while (P[r+1] <= i && r+1 < n) {
                    r++;
                }
            }
            if (l - 1 >= 0) {
                while (P[l-1] <= i && l-1 >= 0) {
                    l--;
                }
            }
//            cout << i << " -> " << l << " " << r << endl;
            if (r - l + 1 == i) {
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}
