class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> cells = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < indices.size(); ++i) {
            int ri = indices[i][0];
            int ci = indices[i][1];
            for (int r = 0; r < m; ++r) {
                ++cells[ri][r];
            }
            for (int c = 0; c < n; ++c) {
                ++cells[c][ci];
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // cout << cells[i][j] << " ";
                if (cells[i][j] % 2 != 0) {
                    ++result;
                }
            }
            // cout << endl;
        }

        return result;
    }
};