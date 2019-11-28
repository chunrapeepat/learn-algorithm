#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> platforms(m);
    vector<int> river(n+1);
    int lastPlatform = 0;
    for (int i = 0; i < m; ++i) {
        int platform; cin >> platform;
        platforms[i] = platform;
        lastPlatform += platform;
    }
    int pos = 0;
    int i = 0;
    bool canJump = true;
    while (pos <= n) {
        int jump = min(d, n - lastPlatform + 1);

        if (i >= m && pos + d <= n) {
            canJump = false;
            break;
        }

        if (i < m) {
            for (int j = pos + max(1, jump); j < pos + max(1, jump) + platforms[i]; ++j) {
                river[j] = i + 1;
            }
        }

        lastPlatform += jump - 1;
        pos = pos + max(1, jump) + ((i < m) ? platforms[i++] - 1 : 0);
    }
    if (canJump) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << river[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
