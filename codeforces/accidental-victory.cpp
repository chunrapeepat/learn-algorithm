#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

typedef long long int lli;

using namespace std;

void solve() {
  int n; cin >> n;
  vector<lli> A(n);
  vector<lli> B(n);
  map<lli, lli> M;

  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(A.begin(), A.end());

  lli c = 0;
  for (int i = 0; i < n; ++i) {
    c += A[i];

    if (M.find(A[i]) == M.end()) {
      M.insert(make_pair(A[i], c));
    } else {
      M.find(A[i])->second = c;
    }
  }

  for (int i = 0; i < n; ++i) {
    lli curr = M.find(A[i])->second;
    for (int j = i+1; j < n; ++j) {
      if (A[j] > A[i]) {
        if (curr >= A[j]) {
          curr += A[j];
        } else {
          break;
        }
      }
    }
    M.find(A[i])->second = curr;
  }

  vector<lli> ans;
  for (int i = 0; i < n; ++i) {
    // cout << M.find(A[i])->second << " " << A[n-1] << endl;
    if (M.find(B[i])->second >= A[n-1]) {
      ans.push_back(i+1);
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
  while (t--) {
    solve();
  }
}