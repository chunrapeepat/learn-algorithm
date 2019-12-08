#include <iostream>
#include <cmath>

using namespace std;

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    string correct, receive; cin >> correct >> receive;
    const int n = correct.size();
    int p, m, q; p = m = q = 0;
    for (int i = 0; i < n; ++i) {
        if (correct[i] == '+') {
            ++p;
        } else {
            ++m;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (receive[i] == '+') {
            --p;
        } else if (receive[i] == '-') {
            --m;
        } else {
            ++q;
        }
    }
    double res = 0;
    if (p >= 0 && m >= 0 && p + m == q) {
        res =  nCr(q, p) * nCr(q - p, m) / pow(2, p + m);
    }
    printf("%.12f\n", res);
    return 0;
}