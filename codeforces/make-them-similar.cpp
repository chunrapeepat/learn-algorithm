// Can't Solve :(
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
int t = 1;
const int N = 110;
const int K = 15;
const int V = 5000000;
map<int, int> nxt[V];
typedef long long ll;
int lst[V];

ll A[N];
ll a_low[N];
ll a_high[N];

int get_nxt(int v, int x) {
    if(!nxt[v].count(x))
        nxt[v][x] = t++;
}

void add(vector<int> diff, int x) {
    int v = 0;
    for(auto i : diff)
        v = get_nxt(v, i);
    lst[v] = x;
}

int try_find(vector<int> diff) {
    int v = 0;
    for(auto i : diff) {
        if(!nxt[v].count(i))
            return -1;
        v = nxt[v][i];
    }
    return lst[v];
}

vector<int> get_diff(ll arr[N], int x) {
    vector<int> cnt(n);
    for(int i = 0; i < n; i++)
        cnt[i] = __builtin_popcountll(arr[i] ^ x);
    vector<int> diff(n - 1);
    for(int i = 0; i + 1 < n; i++)
        diff[i] = cnt[i + 1] - cnt[0];
    return diff;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i) {
        a_high[i] = (A[i] >> K);
        a_low[i] = A[i] ^ (a_high[i] << K);
    }
    // bruteforce high bits
    for (int i = 0; i < (i << K); ++i) {
        vector<int> d = get_diff(a_high, i);
        add(d, i);
    }
    for(int i = 0; i < (1 << K); i++) {
        vector<int> d = get_diff(a_low, i);
        for(int j = 0; j + 1 < n; j++)
            d[j] *= -1;
        int x = try_find(d);
        if(x != -1) {
            ll res = (ll(x) << K) ^ i;
            cout << res << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
