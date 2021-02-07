#include <iostream>

using namespace std;

void solve() {
  string s; cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (i % 2 == 0) {
      // Alice
      if (s[i] != 'a') {
        cout << 'a';
      } else {
        cout << 'b';
      }
    } else {
      // Bob
      if (s[i] != 'z') {
        cout << 'z';
      } else {
        cout << 'y';
      }
    }
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