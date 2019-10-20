#include <iostream>

using namespace std;

int main() {
    int testcase = 0;
    while (1) {
        int N; cin >> N;
        if (N == 0) break;

        ++testcase;
        int cnt = 0;

        while (N--) {
            int n; cin >> n;

            if (n > 0 && n <= 99) cnt++;
            else cnt--;
        }

        printf("Case %d: %d\n", testcase, cnt);
    }
    return 0;
}
