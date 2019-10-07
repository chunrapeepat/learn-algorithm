#include <iostream>
#define SIZE 10001
using namespace std;
typedef pair<int, int> Pair;

Pair get_on_x(int x, int y) {
    int fi, la;
    fi = x - y;
    la = x + y;
    if (fi < 0) fi = 0;
    if (la > 10000) la = 10000;
    return Pair(fi, la);
}

void fill(int* arr, Pair p) {
    for (int i = p.first; i < p.second+1; i++)
        arr[i]++;
}

int find_max(int* arr) {
    int max = 0;
    for (int i = 0; i < SIZE; i++)
       if (max < arr[i])
        max = arr[i];
    return max;
}

int main() {
    std::ios::sync_with_stdio(false);
    int N;

    while ((cin >> N) && (N != 0)) 
    {
        int* ans = new int[SIZE]();
        int max = 0;
        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            Pair range = get_on_x(x, y);
            fill(ans, range);
        }
        cout << find_max(ans) << endl;
        
    }

    return 0;
}