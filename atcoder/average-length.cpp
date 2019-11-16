#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(int i, vector<bool> v, vector<pair<int, int>>& p, long double& total, long double& cnt, int n) {
    v[i] = true;
    for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (!v[j]) {
            total += sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
            dfs(j, v, p, total, cnt, n);
        }
    }
}

long double fac(int i) {
    long double result = 1;
    for (int j = 2; j <= i; ++j) {
        result = result * j;
    }
    return result;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p;
    while (n--) {
        int x, y; cin >> x >> y;
        p.emplace_back(x, y);
    }
    long double total = 0;
    long double cnt = 0;
    for (int i = 0; i < p.size(); ++i) {
        dfs(i, vector<bool>(p.size()), p, total, cnt, p.size());
    }
    cout << total / fac(p.size()) << endl;
    return 0;
}
