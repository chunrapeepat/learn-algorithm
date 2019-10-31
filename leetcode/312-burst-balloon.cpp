class Solution {
public:
    int maxCoins(vector<int>& A) {
        if (A.empty()) return 0;

        const int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int L = n - 1; L >= 0; --L) {
            for (int R = L; R < n; ++R) {
                for (int i = L; i <= R; ++i) {
                    dp[L][R] = max(dp[L][R],
                            A[i]*(L-1 >= 0 ? A[L-1] : 1)*(R+1 < n ? A[R+1] : 1)
                            + (i-1 >= 0 ? dp[L][i-1] : 0)
                            + (i+1 < n ? dp[i+1][R] : 0));
                }
            }
        }

        return dp[0][n - 1];
    }
};