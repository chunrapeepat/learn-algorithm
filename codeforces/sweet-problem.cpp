#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> A;
        int r, g, b; cin >> r >> g >> b;
        A.push_back(r);
        A.push_back(g);
        A.push_back(b);
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        int minV = A[2];
        int diff = A[0] - A[1];
        A[0] -= min(diff, A[2]);
        A[2] = max(0, A[2] - diff);

        cout << min(A[0]-A[2]/2-(A[2]%2), A[1]-A[2]/2) + minV << endl;
    }
    return 0;
}