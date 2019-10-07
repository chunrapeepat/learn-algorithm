#include <iostream>
#include <cmath>

using namespace std;

// 1. assume that start point are higher than dest point
    // let's check it first and then sort before goto function
// 2. find the way to get the same level with dest point
    // formula is 2n - (1 - (curr.r + curr.c) % 2)
    // we calculate the range (start.r + n, start.c +- (n - 1))
// 3. calculate the distance between current x and y from range

int dist(int Sr, int Sc, int Dr, int Dc) {
    if (Sr == Dr) return abs(Sc - Dc);

    int distance = 2 * (Dr - Sr) - (1 - (Sr + Sc) % 2);

    int start = Sc - (Dr - Sr - (1 - (Sr + Sc) % 2));
    int end = Sc + (Dr - Sr - (1 - (Sr + Sc) % 2));

    if (Dc >= start && Dc <= end) {
        distance += 1 - (Dr + Dc) % 2;
    } else {
        distance += min(abs(start - Dc), abs(end - Dc));
    }

    return distance;
}

int main() {
    while (1) {
        int Sr, Sc, Dr, Dc;
        cin >> Sr >> Sc >> Dr >> Dc;

        if (Sr == 0 && Sc == 0 && Dr == 0 && Dc == 0) {
            break;
        }

        if (Sr < Dr) {
            cout << dist(Sr, Sc, Dr, Dc) << endl;
        } else {
            cout << dist(Dr, Dc, Sr, Sc) << endl;
        }
    }
    return 0;
}