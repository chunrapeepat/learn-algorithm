#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// type
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
// shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define R first
#define C second
#define X first
#define Y second
#define INIT_RANDOM_SEED srand(time(0));

void solve() {
  int n; cin >> n;
  int N = n;
  // Step 1; Reduce arr -> no A(i) == A(i+1)
  vi A;
  int prev = -1;
  while (n--) {
    int a; cin >> a;
    if (a != prev) {
      A.pb(a);
      prev = a;
    }
  }
  // Step 2; Store range in arr
  vector<vector<pii> > cnt(N+1, vector<pii>());
  for (int i = 0; i < A.size(); ++i) {
    int num = A[i];

    if (cnt[num].empty()) {
      cnt[num].push_back(mp(i, i));
    } else {
      cnt[num].push_back(mp(cnt[num].back().F, i));
    }
  }
  // Step 3; count and find min value
  int ans = A.size();
  for (int i = 1; i <= N; ++i) {
    if (cnt[i].empty()) {
      continue;
    }
    int count = 0;
    count += cnt[i].front().F > 0 ? 1 : 0; // pre
    count += cnt[i].back().S < A.size() - 1 ? 1 : 0; // post
    for (int j = 0; j < cnt[i].size(); ++j) {
      count = count + (cnt[i][j].S - cnt[i][j].F > 0 ? 1 : 0);
    }
    if (count < ans) ans = count;
  }
  cout << ans << endl;
}

int main() {
  FAST_IO;
  int t; cin >> t;

  while(t--)
    solve();

  return 0;
}