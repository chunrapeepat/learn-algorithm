#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        vector<int> planks(n);
        for (int i = 0; i < n; ++i) {
            int h; cin >> h;
            planks[i] = h;
        }
        sort(planks.begin(), planks.end(), greater<int>());
        int max = -1;
        int h = INT_MAX;
        for (int j = 0; j < n; ++j) {
            h = min(h, planks[j]);
            if (min(j+1, h) > max) {
                max = min(j+1, h);
            }
        }
        cout << max << endl;
    }
    return 0;
}