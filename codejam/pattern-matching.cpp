// template-cpp-algor
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

// type
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
// shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define R first
#define C second
#define X first
#define Y second
#define INIT_RANDOM_SEED srand(time(0));
// print
template<typename T, typename... Types>
void print_with_space(T t, Types... ts) {
    cout << t << " ";
}
template<typename T, typename... Args>
void DEBUG(T t, Args... args) {
    cout << "DEBUG: " << t << " "; print_with_space(args...); cout << endl;
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

/* CODE START BELOW THIS POINT!!! */
string merge_pattern(string a, string b) {
    if (a.length() > b.length()) {
        return merge_pattern(b, a);
    }
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 1));
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i-1] == '*') {
                dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i][j-1]));
                continue;
            }
            if (b[j-1] == '*') {
                dp[i][j] = max(dp[i][j-1], max(dp[i-1][j-1], dp[i-1][j]));
                continue;
            }
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    // DEBUG DP TABLE
//    cout << "DP TABLE" << endl;
//    cout << endl << "  " << b << endl;
//    for (int i = 1; i <= a.length(); ++i) {
//        cout << a[i-1] << " ";
//        for (int j = 1; j <= b.length(); ++j) {
//            cout << dp[i][j];
//        }
//        cout << endl;
//    }
    if (dp[a.length()][b.length()] == 0) {
        return "*";
    }
    string ans = "";
    int i = a.length();
    int j = b.length();
    while (i > 0 && j > 0) {
        if (a[i-1] == '*') {
            ans = b[j-1] + ans;
            j--;
        }
        if (a[i-1] == b[j-1] || b[j-1] == '*') {
            ans = b[j-1] + ans;
            i--;
            j--;
        }
    }
    return ans;
}

void test_case(int t) {
    int n; cin >> n;
    vector<string> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i];
    }
    string p = ps[0];
    bool isFail = false;
    for (int i = 1; i < n; ++i) {
        p = merge_pattern(p, ps[i]);
        if (p.size() == 1 && p[0] == '*') {
            isFail = true;
            break;
        }
    }
    printf("Case #%d: ", t);
    if (isFail) {
        printf("*\n");
        return;
    }
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] != '*')
            printf("%c", p[i]);
    }
    printf("\n");
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        test_case(t);
    }
    return 0;
}
