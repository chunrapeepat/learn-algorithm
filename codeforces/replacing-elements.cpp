#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
  int n, d; cin >> n >> d;
  bool pass = true;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    if (A[i] > d) {
      pass = false;
    }
  }
  sort(A.begin(), A.end());
  if (pass || A[0] + A[1] <= d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}