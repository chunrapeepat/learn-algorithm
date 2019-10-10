#include <iostream>
#include <vector>
#include <bitset>
#include <map>

#define MAXN 1000010

using namespace std;

void SieveOfEratosthenes(int n, bitset<MAXN>& ps) {
    for (int p=2; p <= n; p++) {
        if (ps[p] == 0) {
            for (int i=p*2; i<=n; i += p)
                ps[i] = 1;
        }
    }
}

int GCD(int a, int b) {
    if (a < b) return GCD(b, a);
    if (b == 0) return a;
    return GCD(b, a % b);
}

void BFS(vector<int>& G, vector<bool>& visited, int i, bitset<MAXN> ps) {
    if (visited[i]) return;
    visited[i] = true;

    for (int j = 0; j < G.size(); ++j) {
        if (ps[G[i]] == 0 && ps[G[j]] == 0) {
            continue;
        }
        if (i != j && !visited[j] && GCD(G[i], G[j]) > 1) {
            BFS(G, visited, j, ps);
        }
    }
}

int main() {
    bitset<MAXN> ps;
    SieveOfEratosthenes(MAXN, ps);

    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;

        vector<int> G;
        vector<bool> visited(N, false);

        for (int i = 0; i < N; ++i) {
            int num; cin >> num;
            G.push_back(num);
        }

        int CC = 0;
        for (int j = 0; j < N; ++j) {
            if (!visited[j]) {
                ++CC;
                BFS(G, visited, j, ps);
            }
        }

        printf("Case %d: %d\n", t, CC);
    }

    return 0;
}