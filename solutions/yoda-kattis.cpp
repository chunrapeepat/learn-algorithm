#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string s_a, s_b; cin >> s_a >> s_b;
    bool is_a, is_b; is_a = is_b = true;

    int n = s_a.length();
    int m = s_b.length();
    int a, b, i; a = b = 0; i = 1;
    int ia, ib; ia = ib = 0;

    while (i <= n && i <= m) {
        if (s_a[n-i] == s_b[m-i]) {
            a += (s_a[n-i]-'0') * pow(10, ia++);
            b += (s_a[n-i]-'0') * pow(10, ib++);
            is_a = is_b = false;
        } else if (s_a[n-i] > s_b[m-i]) {
            a += (s_a[n-i]-'0') * pow(10, ia++);
            is_a = false;
        } else {
            b += (s_b[m-i]-'0') * pow(10, ib++);
            is_b = false;
        }
        i++;
    }

    int cn = n;
    int cm = m;
    if (n < m) {
        while (cm != cn) {
            b += (s_b[m-i]-'0') * pow(10, ib++);
            cm--; i++;
            is_b = false;
        }
    } else if (n > m) {
        while (cm != cn) {
            a += (s_a[n-i]-'0') * pow(10, ia++);
            cn--; i++;
            is_a = false;
        }
    }

    if (is_a) {
        cout << "YODA" << endl;
    } else {
        cout << a << endl;
    }
    if (is_b) {
        cout << "YODA" << endl;
    } else {
        cout << b << endl;
    }

    return 0;
}