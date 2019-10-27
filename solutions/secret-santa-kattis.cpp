#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long int ll;

int main() {
    int n; cin >> n;

    ll fac = 2;
    double sum = 0;
    for (int i = 2; i <= min(n, 13); ++i) {
        sum += ((i%2 == 0) ? 1.0 : -1.0) * 1.0/fac;
        fac = fac * (i + 1);
    }

    cout << fixed << setprecision(8) << 1 - sum << endl;
    return 0;
}