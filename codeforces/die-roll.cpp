#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int y, w; cin >> y >> w;
    int pos = 6 - max(y, w) + 1;
    int d = gcd(pos, 6);
    printf("%d/%d\n", pos/d, 6/d);
    return 0;
}