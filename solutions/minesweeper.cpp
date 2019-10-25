#include <iostream>

using namespace std;

int main() {
    int index = 1;

    while (true) {
        int height, width;
        cin >> height >> width;

        if (height == 0 || width == 0) break;

        int** F = new int*[height];
        for (int i = 0; i < height; ++i) {
            F[i] = new int[width];
            for (int j = 0; j < width; ++j) {
                F[i][j] = 0;
            }
        }

        for (int h = 0; h < height; ++h) {
            for (int w = 0; w < width; ++w) {
                char c;
                cin >> c;

                if (c == '*') {
                    F[h][w] = -1;

                    // Down and Top
                    if (h + 1 >= 0 && h + 1 < height && F[h + 1][w] != -1) ++F[h + 1][w];
                    if (h - 1 >= 0 && h - 1 < height && F[h - 1][w] != -1) ++F[h - 1][w];

                    // Right and Left
                    if (w + 1 >= 0 && w + 1 < width && F[h][w + 1] != -1) ++F[h][w + 1];
                    if (w - 1 >= 0 && w - 1 < width && F[h][w - 1] != -1) ++F[h][w - 1];

                    // Top Left and Top Right
                    if (h - 1 >= 0 && h - 1 < height && w - 1 >= 0 && w - 1 < width && F[h - 1][w - 1] != -1) ++F[h - 1][w - 1];
                    if (h - 1 >= 0 && h - 1 < height && w + 1 >= 0 && w + 1 < width && F[h - 1][w + 1] != -1) ++F[h - 1][w + 1];
                    if (h + 1 >= 0 && h + 1 < height && w - 1 >= 0 && w - 1 < width && F[h + 1][w - 1] != -1) ++F[h + 1][w - 1];
                    if (h + 1 >= 0 && h + 1 < height && w + 1 >= 0 && w + 1 < width && F[h + 1][w + 1] != -1) ++F[h + 1][w + 1];
                }
            }
        }

        // print the result
        if (index > 1) cout << endl;
        cout << "Field #" << index++ << ":" << endl;
        for (int h = 0; h < height; ++h) {
            for (int w = 0; w < width; ++w) {
                int d = F[h][w];

                if (d == -1) cout << "*";
                else cout << d;
            }
            cout << endl;
        }
    }
    return 0;
}
