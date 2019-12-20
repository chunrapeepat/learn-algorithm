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

//int main() {
//    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
//    int res = -1;
//    for (int i = 0; i <= 1000; ++i) {
//        if (i > min(a, d)) break;
//        cout << "Debug: " <<  i << " " << min(b, min(c, d-i)) << endl;
//        res = max(res, i*e + min(b, min(c, d-i)) * f);
//    }
//    cout << res << endl;
//    return 0;
//}

int main() {
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (e > f) {
        int v_min = min(a, d);
        cout << v_min * e + min(b, min(c, d - v_min)) * f << endl;
    } else {
        int v_min = min(b, min(c, d));
        cout << v_min * f + min(a, d - v_min) * e << endl;
    }
    return 0;
}
