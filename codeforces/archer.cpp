#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d; cin >> a >> b >> c >> d;
    double S = a/b;
    double Z = c/d;
    double res = 0;
    for (int i = 0; i < 1000000; ++i) {
        res += S*pow(1-S, i)*pow(1-Z, i);
    }
    printf("%.12f\n", res);
    return 0;
}