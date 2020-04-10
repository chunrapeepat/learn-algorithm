#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

// type
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
// shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define R first
#define C second
#define X first
#define Y second
#define INIT_RANDOM_SEED srand(time(0));
// print
template<typename T, typename... Types>
void print_with_space(T t, Types... ts) {
    cout << t << " ";
}
template<typename T, typename... Args>
void DEBUG(T t, Args... args) {
    cout << "DEBUG: " << t << " "; print_with_space(args...); cout << endl;
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

/* CODE START BELOW THIS POINT!!! */

void solve(int t) {
    INIT_RANDOM_SEED;
    int r, c; cin >> r >> c;

    // shuffle starting cell
    vector<pair<int, int>> grid;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            grid.pb(mp(i, j));
        }
    }
    random_shuffle(grid.begin(), grid.end());

    // start moving
    for (int s = 0; s < r*c; ++s) {
        vvb visited = vvb(r, vb(c, false));
        stack<pair<int, int>> stk; stk.push(grid[s]);
        vector<vector<pii>> parentMap = vector<vector<pii>>(r, vector<pii>(c, mp(-1, -1)));
        vvi depthMap = vvi(r, vi(c, 1));

        while (!stk.empty()) {
            pair<int, int> cell = stk.top(); stk.pop();

            if (!visited[cell.R][cell.C]) {
                visited[cell.R][cell.C] = true;
            }

            for (int i = 0; i < r*c; ++i) {
                int counter = 0;
                if (!(grid[i].R == cell.R
                || grid[i].C == cell.C
                || grid[i].R - grid[i].C == cell.R - cell.C
                || grid[i].R + grid[i].C == cell.R + cell.C) && !visited[grid[i].R][grid[i].C]) {
                    stk.push(grid[i]);
                    parentMap[grid[i].R][grid[i].C] = mp(cell.R, cell.C);
                    depthMap[grid[i].R][grid[i].C] = depthMap[cell.R][cell.C] + 1;

                    ++counter;
                }

                if (counter == 0 && depthMap[cell.R][cell.C] == r*c) {
                    printf("Case #%d: POSSIBLE\n", t);
                    list<pii> moves;

                    pair<int, int> curr = cell;
                    while (parentMap[curr.R][curr.C].R != -1) {
                        moves.pf(curr);
                        curr = parentMap[curr.R][curr.C];
                    }
                    moves.pf(curr);

                    for (const auto &C : moves) {
                        printf("%d %d\n", C.R + 1, C.C + 1);
                    }

                    return;
                }
            }
        }
    }

    printf("Case #%d: IMPOSSIBLE\n", t);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}
