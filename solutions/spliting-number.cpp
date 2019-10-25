#include <iostream>

using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;

        if (n == 0) break;

        int i = 0;
        int s = 1;
        int a = 0;
        int b = 0;

        while ((n >> i) != 0) {
            if ((n >> i) & 1) {
                a = a | (((n >> i) & 1) << i) * s;
                b = b | (((n >> i) & 1) << i) * (1 - s);
                s = 1 - s;
            }
            i++;
        }

        cout << a << " " << b << endl;
    }
    return 0;
}
