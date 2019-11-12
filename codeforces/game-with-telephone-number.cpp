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

    int turn1 = (n - 11) / 2;
    int turn2 = turn1;

    string res = "";
    for (int i = 0; i < n; ++i) {
        if (number[i] == '8') {
            if (turn1 > 0) --turn1;
            else res += number[i];
        } else {
            if (turn2 > 0) --turn2;
            else res += number[i];
        }
    }

    if (res[0] == '8') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
