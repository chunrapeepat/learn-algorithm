#include <iostream>

using namespace std;

int main() {
    string apaxian; cin >> apaxian;
    string result = ""; result += apaxian.at(0);
    char last = apaxian.at(0);

    for (int i = 1; i < apaxian.length(); ++i) {
        if (last == apaxian.at(i)) {
            continue;
        }
        last = apaxian.at(i);
        result += apaxian.at(i);
    }

    cout << result << endl;
    return 0;
}