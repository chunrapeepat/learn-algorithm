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
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 1; i < n; ++i) {
        if (s[i-1] > s[i]) {
            cout << "Yes" << endl;
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
