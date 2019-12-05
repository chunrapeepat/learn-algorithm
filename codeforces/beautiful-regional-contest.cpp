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
        int N = n;
        vi set;
        int prev = -1;
        int cnt = 0;
        while (n--) {
            int p; cin >> p;
            if (prev == -1) {
                prev = p;
            }
            if (p == prev) {
                cnt++;
            } else {
                set.pb(cnt);
                prev = p;
                cnt = 1;
            }
        }
        set.pb(cnt);
        vi res;
        int sum = 0;
        for (int i = 0; i < set.size(); ++i) {
            sum += set[i];
            if (sum <= N / 2) {
                res.pb(set[i]);
            }
        }
        if (res.size() < 3) {
            cout << "0 0 0" << endl;
        } else {
            int g, s, b; g = s = b = 0;
            g = res[0];
            int s_sum = 0;
            int b_sum = 0;
            for (int i = 1; i < res.size(); ++i) {
                if (s == 0) {
                    s_sum += res[i];
                    if (s_sum > g) {
                        s = s_sum;
                    }
                } else {
                    b_sum += res[i];
                }
            }
            b = b_sum;
            if (g < s && g < b) {
                cout << g << " " << s << " " << b << endl;
            } else {
                cout << "0 0 0" << endl;
            }
        }
    }
    return 0;
}
