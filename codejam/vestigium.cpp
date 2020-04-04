#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(n));
    vector<map<int, int>> row = vector<map<int, int>>(n);

    int k = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        bool isRowHasRepeatedElement = false;

        for (int j = 0; j < n; ++j) {
            int e; cin >> e;
            mat[i][j] = e;

            if (row[i].find(e) != row[i].end() && !isRowHasRepeatedElement) {
                ++r;
                isRowHasRepeatedElement = true;
            } else {
                row[i].insert(make_pair(e, e));
            }

            if (i == j) k += e;
        }
    }

    int c = 0;
    vector<map<int, int>> col = vector<map<int, int>>(n);
    for (int j = 0; j < n; ++j) {
        bool isColHasRepeatedElement = false;
        for (int i = 0; i < n; ++i) {
            if (col[j].find(mat[i][j]) != col[j].end() && !isColHasRepeatedElement) {
                ++c;
                isColHasRepeatedElement = true;
            } else {
                col[j].insert(make_pair(mat[i][j], mat[i][j]));
            }
        }
    }

    printf("Case #%d: %d %d %d\n", t, k, r, c);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}