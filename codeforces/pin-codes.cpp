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
        vector<string> S(n);
        map<string, bool> chk;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            S[i] = s;
            chk.insert({s, true});
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (S[i].compare(S[j]) != 0) {
                    continue;
                }
                ++res;
                bool ok = false;
                for (int x = 0; x < 4 && !ok; ++x) {
                    for (int y = 0; y <= 9 && !ok; ++y) {
                        string newS = S[j];
                        newS[x] = '0'+y;
                        if (chk.find(newS) == chk.end()) {
                            ok = true;
                            S[j] = newS;
                            chk.insert({newS, true});
                            break;
                        }
                    }
                }
            }
        }
        cout << res << endl;
        for (int i = 0; i < n; ++i) {
            cout << S[i] << endl;
        }
    }
    return 0;
}
