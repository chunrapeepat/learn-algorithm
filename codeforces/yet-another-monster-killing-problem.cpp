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

const int N = int(2e5) + 99;

int t;
int n;
int a[N];
int m;
int p[N], s[N];
int bst[N];

int main() {
    scanf("%d", &t);
    for(int tc = 0; tc < t; ++tc){
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i) bst[i] = 0;
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf("%d %d", p + i, s + i);
            bst[s[i]] = max(bst[s[i]], p[i]);
        }
        for(int i = n - 1; i >= 0; --i)
            bst[i] = max(bst[i], bst[i + 1]);


        int pos = 0;
        int res = 0;
        bool ok = true;
        while(pos < n){
            ++res;
            int npos = pos;
            int mx = 0;
            while(true){
                mx = max(mx, a[npos]);
                if(mx > bst[npos - pos + 1]) break;
                ++npos;
            }

            if(pos == npos){
                ok = false;
                break;
            }
            pos = npos;
        }

        if(!ok) res = -1;
        printf("%d\n", res);
    }

    return 0;
}