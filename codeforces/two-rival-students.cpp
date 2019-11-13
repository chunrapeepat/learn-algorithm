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
        int n, x, a, b; cin >> n >> x >> a >> b;
        if (a < b) swap(a, b);

        while (!(x == 0 || (a == n && b == 1))) {
            if (a < n) {
                ++a;
            } else {
                --b;
            }
            --x;
        }

        cout << abs(a - b) << endl;
    }
    return 0;
}
