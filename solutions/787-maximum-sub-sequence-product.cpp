#include <iostream>
#include <vector>

using namespace std;

// I got Time Limit Exceed on this problem, Don't know when to exit program
int main() {
    while (1) {
        vector<int> v;
        int count = 0;

        while (1) {
            int num;
            cin >> num;

            if (num == -999999) break;

            v.push_back(num); ++count;
        }

        long long int max = -999999;
        long long int dp[count][count];

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                if (i + j >= count) continue;

                if (j == j + i) {
                    dp[j][j] = v[j];
                } else {
                    dp[j][j + i] = dp[j][j + i - 1] * dp[j + i][j + i];
                }

                if (dp[j][j + i] > max) {
                    max = dp[j][j + i];
                }
            }
        }

        cout << max << endl;
    }
    return 0;
}