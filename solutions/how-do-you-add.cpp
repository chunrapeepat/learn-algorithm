#include <iostream>

using namespace std;

unsigned long memo[101][101] = {{0}};

unsigned long P(int n, int k) {
    if (memo[n][k]) return memo[n][k];
    if (k == 1) return 1;
    if (k == 2) {
        memo[n][k] = n + 1;
        return n + 1;
    }
    int S = 0;
    for (int i = 0; i <= n; ++i) S += P(n - i, k - 1);
    memo[n][k] = S;
    return S % 1000000;
}

int main() {
    while (1) {
        int N, K;
        cin >> N >> K;

        if (N == 0 && K == 0) break;
        if (N == 0 || K == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << P(N, K) << endl;
    }
    return 0;
}