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
bool areAllBitsSet(int n) {
    if (n == 0)
        return false;
    if (((n + 1) & n) == 0)
        return true;
    return false;
}
pair<int, int> m(int x, bool is_minus) {
    if (!is_minus) {
        int power_of_two = 1;
        while (power_of_two < x) {
            power_of_two <<= 1;
        }
        int diff = power_of_two - x;
        return mp(power_of_two, diff);
    } else {
        int power_of_two = 1;
        while (power_of_two <= x) {
            power_of_two <<= 1;
        }
        int diff = power_of_two - x;
        return mp(diff, power_of_two);
    }
}
void buildSolution(int t, pii mx, pii my, bool is_x, bool is_y) {
    int x = mx.first;
    int y = my.first;
    int dx = mx.second;
    int dy = my.second;
    printf("Case #%d: ", t);
    while (x > 0 || y > 0 || dx > 0 || dy > 0) {
        if (x & 1) {
            printf("%c", is_x ? 'W' : 'E');
        } else if (y & 1) {
            printf("%c", is_y ? 'S' : 'N');
        } else if (dx & 1) {
            printf("%c", is_x ? 'E' : 'W');
        } else if (dy & 1) {
            printf("%c", is_y ? 'N' : 'S');
        }

        x >>= 1;
        y >>= 1;
        dx >>= 1;
        dy >>= 1;
    }
    printf("\n");
}
void test_case(int t) {
    int x, y; cin >> x >> y;

    bool is_minus_x = false;
    bool is_minus_y = false;
    if (x < 0) {
        is_minus_x = true;
        x *= -1;
    }
    if (y < 0) {
        is_minus_y = true;
        y *= -1;
    }

    pii px = m(x, is_minus_x);
    pii py = m(y, is_minus_y);
    int mx = px.first | px.second;
    int my = py.first | py.second;

    if(areAllBitsSet(x^y) && (x^y) == (x|y)) {
        buildSolution(t, mp(x,0), mp(y,0), is_minus_x, is_minus_y);
    } else if (areAllBitsSet(x ^ my) && (x^my) == (x|my)) {
        buildSolution(t, mp(x,0), py, is_minus_x, false);
    } else if (areAllBitsSet(mx ^ y) && (mx^y) == (mx|y)) {
        buildSolution(t, px, mp(y,0), false, is_minus_y);
    } else if (areAllBitsSet(mx ^ my) && (mx^my) == (mx|my)) {
        buildSolution(t, px, py, false, false);
    } else {
        printf("Case #%d: IMPOSSIBLE\n", t);
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        test_case(t);
    }
    return 0;
}
