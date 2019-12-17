#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi P(n);
        int l, r;
        for (int i = 0; i < n; ++i) {
            cin >> P[i];
            if (P[i] == 1) {
                l = r = i;
            }
        }
        vi res(n+1);
        for (int i = 1; i <= n; ++i) {
            if (r + 1 < n) {
                while (P[r+1] <= i && r+1 < n) {
                    r++;
                }
            }
            if (l - 1 >= 0) {
                while (P[l-1] <= i && l-1 >= 0) {
                    l--;
                }
            }
            if (r - l + 1 == i) {
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}
