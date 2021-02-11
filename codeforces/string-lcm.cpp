#include <iostream>
#include <cmath>

using namespace std;

int GCD(int a, int b) {
   if (b == 0)
   return a;
   return GCD(b, a % b);
}

void LCM(string s, string t) {
  if (t.size() > s.size()) {
    LCM(t, s);
    return;
  }

  string _base = "";
  int m = min(t.size(), s.size());
  for (int i = 0; i < m; ++i) {
    if (s[i] == t[i]) {
      _base += s[i];
    } else {
      cout << -1 << endl;
      return;
    }
  }
  int times = (s.size() * t.size()) / GCD(s.size(), t.size());
  times = times / _base.size();
  string base = "";
  for (int i = 0; i < times; ++i)
    base += _base;
  
  int sp = 0;
  int tp = 0;
  for (int i = 0; i < base.size(); ++i) {
    if (s[sp] == base[i] && t[tp] == base[i]) {
      sp = (sp + 1) % s.size();
      tp = (tp + 1) % t.size();
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << base << endl;
}

int main() {
  int t; cin >> t; 
  while (t--) {
    string s, t; cin >> s >> t;
    LCM(s, t);
  }
  return 0;
}