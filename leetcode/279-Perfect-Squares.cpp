class Solution {
public:
    int numSquares(int n) {
        // generate perfect square number
        vector<int> s(n+1, 0);
        vector<int> sl;
        int cnt = 1;
        while (cnt * cnt <= n) {
            int r = cnt * cnt;
            s[r] = 1;
            sl.push_back(r);
            if (r == n) return 1;
            ++cnt;
        }
        for (int i = 2; i <= n; ++i) {
            if (s[i] == 1) continue;
            int min = i;
            int p = 1;
            while (p*p <= i) {
                int sq = p*p;
                int r = s[sq] + s[i-sq];
                if (r < min) min = r;
                ++p;
            }
            s[i] = min;
        }
        return s[n];
    }
};
