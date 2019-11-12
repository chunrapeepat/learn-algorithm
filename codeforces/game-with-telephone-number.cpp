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
    string number; cin >> number;
    int c8 = 0;
    int n8 = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (number[i] == '8') {
            ++c8;
            n8 += cnt;
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    int turn = n - 11;
    n8 = n8 - ((turn / 2) + (turn % 2));
    c8 = c8 - (turn / 2);

    if (c8 > 0 && n8 <= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
