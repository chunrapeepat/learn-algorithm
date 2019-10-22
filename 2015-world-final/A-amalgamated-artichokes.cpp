#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ll p, a, b, c, d; cin >> p >> a >> b >> c >> d;
    int n; cin >> n;

    double max = 0;
    double maxDiff = 0;

    for (int i = 1; i <= n; ++i) {
        double price = p * (sin(a*i + b) + cos(c*i + d) + 2);
        if (i == 1) {
            max = price;
            maxDiff = 0;
            continue;
        }
        if (max - price > maxDiff) maxDiff = max - price;
        if (price > max) max = price;
    }

    printf("%.8lf\n", maxDiff);

    return 0;
}