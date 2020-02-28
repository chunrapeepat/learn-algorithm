#include <iostream>

using namespace std;

int main() {
    int ai = 1;
    int aj = 1;
    for (int i = 1; i < 10; ++i) {
        int result = ai + aj;
        cout << result << endl;
        ai = aj;
        aj = result;
    }
    return 0;
}