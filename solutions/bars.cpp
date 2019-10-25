#include <iostream>

using namespace std;

void sort(int n, int* ptr)
{
    int i, j, t;

    // Sort the numbers using pointers
    for (i = 0; i < n; i++) {

        for (j = i + 1; j < n; j++) {

            if (*(ptr + j) < *(ptr + i)) {

                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }

    // print the numbers
//    for (i = 0; i < n; i++)
//        printf("%d ", *(ptr + i));
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int l, n;
        cin >> l >> n;

        // Init Table
        bool** f = new bool*[n];
        int* nums = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = new bool[l+1];
            for (int j = 0; j <= l; ++j) {
                f[i][j] = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            int number;
            cin >> number;
            nums[i] = number;
        }

        sort(n, nums);

        // Find Sum
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= l; ++j) {
                if (nums[i] > l) continue;

                if (j == 0) {
                    f[i][j] = true;
                    continue;
                }

                if (j == nums[i]) {
                    f[i][j] = true;
                    continue;
                }

                if (i - 1 >= 0 && f[i - 1][j]) {
                    f[i][j] = true;
                    continue;
                }

                if (i - 1 >= 0 && f[i - 1][j - nums[i]]) {
                    f[i][j] = true;
                    continue;
                }
            }
        }

        bool is_found = false;
        for (int k = 0; k < n; ++k) {
            if (f[k][l]) {
                is_found = true;
                break;
            }
        }

        if (is_found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
