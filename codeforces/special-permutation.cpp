#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;

  while (t--) {
    int n; cin >> n;
    int m = (n / 2) + 1;

    for (int i = n; i >= 1; i--) {
      if (n % 2 == 1 && i == m) {
        continue;
      }
      cout << i << ' ';
    }

    if (n % 2 == 1) {
      cout << m << ' ';
    }

    cout << endl;
  }

  return 0;
}