#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
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

typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << "debug> " << x << endl;
#define PRINT(x) cout << x << endl;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

ll factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main () {
    FAST_IO

    ll m, n; cin >> m >> n;
    int t; cin >> t;

    if (t == 1) {
        if (n >= 13) {
            PRINT("LTE")
        } else {
            if (m < factorial(n)) {
                PRINT("LTE")
            } else {
                PRINT("AC")
            }
        }
    }

    if (t == 2) {
        if (n >= 30) {
            PRINT("LTE")
        } else {
            if (m < pow(2, n)) {
                PRINT("LTE")
            } else {
                PRINT("AC")
            }
        }
    }

    if (t == 3) {
        if (m < n * n * n * n) {
            PRINT("LTE")
        } else {
            PRINT("AC")
        }
    }

    if (t == 4) {
        if (m < n * n * n) {
            PRINT("LTE")
        } else {
            PRINT("AC")
        }
    }

    if (t == 5) {
        if (m < n * n) {
            PRINT("LTE")
        } else {
            PRINT("AC")
        }
    }

    if (t == 6) {
        if (m < n * log2(n)) {
            PRINT("LTE")
        } else {
            PRINT("AC")
        }
    }

    if (t == 7) {
        if (m < n) {
            PRINT("LTE")
        } else {
            PRINT("AC")
        }
    }

    return 0;
}