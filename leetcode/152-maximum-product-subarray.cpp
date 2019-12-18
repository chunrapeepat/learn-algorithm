class Solution {
public:
    int maxProduct(vector<int>& A) {
        const int n = A.size();
        vector<int> dp_max(n, 0); dp_max[0] = A[0];
        vector<int> dp_min(n, 0); dp_min[0] = A[0];
        int res = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] >= 0) {
                dp_max[i] = max(dp_max[i-1] * A[i], A[i]);
                dp_min[i] = min(dp_min[i-1] * A[i], A[i]);
            } else {
                dp_max[i] = max(dp_min[i-1] * A[i], A[i]);
                dp_min[i] = min(dp_max[i-1] * A[i], A[i]);
            }
            res = max(res, dp_max[i]);
        }
        return res;
    }
};