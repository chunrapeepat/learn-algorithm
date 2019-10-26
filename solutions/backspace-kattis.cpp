#include <iostream>

using namespace std;

int main() {
    string str; cin >> str;
    int skip = 0;

    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == '<') {
            ++skip;
            continue;
        }
        if (skip > 0) {
            --skip;
            str[i] = '<';
            continue;
        }
    }

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != '<')
            cout << str[i];
    }
    cout << endl;

    return 0;
}