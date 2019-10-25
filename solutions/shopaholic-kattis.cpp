#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> price(n, 0);

    for (int i = 0; i < n; ++i) {
        int cost; cin >> cost;
        price[i] = cost;
    }

    sort(price.begin(), price.end(), greater<int>());
    long long int discount = 0;
    for (int i = 0; i < n; ++i) {
        if ((i+1) % 3 == 0) {
            discount += price[i];
        }
    }

    cout << discount << endl;
    return 0;
}