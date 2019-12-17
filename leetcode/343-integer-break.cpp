#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> res(n+1);
    res[1] = 1;
    for (ll i = 1; i <= n; ++i) {
        ll v_max = -1;
        for (ll a = 1; a <= i - 1; ++a) {
            v_max = max(v_max, a * res[i - a]);
            v_max = max(v_max, a * (i - a));
        }
        res[i] = v_max;
    }
    cout << res[n] << endl;
}