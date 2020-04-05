#include <iostream>
#include <vector>

using namespace std;

void findCombinationsUtil(int arr[], int index, int num, int reducedNum, int size) {
    if (reducedNum < 0 || index > size)
        return;

    if ((size - index) > reducedNum) return;

    if (reducedNum == 0) {
        for (int i = 0; i < index; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    int prev = (index == 0)? 1 : arr[index-1];

    for (int k = prev; k <= size ; k++) {
        arr[index] = k;
        findCombinationsUtil(arr, index + 1, num,reducedNum - k, size);
    }
}

void findCombinations(int n, int size) {
    int arr[n];
    findCombinationsUtil(arr, 0, n, n, size);
}

void solve(int t) {
    int n, k; cin >> n >> k;

    findCombinations(k, n);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}