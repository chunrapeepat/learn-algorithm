class Solution {
public:
    int maxSatisfaction(vector<int>& S) {
        const int n = S.size();
        sort(S.begin(), S.end());
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = S[i];
        int ans = 0;
        for (int d = 1; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                int j = i + d;
                dp[i][j] = dp[i][j-1] + (d+1)*S[j];
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};