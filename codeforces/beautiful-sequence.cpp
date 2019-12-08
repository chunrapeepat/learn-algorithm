#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair

int main() {
    vi nums(4); cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    int total = nums[0] + nums[1] + nums[2] + nums[3];
    for (int st = 0; st < 4; ++st) if (nums[st]) {
        vi res;
        vi ths = nums;
        int pos = st;

        --ths[pos];
        res.pb(pos);

        for (int i = 0; i < total - 1; ++i) {
            if (pos - 1 >= 0 && ths[pos - 1]) {
                res.pb(pos - 1);
                ths[pos - 1]--;
                pos--;
            } else if (pos + 1 < 4 && ths[pos + 1]) {
                res.pb(pos + 1);
                ths[pos + 1]--;
                pos++;
            } else {
                break;
            }
        }
        if (res.size() == total) {
            cout << "YES" << endl;
            for (int i = 0; i < total; ++i) {
                cout << res[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
