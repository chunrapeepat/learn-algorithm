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

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    int q; cin >> q;
    while (q--) {
        vector<ll> A(3); cin >> A[0] >> A[1] >> A[2];
        ll v_min = INT_MAX;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    ll a = A[0]+i;
                    ll b = A[1]+j;
                    ll c = A[2]+k;
                    ll res = abs(a-b)+abs(b-c)+abs(a-c);
                    if (res < v_min) v_min = res;
                }
            }
        }
        cout << v_min << endl;
    }
    return 0;
}

//int main() {
//    int q; cin >> q;
//    while (q--) {
//        vi A(3); cin >> A[0] >> A[1] >> A[2];
//        sort(A.begin(), A.end());
//        if (A[0] < A[1]) {
//            ++A[0];
//        }
//        if (A[2] > A[1]) {
//            --A[2];
//        }
////        cout << abs(A[0]-A[1]) + abs(A[0]-A[2]) + abs(A[2]-A[1]) << endl;
////        cout << A[0] << " " << A[1] << " " << A[2] << endl;
//    }
//    return 0;
//}
