#include <iostream>
#include <vector>

#define MAX 20000000

using namespace std;

// 1. run seive algorithm from 2 to 20,000,000
// 2. if we find 2-prime add it to vector
// 3. then answer the question

vector<pair<int, int>> ps;

void seive(int n) {
    vector<bool> prime(n + 1, true);
    int prev = -1;

    for (int p=2; p <= n; p++) {
        if (prime[p] == true) {
            if (p - prev == 2) {
                pair<int, int> twin(prev, p);
                ps.push_back(twin);
            }
            prev = p;
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    seive(MAX);
    int n;
    while (scanf("%d", &n) == 1) {
        printf("(%d, %d)\n", ps[n-1].first, ps[n-1].second);
    }

    return 0;
}