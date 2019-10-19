#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    int* p = new int[N];

    for (int i = 0; i < N; ++i) {
        int n; cin >> n;
        p[i] = n;
    }

    next_permutation(p, p + N);

    for (int i = 0; i < N; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}
