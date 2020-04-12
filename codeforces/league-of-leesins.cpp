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
bool find(vi a, int e) {
    for (int i = 0; i < 3; ++i) {
        if (a[i] == e) return true;
    }
    return false;
}

vi find_common(vi a, vi b) {
    vi ans;
    for (int i = 0; i < 3; ++i) {
        if (find(a, b[i])) {
            ans.push_back(b[i]);
        }
    }
    return ans;
}

void test_case() {
    int n; cin >> n;
    vvi tup(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        int a, b, c; cin >> a >> b >> c;
        vi t = {a, b, c};
        tup[i] = t;
    }
    for (int i = 1; i < (n-2)-1; ++i) {
        vi prev = find_common(tup[i-1], tup[i]);
        vi next = find_common(tup[i], tup[i+1]);

        int p = 0;
        int n = 0;
        int c = 0;
        if (prev[0] == next[0]) {
            c = prev[0];
            p = prev[1];
            n = next[1];
        } else if (prev[1] == next[1]) {
            c = prev[1];
            p = prev[0];
            n = next[0];
        } else if (prev[1] == next[0]) {
            c = prev[1];
            p = prev[0];
            n = next[1];
        } else if (prev[0] == next[1]){
            c = prev[0];
            p = prev[1];
            n = next[0];
        }

        cout << p << " " << c << " " << n << endl;
    }
}

int main() {
    test_case();
    return 0;
}
