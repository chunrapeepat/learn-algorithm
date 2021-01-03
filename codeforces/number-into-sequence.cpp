#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long int lli;
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define R first
#define C second
#define X first
#define Y second

void solve() {
  lli n; cin >> n;
  lli N = n;
  vector<lli> p;
  for (lli i = 2; i <= sqrt(n); ++i) {
    while (N % i == 0) {
      N = N / i;
      p.push_back(i);
    }
  }
  if (N != 1) p.push_back(N);
  map<lli, int> cnt;
  for (int i = 0; i < p.size(); ++i) {
    if (cnt.find(p[i]) == cnt.end()) {
      cnt.insert(mp(p[i], 1));
    } else {
      ++cnt.find(p[i])->S;
    }
  }
  int maxCount = -1;
  lli maxCountValue = -1;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    if (it->S > maxCount) {
      maxCountValue = it->F;
      maxCount = it->S;
    }
  }
  vector<lli> ans;
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == maxCountValue) {
      ans.push_back(p[i]);
      p[i] = -1;
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == -1) continue;
    if (p[i] % ans.back() == 0) { 
      ans.push_back(p[i]); 
    } else { 
      ans[ans.size()-1] = ans.back() * p[i]; 
    } 
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}