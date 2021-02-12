#include <iostream>
#include <cmath>

using namespace std;

int ops(int a, int b) {
  int res = 0;
  while (a > 0) {
    ++res;
    a = a / b;
  }
  return res;
}

void solve() {
  int a, b; cin >> a >> b; 
  int res_b = 0;
  if (b == 1) {
    ++res_b; ++b;
  }
  int prev = ops(a, b) + res_b;
  int i = 0;
  while (i < sqrt(a)) {
    ++res_b; ++b; ++i;
    int curr = ops(a, b) + res_b;
    if (curr < prev) {
      prev = curr;
    } 
  }

  cout << prev << endl;
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}