#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

static const int MAX = 1024;
static vector<int> G[MAX];

// 1. create vector of vector to get child
// 2. receive input into structure
// 3. traverse and count is child is eq to K

int dfs(int parent, int curr, int K) {
    if (G[curr].size() < K) {
        return 1;
    }
    int result = 1, t = 0;
    vector<int> A(G[curr].size());
    for (auto v: G[curr]) {
        if (v == parent)
            continue;
        A[t++] = dfs(curr, v, K);
    }
    if (t < K) return 1;
    sort(A.begin(), A.begin() + t);
    for (int i = t - 1; K > 0; i--, K--)
        result += A[i];
    return result;
}

int main() {
    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;

        for (int i = 1; i <= N; i++)
            G[i].clear();

        for (int i = 1; i < N; ++i) {
            int U, V;
            cin >> U >> V;

            G[U].push_back(V);
            G[V].push_back(U);
        }

        printf("Case %d: %d\n", t, dfs(-1, 1, K));
    }

    return 0;
}