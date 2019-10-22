#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> check(366, false);
    int cnt = 0;

    while (n--) {
        int s, t; cin >> s >> t;
        for (int i = s; i <= t; ++i) {
            if (!check[i]) {
                check[i] = true;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
