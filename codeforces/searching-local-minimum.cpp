#include <iostream>
#include <vector>

using namespace std;

int n;
int ask(int i) {
  if (i != 0 && i != n + 1) {
    cout << "? " << i << endl;
    cout.flush();
    int a; cin >> a;
    return a;
  }
  return 99999;
}

int main() {
  cin >> n;
  vector<int> A(n+2);
  int l = 0;
  int r = n+1;
  int m = (l + r) / 2;
  A[l] = 99999;
  A[r] = 99999;
  A[m] = ask(m);

  while (!(l == m - 1 && r == m + 1)) {
    // left
    int i = (l + m) / 2;
    A[i] = ask(i);
    if (A[i] > A[m]) {
      l = i;
    } else if (A[i] < A[m]) {
      r = m;
      m = i;
    }

    // cout << "Debug: L = " << l << " M = " << m << " R = " << r << endl;

    // right
    int j = (m + r) / 2;
    A[j] = ask(j);
    if (A[j] > A[m]) {
      r = j;
    } else if (A[j] < A[m]) {
      l = m;
      m = j;
    }

    // cout << "Debug: L = " << l << " M = " << m << " R = " << r << endl;
  }

  cout << "! " << m << endl;
  return 0;
}