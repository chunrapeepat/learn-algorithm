#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long bigint;

int main() {
    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        bigint A; cin >> A;
        bigint B; cin >> B;

        bigint power = 1;
        bigint a_or = 0;
        bigint a_and = 0;

        int N = floor(log2(B)) + 1;

        for (int i = 0; i < N; ++i) {
            bigint x = (A >> i & 1) | (min(A + power, B) >> i & 1);
            bigint y = (A >> i & 1) & (min(A + power, B) >> i & 1);

            a_or += x << i;
            a_and += y << i;

            power *= 2;
//            cout << "Debug: " << x << " " << y << " -> " << min(A + power, B) << endl;
        }

        cout << "Case " << t << ": " << a_or << " " << a_and << endl;
    }

    return 0;
}