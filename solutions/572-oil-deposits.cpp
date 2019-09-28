#include <iostream>
#include <vector>

using namespace std;

int di[] = {1, -1, 1, 1, -1, -1, 0, 0};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};

int M, N;
vector<vector<char> > T;
bool visited[100][100];

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= M || j >= N) {
        return;
    }
    if (T[i][j] != '@') {
        return;
    }
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    for (int a = 0; a < 8; ++a) {
        for (int b = 0; b < 8; ++b) {
            dfs(i + di[a], j + dj[b]);
        }
    }
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;

        M = m;
        N = n;

        if (m == 0) break;

        // init vector
        vector<vector<char> > t;
        T = t;

        // init visited to true
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                visited[i][j] = false;
            }
        }

        // receive input
        for (int i = 0; i < m; ++i) {
            vector<char> v;
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                v.push_back(c);
            }
            T.push_back(v);
        }

        // count
        int CC = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (T[i][j] == '@' && !visited[i][j]) {
                    ++CC; dfs(i, j);
                }
            }
        }
        cout << CC << endl;
    }
    return 0;
}