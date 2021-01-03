#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;

  while (t--) {
    int n; cin >> n;
    vector<int> A(n, 0);
    vector<int> U(n+1, 0);

    for (int i = 0; i < n; ++i) {
      int a; cin >> A[i];
      ++U[A[i]];
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
      if (U[i] == 1) {
        ans = i;
        break;
      }
    }

    if (ans == -1) {
      cout << -1 << endl;
    } else {
      for (int i = 0; i < n; ++i) {
        if (A[i] == ans) {
          cout << i + 1 << endl;
          break;
        }
      }
    }
  }

  return 0;
}