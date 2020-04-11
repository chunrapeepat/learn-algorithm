class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size();
        vector<int> less(n);
        vector<int> greater(n);

        for (int i = 0; i < n; ++i) {
            int l_count = 0;
            for (int l = 0; l < i; ++l) {
                if (rating[l] < rating[i]) ++l_count;
            }
            less[i] = l_count;
            int g_count = 0;
            for (int g = i+1; g < n; ++g) {
                if (rating[g] > rating[i]) ++g_count;
            }
            greater[i] = g_count;
        }

        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += less[i] * greater[i];
            ans += (i - less[i]) * (n - (i+1) - greater[i]);
        }
        return ans;
    }
};