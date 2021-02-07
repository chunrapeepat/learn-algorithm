#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm> 

typedef long long ll;
using namespace std;

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    return a.second < b.second; 
} 

void solve() {
  ll A, B, n; cin >> A >> B >> n;
  vector<pair<ll, ll> > M;
  vector<ll> mA(n);
  vector<ll> mB(n);
  for (int i = 0; i < n; ++i) {
    cin >> mA[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> mB[i];
  }
  for (int i = 0; i < n; ++i) {
    ll d = ((mB[i] / A) + (mB[i] % A != 0)) * mA[i];
    M.push_back(make_pair(i, mA[i]));
  }
  // sort by damage
  sort(M.begin(), M.end(), compare);

  for (int i = 0; i < n; ++i) {
    pair<ll, ll> MP = make_pair(mA[M[i].first], mB[M[i].first]);
    ll times = (MP.second / A) + (MP.second % A != 0);
    if ((times * MP.first) <= B) {
      B = B - (times * MP.first);
    } else {
      if (i == n - 1) {
        ll t = (B / MP.first) + (B % MP.first != 0);
        if ((t * A) >= MP.second) {
          break;
        }
      }
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  int t; cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}