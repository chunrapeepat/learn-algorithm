#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int set = 0;

    while (1) {
        int n; cin >> n;
        if (n == 0) break;

        vector<string> result(n, "");
        int cnt = 1;
        int i = 0;
        int j = n-1;

        int t = n;
        while (t--) {
            string name; cin >> name;
            if (cnt % 2) {
                result[i++] = name;
            } else {
                result[j--] = name;
            }
            ++cnt;
        }

        cout << "SET " << ++set << endl;
        for (int k = 0; k < n; ++k) {
            cout << result[k] << endl;
        }
    }
    return 0;
}
