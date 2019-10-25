#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> dp(3, vector<int>(m, 0));
    vector<pair<int, int>> bad_loc;

    while (n--) {
        int x, y; cin >> x >> y;
        bad_loc.push_back({x, y});
    }

    dp[0][0] = 1;
    dp[0][1] = 2;
    dp[1][0] = 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            // a = dp[i][j-1], b = dp[i-1][j], c = dp[i-2][j], d = dp[i][j-2]
            int a = (j-1 >= 0) ? dp[i][j-1] : 1;
            int b = (i-1 >= 0) ? dp[i-1][j] : 1;
            int c = (i-2 >= 0) ? dp[i-2][j] : (i-2 == -1) ? 1 : 0;
            int d = (j-2 >= 0) ? dp[i][j-2] : (j-2 == -1) ? 1 : 0;

            int is1 = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0;
            int is2 = (i-2 >= 0 && j-1 >= 0) ? dp[i-2][j-1] : 0;
            int is3 = (i-1 >= 0 && j-2 >= 0) ? dp[i-1][j-2] : 0;

            dp[i][j] = b*(a-is1) + (c-is2)*a + (d-is3)*b;
        }
    }

    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < m; ++y) {
            cout << dp[x][y] << " ";
        }
        cout << endl;
    }

//    cout << dp[2][m-1] << endl;
    return 0;
}