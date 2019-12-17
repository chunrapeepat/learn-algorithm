#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main() {
    int q; cin >> q;
    while (q--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        string res = "";
        int cnt = 0;
        bool ok = false;
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else {
                if (k >= cnt) {
                    k -= cnt;
                    res += '0';
                } else {
                    res += string(cnt - k, '1');
                    res += '0';
                    res += string(k, '1');
                    res += s.substr(i + 1);
                    cout << res << endl;
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            res += string(cnt, '1');
            cout << res << endl;
        }
    }
    return 0;
}
