#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  int ans = 0;
  int prev; cin >> prev;
  int cnt = 1;

  for (int i = 0; i < n - 1; ++i) {
    int a; cin >> a;
    if (prev == a) {
      ++cnt;
    } else {
      if (cnt == 1) ans++;
      else ans += 2;

      cnt = 1;
      prev = a;
    }
  }

  if (cnt == 1) ans++;
  else ans += 2;

  cout << ans << endl;
  return 0;
}