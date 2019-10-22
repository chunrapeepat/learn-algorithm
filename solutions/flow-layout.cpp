#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    while (1) {
        int maxWidth; cin >> maxWidth;
        if (maxWidth == 0) break;

        int totalW = 0;
        int totalH = 0;
        int width = 0;
        int height = 0;

        while (1) {
            int w, h; cin >> w >> h;
            if (w == -1 && h == -1) break;

            if (w + width <= maxWidth) {
                width += w;
                height = max(height, h);
            } else {
                totalH += height;
                totalW = max(totalW, width);
                width = w;
                height = h;
            }
        }

        cout << max(totalW, width) << " x " << totalH + height << endl;
    }
    return 0;
}
