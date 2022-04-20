class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> m(s.length(), vector<bool>(s.length(), false));
        int ri = -1;
        int rj = -1;
        for (int l = 1; l <= s.length(); ++l) {
            for (int j = l-1; j < s.length(); ++j) {
                int i = j - (l-1);
                if (i == j) {
                    m[i][j] = true;
                    ri = i;
                    rj = j;
                    continue;
                }
                bool mid = (i+1 <= j-1) ? m[i+1][j-1] : true;
                m[i][j] = (s[i] == s[j]) && mid;
                if (m[i][j]) {
                    ri = i;
                    rj = j;
                }
            }
        }
        return s.substr(ri, rj - ri + 1);
    }
};
