#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int wallet, types;
    cin >> wallet >> types;

    bool table[types][wallet + 1];
    for (size_t i = 0; i < types; ++i) {
      for (size_t j = 0; j <= wallet; ++j) {
        table[i][j] = false;
      }
    }

    for (int i = 0; i < types; ++i) {
      int amount;
      cin >> amount;

      for (int j = 0; j < amount; ++j) {
        int price;
        cin >> price;

        if (i == 0) {
          if (wallet - price >= 0) table[0][wallet - price] = true;
          continue;
        }

        for (int z = 0; z <= wallet; ++z) {
          if (table[i-1][z]) {
            if (z - price >= 0) table[i][z - price] = true;
          }
        }
      }
    }

    bool has_result = false;
    for (int i = 0; i < wallet; ++i) {
      if (table[types - 1][i]) {
        cout << wallet - i << endl;
        has_result = true;
        break;
      }
    }

    if (!has_result) {
      cout << "no solution" << endl;
    }
  }

  return 0;
}
