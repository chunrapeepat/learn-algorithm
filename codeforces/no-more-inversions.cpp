#include <iostream>

using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int last = 2 * k - n;
  for (int i = 1; i < last; ++i) {
    cout << i << " ";
  }
 
  for (int i = 0; i < k - last + 1; ++i) {
    cout << (k - i) << " ";
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