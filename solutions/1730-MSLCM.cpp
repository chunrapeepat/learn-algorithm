#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

#define MAXN 20000002

// 2 -> 1 2 = 3
// 3 -> 1 3 = 4
// 4 -> 1 2 4 = 7
// 5 -> 1 5 = 6
// 6 -> 1 2 3 6 = 12
// 7 -> 1 7 = 8
// 8 -> 1 2 4 8 = 15
// 9 -> 1 3 9 = 13
// 10 -> 1 2 5 10 = 18
// 3 + 4 + 7 + 6 + 12 + 8 + 15 + 13 + 18 = 16
// 40 -> 1 2 4 5 10 20 40

// TLE
void Seive(bitset<MAXN>& primes) {
    for (int p=2; p <= MAXN; p++) {
        if (primes[p] == 1) {
            for (int i=p*2; i<=MAXN; i += p)
                primes[i] = 0;
        }
    }
}

int findSum(int input) {
    int maxD = (int) sqrt(input);
    int sum=1;
    for(int i = 2; i <= maxD; i++) {
        if(input % i == 0)
        {
            sum += i;
            int d = input/i;
            if(d!=i)
                sum+=d;
        }
    }
    return sum + input;
}

int main() {
    bitset<MAXN> primeMap; primeMap.set();
    Seive(primeMap);

    vector<int> dp(MAXN, 0);

    int ans = 0;
    for (int n = 2; n <= MAXN; ++n) {
        if (primeMap[n] == 1) ans += n + 1;
        else if (n % 2 == 0) ans += dp[n / 2] + n;
        else ans += findSum(n);
        dp[n] = ans;
    }

    cout << "OK" << endl;

    while (1) {
        int N; cin >> N;

        if (N == 0) break;

        cout << "OK" << endl;
    }
    return 0;
}