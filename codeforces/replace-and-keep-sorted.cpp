#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q, k; cin >> n >> q >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  vector<int> ANS(n);
  vector<int> CUM(n);
  vector<int> FIRST(n);
  vector<int> LAST(n);
  int l = 0;
  int r = n-1;
  int ans = 0;
  for (int j = l; j <= r; ++j) {
    int prev = (j == l) ? 0 : A[j - 1];
    int next = (j == r) ? k+1 : A[j + 1];
    ans += (next - (prev + 1) - 1);

    CUM[j] = ans;
    ANS[j] = (next - (prev + 1) - 1);
    FIRST[j] = (next - (0 + 1) - 1);
    LAST[j] = ((k+1) - (prev + 1) - 1);
  }

  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << ANS[i] << endl;
  // }
  // cout << endl;

  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << CUM[i] << endl;
  // }
  // cout << endl;

  for (int i = 0; i < q; ++i) {
    int s, e; cin >> s >> e;
    --s, --e;

    int result = CUM[e] - (s - 1 < 0 ? 0 : CUM[s - 1]);
    result = result - ANS[s] + FIRST[s];
    result = result - ANS[e] + LAST[e];

    cout << result << endl;
  }
  return 0;
}