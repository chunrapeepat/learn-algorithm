#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main () {
    ll l, h;
    while (cin >> l >> h && (l + h)) {
        ld sum = 0;
        for (int i = l; i <= h; ++i)
            sum += pow(i, -2.0/3) / 3;
        cout << fixed << setprecision(5) << sum << "E-";
        cout << setw(3) << setfill('0') << 15 << endl;
    }
}
