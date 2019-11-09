// O(n^2) solution (AC)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        if (n == 0) return 0;

        vector<int> lessLeft = vector<int>(n);
        vector<int> lessRight = vector<int>(n);
        lessLeft[0] = -1;
        lessRight[n-1] = n;

        for (int i = 1; i < n; ++i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = lessLeft[p];
            }
            lessLeft[i] = p;
        }

        for (int i = n-2; i >= 0; --i) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = lessRight[p];
            }
            lessRight[i] = p;
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, heights[i] * (lessRight[i] - lessLeft[i] - 1));
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.size() == 0) return 0;
        const int n = mat.size();
        const int m = mat[0].size();

        vector<vector<int>> row = vector<vector<int>>(n, vector<int>(m));

        // calculate row (sum)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '1') {
                    row[i][j] = (i-1 < 0 ? 0 : row[i-1][j]) + 1;
                }
            }
        }

        // find largest rectangle
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int area = largestRectangleArea(row[i]);
            if (area > result) {
                result = area;
            }
        }

        return result;
    }
};

// O(n^4) solution (Got TLE)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.size() == 0) return 0;
        const int n = mat.size();
        const int m = mat[0].size();

        vector<vector<int>> sum = vector<vector<int>>(n, vector<int>(m));
        vector<vector<int>> row = vector<vector<int>>(n, vector<int>(m));
        vector<vector<int>> col = vector<vector<int>>(n, vector<int>(m));

        // calculate prefix sum, row, col
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum[i][j] = (i-1 < 0 ? 0 : sum[i-1][j])
                            + (j-1 < 0 ? 0 : sum[i][j-1])
                            - (i-1 < 0 || j-1 < 0 ? 0 : sum[i-1][j-1])
                            + (mat[i][j] - '0');
                if (mat[i][j] == '1') {
                    row[i][j] = (i-1 < 0 ? 0 : row[i-1][j]) + 1;
                    col[i][j] = (j-1 < 0 ? 0 : col[i][j-1]) + 1;
                }
            }
        }

        // find max rectangle
        int result = 0;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (row[i][j] > 0 && col[i][j] > 0) {
                    int area_check = (abs(i-(i - row[i][j] + 1))+1) * (abs(j-(j - col[i][j] + 1))+1);
                    if (area_check <= result) continue;

                    for (int y = i - row[i][j] + 1; y <= i; ++y) {
                        for (int x = j - col[i][j] + 1; x <= j; ++x) {
                            int size = sum[i][j]
                                       - (y-1 < 0 ? 0 : sum[y-1][j])
                                       - (x-1 < 0 ? 0 : sum[i][x-1])
                                       + (x-1 < 0 || y-1 < 0 ? 0 : sum[y-1][x-1]);
                            int area = (abs(i-y)+1) * (abs(j-x)+1);
                            if (size == area && size > result) {
                                result = size;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};