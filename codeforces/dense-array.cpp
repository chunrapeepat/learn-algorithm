#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int d(int a, int b) {
  return (a / b) + (a % b != 0);
}

int cnt_dense(int a, int b) {
  if (d(b, a) <= 2) {
    return 0;
  }
  int cnt = 0;
  int curr = a;
  while (d(b, curr) > 2) {
    ++cnt;
    curr *= 2;
  }
  return cnt;
}

void solve() {
  int n; cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a = min(A[i], A[i+1]);
    int b = max(A[i], A[i+1]);
    ans += cnt_dense(a, b);
    // cout << "A: " << a << " B:" << b << endl;
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}