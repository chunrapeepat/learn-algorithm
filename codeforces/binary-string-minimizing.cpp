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
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int i = 0;
        int cnt = 0;
        while (i < n && cnt < k) {
            if (s[i] == '1' && s[i+1] == '0') {
                swap(s[i], s[i+1]);
                i = 0;
                ++cnt;
            } else {
                ++i;
            }
        }
        cout << s << endl;
    }
    return 0;
}
