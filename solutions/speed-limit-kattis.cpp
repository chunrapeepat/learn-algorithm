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
    while (1) {
        int n; cin >> n;
        if (n == -1) break;

        int prv = 0;
        int total = 0;
        while (n--) {
            int s, t; cin >> s >> t;
            total += s * (t - prv);
            prv = t;
        }

        cout << total << " miles" << endl;
    }
    return 0;
}
