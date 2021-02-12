#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int x, y; cin >> x >> y;
  int cnt = 0;
  for (int xi = 3; xi <= x; ++xi) {
    map<int, bool> div;
    vector<int> div_v;
    for (int i=1; i<=sqrt(xi); i++) { 
        if (xi%i == 0) { 
            if (xi/i == i) {
              if ((i - 1) > y) break;
              div.insert(make_pair(i, true));
              div_v.push_back(i);
            } else {
              if ((i - 1) > y) {
                // cout << i << " " << y << endl;
                break;
              }
              if ((xi/i - 1) > y) {
                // cout << (xi/i) << " " << y << endl;
                break;
              }
              div.insert(make_pair(i, true));
              div.insert(make_pair(xi/i, true));
              div_v.push_back(i);
              div_v.push_back(xi/i);
            }
        } 
    } 
    for (int i = 0; i < div_v.size(); ++i) {
      int d = div_v[i];
      if ((d != 1) && (xi % (d - 1) != 0) && ((xi/(d-1)) == xi/d)) {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}