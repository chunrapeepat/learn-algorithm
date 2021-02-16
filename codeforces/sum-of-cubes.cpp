#include <iostream>
#include <vector>
#include <map>
#include <cmath>

typedef long long int lli;

using namespace std;

lli d(lli a, lli b) {
  return (a / b) + (a % b != 0);
}

int main() {
  int t; cin >> t;
  // pre-compute
  vector<lli> A;
  map<lli, bool> M;
  lli i = 1;
  lli out = 1;
  while (out <= 1000000000000) {
    out = i * i * i;
    A.push_back(out);
    M.insert(make_pair(out, true));
    ++i;
  }

  while (t--) {
    lli x; cin >> x;
    for (int i = 0; i < A.size(); ++i) {
      // cout << A[i] << endl;
      if (A[i] > d(x, 2)) {
        cout << "NO" << endl;
        break;
      }
      lli y = x - A[i];
      if (M.find(y) != M.end()) {
        cout << "YES" << endl;
        break;
      }
    }
  }
}
