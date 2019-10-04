#include <iostream>

using namespace std;

typedef unsigned long long chun;

chun GCD(u_int p, u_int q) {
    if (p < q) {
        return GCD(q, p);
    }
    if (q == 0) {
        return p;
    }
    return GCD(q, p % q);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        chun p, q;
        char c;
        cin >> p >> c >> q;

        chun d = GCD(p, q);
        printf("%llu / %llu\n", p / d, q / d);
    }

    return 0;
}