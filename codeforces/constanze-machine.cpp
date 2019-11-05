#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

int main() {
    string msg; cin >> msg;
    const int n = msg.length();
    vector<int> dp = vector<int>(n+2); dp[1] = 1; dp[2] = 2;
    ll result = 1;

    for (int j = 3; j <= n; ++j) {
        dp[j] = (dp[j-1] + dp[j-2]) % mod;
    }

    int count = 0;
    char prev = 'x';

    for (int i = 0; i < n; ++i) {
        if (msg[i] == 'w' || msg[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
        if (msg[i] == 'u') {
            if (prev == 'u') {
                ++count;
            } else {
                prev = 'u';
                count = 1;
            }
        } else if (msg[i] == 'n') {
            if (prev == 'n') {
                ++count;
            } else {
                prev = 'n';
                count = 1;
            }
        } else {
            prev = 'x';
            count = 0;
        }

        if (i+1 >= n || msg[i+1] != prev) {
            if (count != 0) {
                result = (result * dp[count]) % mod;
            }
        }
    }

    cout << result << endl;
    return 0;
}