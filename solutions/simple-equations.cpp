#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int testcases;
  cin >> testcases;

  for (int t = 0; t < testcases; ++t) {
    int A, B, C;
    int R = 0;
    bool pass = false;

    cin >> A >> B >> C;

    R = sqrt(C);

    for (int x = -R; x <= R && !pass; ++x) {
      for (int y = -R; y <= R && !pass; ++y) {
        for (int z = -R; z <= R && !pass; ++z) {
          int resultA = x + y + z;
          int resultB = x * y * z;
          int resultC = pow(x, 2) + pow(y, 2) + pow(z, 2);

          if (resultA == A && resultB == B && resultC == C && x != y && y != z && x != z) {
            cout << x << " " << y << " " << z << endl;
            pass = true;
            break;
          }
        }
      }
    }

    if (!pass) cout << "No solution." << endl;
  }

  return 0;
}
