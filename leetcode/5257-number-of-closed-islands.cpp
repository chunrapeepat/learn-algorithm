class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& closed) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            ++closed;
            return;
        }
        if (grid[i][j] == 1) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        // cout << i << " " << j <<endl;
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited, closed);
        dfs(grid, i - 1, j, visited, closed);
        dfs(grid, i, j + 1, visited, closed);
        dfs(grid, i, j - 1, visited, closed);
    }

    int closedIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 && visited[i][j] == false) {
                    int closed = 0;
                    dfs(grid, i, j, visited, closed);

                    if (closed == 0) {
                        ++result;
                    }
                }
            }
        }

        return result;
    }
};