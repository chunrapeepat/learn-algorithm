#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> leftMax(N, 0);
    vector<int> rightMin(N, 0);
    vector<int> arr(N, 0);

    int max = INT_MIN;
    for (int i = 0; i < N; ++i) {
        int num; cin >> num;
        arr[i] = num;

        if (num > max) max = num;
        leftMax[i] = max;
    }

    int min = INT_MAX;
    for (int i = N-1; i >= 0; --i) {
        if (arr[i] < min) min = arr[i];
        rightMin[i] = min;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (rightMin[i] < arr[i] || leftMax[i] > arr[i]) {
            continue;
        }
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}