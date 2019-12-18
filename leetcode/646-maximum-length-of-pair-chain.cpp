class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return (a[0] - b[0]) < 0;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), (cmp));
        const int n = pairs.size();
        int res = -1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(dp[j], (pairs[i][1] < pairs[j][0]) ? dp[i] + 1 : dp[i]);
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};