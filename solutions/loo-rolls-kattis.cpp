#include <iostream>

using namespace std;

int main() {
    long long int n, l; cin >> n >> l;
    int cnt = 1;

    while (n % l != 0) {
        l = l - (n % l);
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}