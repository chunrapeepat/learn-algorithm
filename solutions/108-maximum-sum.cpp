#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int c; cin >> c;
            dp[i][j] = c;
            if (i-1 >= 0) dp[i][j] += dp[i-1][j];
            if (j-1 >= 0) dp[i][j] += dp[i][j-1];
            if (i-1 >= 0 && j-1 >= 0) dp[i][j] -= dp[i-1][j-1];
        }
    }
    int maxRect = INT_MIN;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int x = i; x < N; ++x) {
                for (int y = j; y < N; ++y) {
                    int area = dp[x][y];
                    if (i > 0) area -= dp[i-1][y];
                    if (j > 0) area -= dp[x][j-1];
                    if (i > 0 && j > 0) area += dp[i-1][j-1];
                    maxRect = max(maxRect, area);
                }
            }
        }
    }
    cout << maxRect << endl;
}