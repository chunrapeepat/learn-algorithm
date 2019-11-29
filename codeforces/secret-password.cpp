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

bool compare(string &s1,string &s2) {
    return s1.size() > s2.size();
}

int main() {
    int t; cin >> t;
    map<char, bool> chk;
    vector<string> S(t);
    for (int i = 0; i < t; ++i) {
        string s; cin >> s;
        S[i] = s;
    }
    sort(S.begin(), S.end(), compare);
    int res = 0;
    for (int i = 0; i < t; ++i) {
        bool ok = true;
        for (int j = 0; j < S[i].size(); ++j) {
            if (chk.find(S[i][j]) == chk.end()) {
                ok = false;
                chk.insert({S[i][j], true});
            }
        }
        if (!ok) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
