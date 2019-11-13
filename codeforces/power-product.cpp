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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair

int main() {
    FAST_IO;
    int n, k; cin >> n >> k;
    vll numbers;
    ll maxNum = -1;
    for (int i = 0; i < n; ++i) {
        ll num; cin >> num;
        numbers.push_back(num);

        if (num > maxNum)
            maxNum = num;
    }
    map<ll, bool> checker;
    int index = 1;
    while (1) {
        int p = pow(index++, k);
        checker.insert({p, true});

        if (p >= maxNum * maxNum) break;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (checker.find(numbers[i] * numbers[j]) != checker.end()) ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
