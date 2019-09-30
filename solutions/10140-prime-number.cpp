#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map<int, bool> memo;

bool is_prime(int n) {
    if (n <= 2) return true;

    if (memo.find(n) != memo.end()) {
        return memo.find(n)->second;
    }

    int count = 0;
    int upper = ceil(sqrt(n));
    for (int i = 2; i <= upper; ++i) {
        if (n % i == 0) {
            ++count;
        }
    }

    bool result = count == 0;
    memo.insert({n, result});

    return result;
}

int main() {
    int L, U;

    while (scanf("%d %d", &L, &U) == 2) {
        vector<int> prime;

        for (int i = L; i < U; ++i) {
            if (is_prime(i)) {
                prime.push_back(i);
            }
        }

        if (prime.size() < 2) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }

        int min_i = -1;
        int min = 99999999;
        int max_i = -1;
        int max = -1;
        for (int i = 1; i < prime.size(); ++i) {
            int dist = prime[i] - prime[i - 1];
            if (dist > max) {
                max = dist;
                max_i = i;
            }
            if (dist < min) {
                min = dist;
                min_i = i;
            }
        }

        cout << prime[min_i - 1] << "," << prime[min_i] << " are closest, " << prime[max_i - 1] << "," << prime[max_i] << " are most distant." << endl;
    }
    return 0;
}