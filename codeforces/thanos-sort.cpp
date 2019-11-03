#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int thanos_sort(vector<int> arr, int l, int r) {
    if (l == r) {
        return 1;
    }
    bool is_sorted = true;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i-1] > arr[i]) {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted) {
        return r - l + 1;
    }
//    cout << l << " " << l + (r-l)/2 << endl;
//    cout << l + (r-l)/2 + 1 << " " << r << endl;
    return max(thanos_sort(arr, l, l + (r-l)/2), thanos_sort(arr, l + (r-l)/2 + 1, r));
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    while (n--) {
        int a; cin >> a;
        arr.push_back(a);
    }
    cout << thanos_sort(arr, 0, arr.size() - 1);
    return 0;
}