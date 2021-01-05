#include <iostream>

using namespace std;

void test_case(int t) {
  int n, x; cin >> n >> x;
  int max = 0;
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    max += ((a / x) + (a % x != 0));
    sum += a;
  }

  int min = ((sum / x) + (sum % x != 0));
  cout << min << " " << max << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        test_case(t);
    }
    return 0;
}
