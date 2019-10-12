#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int T; cin >> T;
    int tc = 0;

    while (T--) {
        int E, P, K, R; cin >> E >> P >> K >> R;

        if (E > P * K && R >= P * K) {
            printf("Case %d: %d\n", ++tc, -1);
            continue;
        }

        float max = P * K;
        float rate = max - R;
        if (rate <= 0) {
            printf("Case %d: %d\n", ++tc, K);
            continue;
        }


        float round = ceil((E - max) / rate);

        if (round <= 0) {
            unsigned long long total = E / P;
            unsigned long long frag = (E - P * total);
            printf("Case %d: %llu\n", ++tc, total + frag);
            continue;
        }

        unsigned long long total = K * round;
        unsigned long long total2 = ceil((E - round * rate) / P);
        printf("Case %d: %llu\n", ++tc, total + total2);
    }

    return 0;
}