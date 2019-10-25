#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, p; cin >> n >> p;
    vector<int> views(n, 0);
    vector<int> dp(n, 0);

    int maximum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int view; cin >> view;
        views[i] = view - p;

        if (i == 0) {
            dp[i] = views[i];
        } else {
            dp[i] = max(dp[i-1] + views[i], views[i]);
        }

        if (dp[i] > maximum) {
            maximum = dp[i];
        }
    }

    cout << maximum << endl;
    return 0;
}