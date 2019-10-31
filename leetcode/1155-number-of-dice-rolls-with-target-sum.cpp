class Solution {
public:
    const int mod = 1e9 + 7;
    void add(int& a, int b) {
        a += b;
        if (a >= mod) {
            a -= mod;
        }
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<int> ways(target + 1);
        ways[0] = 1;

        for (int rolls = 1; rolls <= d; ++rolls) {
            vector<int> new_ways(target + 1);

            // calculate prefix sum
            for (int i = 1; i < target+1; ++i) {
                add(ways[i], ways[i-1]);
            }
            for (int t = 1; t <= target; ++t) {
                add(new_ways[t], ways[t-1] - (t-f-1 >= 0 ? ways[t-f-1] : 0));
                if (new_ways[t] < 0) {
                    new_ways[t] += mod;
                }
            }
            ways = new_ways;
        }

        return ways[target];
    }
};