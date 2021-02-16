#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> C(3, 0);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    ++C[a % 3];
  }
  int ans = 0;
  int t = n / 3;
  while (C[0] != C[1] || C[1] != C[2] || C[0] != C[2] || C[0] != t) {
    if (C[0] < t) {
      if (C[2] > t) {
        --C[2];
        ++C[0];
        ++ans;
      } else if (C[1] > t) {
        --C[1];
        ++C[0];
        ans += 2;
      }
    }

    if (C[1] < t) {
      if (C[0] > t) {
        --C[0];
        ++C[1];
        ++ans;
      } else if (C[2] > t) {
        --C[2];
        ++C[1];
        ans += 2;
      }
    }

    if (C[2] < t) {
      if (C[1] > t) {
        --C[1];
        ++C[2];
        ++ans;
      } else if (C[0] > t) {
        --C[0];
        ++C[2];
        ans += 2;
      }
    }
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