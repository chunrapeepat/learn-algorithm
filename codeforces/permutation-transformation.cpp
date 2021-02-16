#include <iostream>
#include <vector>
#include <map>
#include <cmath>

typedef long long int lli;

using namespace std;

void traverse(int l, int r, vector<int>& A, vector<int>& ans, int d) {
  if (l > r) {
    return;
  }
  // cout << l << " " << r << endl;

  // find max
  int max_value = -1;
  int max_index = -1;
  for (int i = l; i <= r; ++i) {
    if (A[i] > max_value) {
      max_value = A[i];
      max_index = i;
    }
  }

  // cout << "MAX index: " << max_index << endl;
  ans[max_index] = d;
  traverse(l, max_index - 1, A, ans, d+1);
  traverse(max_index + 1, r, A, ans, d+1);
}

void solve() {
  int n; cin >> n;
  vector<int> ans(n);
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];

  traverse(0, n-1, A, ans, 0);

  // print answer
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}