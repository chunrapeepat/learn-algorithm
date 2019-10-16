#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int l, n; cin >> l >> n;
        int minL = INT_MAX;
        int maxL = INT_MIN;
        int innerMax = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int p; cin >> p;
            int innerLength = min(p, l - p);
            if (innerLength > innerMax) {
                innerMax = innerLength;
            }
            if (p < minL) minL = p;
            if (p > maxL) maxL = p;
        }

        cout << innerMax << " " << max(l - minL, maxL) << endl;
    }

    return 0;
}